# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2016/12/29 15:04:46 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# Informations to be fillet about the project at that level
# (Even if empty, DO NOT REMOVE any variable definition)

TARGET := fillit
SRC := ft_file_reader.c ft_parser.c ft_piece_reader.c ft_relative_position.c \
	ft_string_to_coordinates.c ft_transform_tetri.c ft_valid_pieces_format.c

# Directories

SRC_DIR := srcs
INC_DIR := includes
OBJ_DIR := object
DEP_DIR := .dep
TEST_DIR := test

# Dependencies

LIBRARY := libft.a
OBJECTS :=
ELSE :=

# Sub directories

SUBDIRS := libft
