# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 15:14:49 by gsaid             #+#    #+#              #
#    Updated: 2022/06/14 15:24:00 by gsaid            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CCTEST	=	gcc -fsanitize=address -g3 -Wall -Wextra -Werror

NAME	=	libftprintf.a

SRC		=	ft_printf.c\
			src/ft_itoa_printf.c\
			src/ft_list.c\
			src/ft_libft_printf.c\
			src/ft_utils_p1.c\
			src/ft_utils_p2.c

OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra

all :	$(NAME)

dev :	${OBJS}
	@$(CC) $(CFLAGS) $(OBJS)
	@./a.out

norm :
	@norminette -R CheckForbiddenSourceHeader *.c src/*.c
	@norminette -R CheckDefine *.h

%.o :	%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) :	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS) src/$(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY :	all clean fclean re dev norm
