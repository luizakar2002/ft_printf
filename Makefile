CC			= gcc

FLAGS		= -Wall -Werror -Wextra

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			  ft_handle_flags.c \
			  ft_handle_char.c \
			  ft_handle_int.c \
			  ft_handle_p.c \
			  ft_handle_str.c \
			  ft_handle_u.c \
			  ft_handle_x.c \
			  ft_handle.c \
			  ft_isdigit.c \
			  ft_itoa_u.c \
			  ft_itoa.c \
			  ft_len.c \
			  ft_memset.c \
			  ft_merge_int.c \
			  ft_merge_p.c \
			  ft_merge_str.c \
			  ft_merge_u.c \
			  ft_merge_x.c \
			  ft_printf.c \
			  ft_putchar.c \
			  ft_strdup.c \
			  ft_strrev.c \
			  int_to_hex.c \
			  int_to_hex_p.c \
			  add.c \


				
OBJS		= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
