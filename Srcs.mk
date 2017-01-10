# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2017/01/10 18:22:35 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Informations to be fillet about the project at that level
# (Even if empty, DO NOT REMOVE any variable definition)

TARGET := fillit
SRC := ft_add_tetri.c ft_calculate_array_size.c ft_display_file.c ft_empty_tab.c \
	ft_file_reader.c ft_is_placable.c ft_parser.c ft_piece_reader.c \
	ft_relative_position.c ft_solver.c ft_string_to_coordinates.c \
	ft_transform_tetri.c ft_valid_pieces_format.c main.c

# Directories

SRC_DIR := srcs
INC_DIR := includes
OBJ_DIR := object
DEP_DIR := .dep
TEST_DIR := test

# Dependencies

LIBRARIES := libft
OBJECTS :=
ELSE :=

# Sub directories

SUBDIRS := libft
