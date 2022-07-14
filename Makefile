NAME			=	cub3d
	
LIBFT_A			=	libft.a
LIBFT_H			=	libft.h
LIBFT_DIR		=	libft/
LIBFT_INC		=	libft/inc
LIBFT			=	-L libft -l ft -I libft/inc/



# src
SRCS_DIR		=	src/
SRCS			=	main.c

SRCS_OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))

OBJ				=	$(SRCS_OBJS)

CFLAGS			=	#-Wall -Wextra -Werror -Imlx #-g -fsanitize=address

CC				=	gcc

.PHONY			:	all clean fclean re
		
all				:	$(LIBFT_A) mlx/libmlx.a $(NAME)
		
%.o				:	%.c
					@$(CC) $(CFLAGS) -I include -c $< -o $@
		
$(NAME)			:	$(OBJ)
					@gcc $(CFLAGS) -Lmlx -lmlx -framework OpenGL\
					-framework AppKit -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT_A)		:
					@make -sC $(LIBFT_DIR)

clean			:
					@rm -f $(OBJ)
					@make clean -sC $(LIBFT_DIR)
		
fclean			:	clean
					@rm -f $(NAME)
					@make fclean -sC $(LIBFT_DIR)
		
re				:	fclean all
		
run				:	all
					@./cub3d
