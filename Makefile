CC = cc
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
FTPRINTFDIR = ft_printf
FTPRINTF = $(FTPRINTFDIR)/libftprintf.a
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
OBJ = $(SRC:.c=.o)
INCLUDES = -I $(LIBFTDIR) -I $(FTPRINTFDIR)
RM := rm -f
SRC = src/main.c \
src/utils.c\
src/parsing.c\
src/find_min_max.c\
src/clean_exit.c\
src/push_cost.c\
src/find_target.c\
command/sa.c \
command/sb.c \
command/ss.c \
command/pa.c \
command/pb.c \
command/ra.c \
command/rb.c \
command/rr.c \
command/rra.c \
command/rrb.c \
command/rrr.c \


all: $(NAME)
	
$(NAME): $(OBJ) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $^ -o $@
$(LIBFT):
	@make -C $(LIBFTDIR) --no-print-directory
$(FTPRINTF):
	@make -C $(FTPRINTFDIR) --no-print-directory
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFTDIR) --no-print-directory
	@make clean -C $(FTPRINTFDIR) --no-print-directory
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR) --no-print-directory
	@make fclean -C $(FTPRINTFDIR) --no-print-directory
re: fclean all
	

.PHONY: all clean fclean re
