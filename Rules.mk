#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Rules.mk                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/13 19:41:31 by mgautier          #+#    #+#             *#
#*   Updated: 2017/01/07 15:14:13 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

#
# set DIR to current directory, using SUBDIR, passed by the upper level Rules.mk
# If that one is the top level, DIR is set to himself
#
STACK_POINTER := $(STACK_POINTER).x
DIR_$(STACK_POINTER) := $(DIR)
DIR := $(DIR)$(SUBDIR)

# Local sources files and target

include $(DIR)Srcs.mk

# Give the full path to the locals directories (relative to top level Rules.mk)
# add a slash only if necessary (alway adding a slash cause trouble in the top level
# directory if subdirs are not defined (aka files are in DIR)

$(foreach TYPE,SRC OBJ DEP INC,$(eval $(call ADD_SLASH,$(TYPE))))

# Add the obj and dependency dir to the list of generated dir, which is also a clean
# variables (for the remove directories rule)
# only if they are different from the sub-project directory
# That one obviously does not need to be created, and remove it would be trouble

ifdef OBJ_DIR
GENERATED_SUBDIRS += $(OBJ_LOCAL_DIR)
endif
ifdef DEP_DIR
GENERATED_SUBDIRS += $(DEP_LOCAL_DIR)
endif

# Standard expansion of the SRC into the local OBJ and DEP
# + add them to clean-up variables
# + check if the target of this directory is indicated

OBJ_$(DIR) := $(OBJ)
DEP_$(DIR) := $(DEP)

ifdef TARGET
TARGET_$(DIR) := $(DIR)$(TARGET)
else
$(eval $(TARGET_ERROR))
endif

# If the target is a static library, use the approriate recipe.
# Otherwise, use the linker for an executable

ifeq ($(suffix $(TARGET)),.a)
$(TARGET_$(DIR)): RECIPE = $(LINK_STATIC_LIB)
else
$(TARGET_$(DIR)): RECIPE = $(LINK_EXE)
endif


# Local rules

$(TARGET_$(DIR)): $(OBJ_$(DIR)) $(ELSE) $(LIBRARY)
	$(QUIET) $(RECIPE)

$(info $(STATIC_OBJ_RULE))
$(eval $(STATIC_OBJ_RULE))

# If the target is different from the one make is invoked in,
# add it to the search path for headers.
# If the target requiert a library, add its directory too.

$(TARGET_$(DIR)): CPPFLAGS := $(CPPFLAGS) -iquote$(INC_LOCAL_DIR)

ifdef LIBRARY
$(TARGET_$(DIR)): CPPFLAGS := $(CPPFLAGS) -iquote$(LIBRARY)
endif

# Clean variables 
# If this is the top level (the one where make is invoked) do add the Makefile
# and the Rules.mk files to MKCLEAN

CLEAN += $(OBJ_$(DIR))
FCLEAN += $(TARGET_$(DIR)) $(DEP_$(DIR))
ifneq ($(DIR),)
MKCLEAN += $(DIR)Makefile $(DIR)Rules.mk
endif

# Inclusion of depency files (auto-generated)

-include $(DEP_$(DIR))

# Inclusion of subdirs Rules.mk

$(foreach SUBDIR,$(addsuffix /,$(SUBDIRS)),$(eval $(INCLUDE_SUBDIRS)))

# Tracking current directory

DIR := $(DIR_$(STACK_POINTER))
STACK_POINTER := $(basename $(STACK_POINTER))
