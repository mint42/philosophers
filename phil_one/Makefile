# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 11:54:37 by rreedy            #+#    #+#              #
#    Updated: 2020/06/13 16:43:32 by mint             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phil_one

SRC_DIR := ./srcs
INCLUDE_DIR := ./includes

CC := gcc
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -I$(INCLUDE_DIR)
CFLAGS += -pthread

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))
DEPS := $(patsubst %.c,%.d,$(SRCS))

LIBFT := $(LIBFT_DIR)/$(LIBFT_NAME)
MAKE_LIBFT := $(MAKE) -C $(LIBFT_DIR) -f $(LIBFT_MAKEFILE) --no-print-directory

.PHONY: all clean fclean re name

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MT $@ -c $< -o $@

-include $(DEPS)

clean:
	@- $(RM) $(OBJS) $(DEPS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
