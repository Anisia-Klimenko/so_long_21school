NAME	=	1so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 
MLXFLAGS=	-Lmlx -lmlx -framework OpenGL -framework AppKit

OBJDIR	=	obj
SRCDIR	=	src
LIBDIR	=	libft
MLXDIR	=	mlx

HEADER	=	so_long.h

MLX		=	libmlx.dylib
LIBFT	=	libft.a

SRC		= 	main.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@printf "\nLibft compiling ...\n"
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			@printf "\nMinilibX compiling ...\n"
			@make -C $(MLXDIR)/
			@cp $(MLXDIR)/$(MLX) ./
			$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@printf "\nCompilation OK! \n"

$(OBJDIR)/%.o: 	%.c $(HEADER)
				@printf "Sources compiling... \n"
				$(CC) $(CFLAGS) -Imlx -c $< -o $@
$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER)
				@printf "Sources compiling... \n"
				$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJDIR) :
	@mkdir $@ $@/$(SRCDIR)

$(OBJ) : | $(OBJDIR)

clean:
	@printf "\nclean... \n"
	@make fclean -C $(LIBDIR)/
	@make clean -C $(MLXDIR)/
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "\nfclean... \n"
	@rm -f $(NAME)
	@rm -f $(MLX)

re: fclean all