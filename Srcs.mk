# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgautier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 07:58:53 by mgautier          #+#    #+#              #
#*   Updated: 2016/12/27 18:46:29 by mgautier         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

TARGET := fillit
SRC := ft_file_reader.c ft_parser.c ft_piece_reader.c ft_relative_position.c \
	ft_string_to_coordinates.c ft_transform_tetri.c ft_valid_pieces_format.c

# Directories

SRC_DIR := srcs
INC_DIR := includes
TEST_DIR := test
OBJ_DIR := object

# Dependencies

LIBRARY := libft
OBJECTS :=
ELSE :=

# Sub directories

SUBDIRS := libft
