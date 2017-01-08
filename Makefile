#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/04 13:12:11 by mgautier          #+#    #+#             *#
#*   Updated: 2017/01/08 15:25:09 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

##
## Externals programms
##
CC = gcc
AR = ar
MKDIR = mkdir
RMDIR = rm -Rf
SED = sed
LN = ln -f
TOUCH = touch

##
## Project specific variable
##

FILE_CHAR_RANGE := a-z0-9._

# Extern variables (depending on build environnement)

SYSTEM = $(shell uname)

##
## Externals programms flags
##

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -ansi -pedantic-errors

CPPFLAGS :=
DEPFLAGS = -MT $$@ -MP -MMD -MF $$(word 2,$$^).tmp

# Archive maintainer flags
ARFLAGS = rc
ifeq ($(SYSTEM),Linux)
 ARFLAGS += -U
endif

##
## Build tools
##

# Object file compilation and dependency generation (as a side effect, see DEPFLAGS)
COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $$@ $$<

# Post processing on depencency file (done after compilation) for relative path.
POSTCOMPILE = $(SED) -e 's|$(OBJ_LOCAL_DIR)\([$(FILE_CHAR_RANGE)]*\.o\)|$$$$(OBJ_LOCAL_DIR)\1|g'\
				-e 's|$(SRC_LOCAL_DIR)\([$(FILE_CHAR_RANGE)]*\.c\)|$$$$(SRC_LOCAL_DIR)\1|g'\
				-e 's|$(INC_LOCAL_DIR)\([$(FILE_CHAR_RANGE)]*\.h\)|$$$$(INC_LOCAL_DIR)\1|g'\
				-e 's|$(LIB_LOCAL_DIR)\([$(FILE_CHAR_RANGE)]*\.h\)|$$$$(LIB_LOCAL_DIR)\1|g'\
				$$(word 2,$$^).tmp > $$(word 2,$$^)

# Add objects files to archive (static library)
LINK_STATIC_LIB = $(AR) $(ARFLAGS) $@ $?

# Linker
LINK_EXE = $(CC) $(LDFLAGS) $^ -o $@ $(LDFLAGS_TGT)


##
## Macro variables
##

# These variables are used to obtain the .o and .dep files list
# for each level of the projet, by using the current value of SRC.

OBJ = $(patsubst %.c,$(OBJ_LOCAL_DIR)%.o,$(SRC))
DEP = $(patsubst %.c,$(DEP_LOCAL_DIR)%.dep,$(SRC))

# Functions for handling directories and inclusion of submakefiles

define INCLUDE_SUBDIRS
include $(DIR)$(SUBDIR)Rules.mk
endef

define TARGET_ERROR
$$(error $$(DIR) : No target if indicated for that directory))
endef

define ADD_SLASH
$1_LOCAL_DIR := $(if $($1_DIR),$(DIR)$($1_DIR)/,$(DIR))
endef

##
## Build rules
##

# Compilation rule for objects files (.o) from C source files (.c)
# Generate dependencies files (.dep) as a side effet
# That macro is used with eval in each subdirs to generate a static pattern rule
# for the objects files in that directory

%.o: %.c

define	STATIC_OBJ_RULE
$(OBJ_$(DIR)): $(OBJ_LOCAL_DIR)%.o: $(SRC_LOCAL_DIR)%.c $(DEP_LOCAL_DIR)%.dep | $(OBJ_LOCAL_DIR) $(DEP_LOCAL_DIR)
	$(QUIET) $(COMPILE)
	$(QUIET) $(POSTCOMPILE)
	$(QUIET) $(RM) $$(word 2,$$^).tmp
	$(QUIET) $(TOUCH) $$@
endef

%.dep: ;

.PRECIOUS: %.dep

# Rules to generate the needed Makefiles in the subdirectories and update them if necessary.

%/Rules.mk: Rules.mk | %/Makefile
	$(QUIET) $(LN) $< $@
%/Makefile: Makefile
	$(QUIET) $(LN) $< $@

.PRECIOUS: %/Makefile

##
## Collecting variables (filled during the parsing of the Makefile with relevant files)
##

# These three variables collect respectively : all object files, target files and depency files,
# and submakefiles (that can be generated).
CLEAN :=
FCLEAN :=
MKCLEAN :=

# This variable collect all directory that are (or may be) created by make,
# meaning object and dependency directories
GENERATED_SUBDIRS :=

##
## Inclusion of subdirectories Makefiles (Rules.mk)
##

# Initialize the DIR variable, which tracks the directory whose make is parsing the Rules.mk
DIR := 
# Includes the local Rules.mk, which will include all the subdirectories Rules.mk
# (It could eventually include itself, since the DIR is independant from the actual location
# of Rules.mk)
include Rules.mk

# After having included all sub-Rules.mk, define the rules to create new directories if needed.
# (the directories are order-only prerequisites on build rules)
$(GENERATED_SUBDIRS):
	$(MKDIR) $@

##
## Standard rules for users
##

all: $(TARGET_$(DIR))

# Make sure the default target is always all
.DEFAULT_GOAL:= all

clean:
	$(RM) $(CLEAN)
	
mkclean:
	$(RM) $(MKCLEAN)

fclean: clean
	$(RM) $(FCLEAN)

dirclean:
	$(RMDIR) $(GENERATED_SUBDIRS)
	
mrproper: fclean mkclean

re: fclean all

.PHONY: debug all clean fclean mkclean dirclean re
