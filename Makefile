NAME = so_long

SRC = Mandatory/so_long.c Mandatory/ft_check.c Mandatory/ft_checkmap2.c Mandatory/ft_checkmap3.c \
	Mandatory/ft_startgame.c Mandatory/ft_freemap.c Mandatory/ft_checkmove.c

BNS = Bonus/so_long_bonus.c Bonus/ft_check_bonus.c Bonus/ft_checkmap2_bonus.c Bonus/ft_checkmap3_bonus.c \
	Bonus/ft_startgame_bonus.c Bonus/ft_freemap_bonus.c Bonus/ft_checkmove_bonus.c Bonus/ft_animations.c \

	
CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx-linux -lmlx -lX11 -lXext -lm

OBJ = $(SRC:%.c=%.o)
BONUS = $(BNS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		@$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a $(MLXFLAGS) -o $(NAME)
		
bonus: $(BONUS)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		@$(CC) $(CFLAGS) $(BONUS) ./libft/libft.a $(MLXFLAGS) -o so_long_bonus

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx-linux
		@$(RM) $(OBJ) $(BONUS)
		
fclean: clean
		$(MAKE) fclean -C ./libft
		@$(RM) $(NAME) so_long_bonus
		
re: fclean all
		$(MAKE) re -C ./libft
		$(MAKE) re -C ./minilibx-linux

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	cc -nostartfiles -shared -o libft.so $(OBJ)
