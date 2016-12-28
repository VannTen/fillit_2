#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/04 13:12:11 by mgautier          #+#    #+#             *#
#*   Updated: 2016/12/28 16:33:21 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

.DEFAULT_GOAL:= all

# Build tools

SYSTEM = $(shell uname)
AR = ar 
ARFLAGS = rc
ifeq ($(SYSTEM),Linux)
	ARFLAGS += -U
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror -ansi -pedantic-errors
CFLAGS += $(CFLAGS_TGT)
CPPFLAGS :=

DEPFLAGS = -MT $@ -MP -MMD -MF $(word 2,$^).tmp

COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
POSTCOMPILE = sed -E 's|([0-9a-z_.:]*/)?([0-9a-z_.:]+)|$$(DIR)\2|g' $(word 2,$^).tmp > $(word 2,$^)
	
MKDIR = mkdir
RMDIR = rm -Rf

# DIRECTORY TARGETS RECIPES

# Static libary maintainer
LINK_STATIC_LIB = $(AR) $(ARFLAGS) $@ $?

# Executable linker
LINK_EXE = $(CC) $(LDFLAGS) $^ -o $@ $(LDFLAGS_TGT)

# These variables are used to obtain the .o and .dep files list
# for each level of the projet, by using the current value of SRC.

OBJ = $(patsubst %.c,$(OBJ_LOCAL_DIR)%.o,$(SRC))
DEP = $(patsubst %.c,$(DEP_LOCAL_DIR)%.dep,$(SRC))

# Compilation rule
# Generate dependencies as a side effet
# Cancel implicit rule for objetc files
# For each directory, create a static pattern rule (pattern rule applied only
# to a precise set of targets) that search in the relevant directory for each
# target and prerequisites.

%.o: %.c

define	STATIC_OBJ_RULE
$(OBJ_$(DIR)): $(OBJ_LOCAL_DIR)%.o: $(SRC_LOCAL_DIR)%.c $(DEP_LOCAL_DIR)%.dep | $(OBJ_LOCAL_DIR) $(DEP_LOCAL_DIR)
	$$(COMPILE)
	$$(POSTCOMPILE)
	$$(RM) $$(word 2,$$^).tmp
	touch $$@
endef

%.dep: ;

.PRECIOUS: %.dep

# Rules to generate the needed Makefiles in the subdirectories and update them if necessary.

%/Rules.mk: Rules.mk | %/Makefile
	ln -f $< $@
%/Makefile: Makefile
	ln -f $< $@

.PRECIOUS: %/Makefile

# Functions

define INCLUDE_SUBDIRS
include $(DIR)$(SUBDIR)Rules.mk
endef

define TARGET_ERROR
$$(error $$(DIR) : No target if indicated for that directory))
endef

define ADD_SLASH
$1_LOCAL_DIR := $(if $($1_DIR),$(DIR)$($1_DIR)/,$(DIR))
endef

# Clean-up variables
# Collect all the files that need to be deleted along all the project tree
# the clean-up rules then use them to do their job

CLEAN :=
FCLEAN :=
MKCLEAN :=

GENERATED_SUBDIRS :=
DIR := 
include Rules.mk
# Rule to create needed directories
$(GENERATED_SUBDIRS):
	$(MKDIR) $@

# Mandatory rules
# These are the rules which will be specified by the user as arguments to make

all: $(TARGET_$(DIR))

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
