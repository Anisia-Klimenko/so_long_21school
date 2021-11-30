NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 
MLXFLAGS=	-Lmlx -lmlx -framework OpenGL -framework AppKit

OBJDIR	=	obj
# OBJDIRB	=	obj_bonus
SRCDIR	=	src
LIBDIR	=	libft
MLXDIR	=	mlx

HEADER	=	so_long.h
HEADERB	=	so_long_bonus.h

MLX		=	libmlx*
LIBFT	=	libft.a

SRC		= 	main.c	\
			$(SRCDIR)/gnl/get_next_line.c	\
			$(SRCDIR)/gnl/get_next_line_utils.c	\
			$(SRCDIR)/valid_map.c	\
			$(SRCDIR)/images.c	\
			$(SRCDIR)/utils.c	\
			$(SRCDIR)/hooks.c

SRCB	=	main_bonus.c	\
			$(SRCDIR)/gnl/get_next_line.c	\
			$(SRCDIR)/gnl/get_next_line_utils.c	\
			$(SRCDIR)/valid_map_bonus.c	\
			$(SRCDIR)/images_bonus.c	\
			$(SRCDIR)/utils_bonus.c	\
			$(SRCDIR)/hooks_bonus.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJB	=	$(addprefix $(OBJDIR)/, $(SRCB:.c=.o))

.PHONY	:	all bonus clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@printf "\nLibft compiling ...\n"
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			@printf "\nMinilibX compiling ...\n"
			@make -C $(MLXDIR)/
			@cp $(MLXDIR)/$(MLX) ./
			@printf "\nGame compiling...\n"
			@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@printf "\nCompilation OK! \n"

bonus	: 	$(OBJB)
			@printf "\nLibft compiling ...\n"
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			@printf "\nMinilibX compiling ...\n"
			@make -C $(MLXDIR)/
			@cp $(MLXDIR)/$(MLX) ./
			@printf "\nBonus game compiling...\n"
			@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJB) $(LIBFT) -o $(NAME)
			@printf "\nBonus compilation OK! \n"

$(OBJDIR)/%.o: 	%.c $(HEADER)
				@printf "Sources compiling... \n"
				$(CC) $(CFLAGS) -Imlx -c $< -o $@
$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER)
				@printf "Sources compiling... \n"
				$(CC) $(CFLAGS) -Imlx -c $< -o $@
$(OBJDIR)/$(SRCDIR)/gnl/%.o: 	$(SRCDIR)/gnl/%.c $(HEADER)
					@printf "GNL compiling... \n"
					$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJDIR) :
	@mkdir $@ $@/$(SRCDIR) $@/$(SRCDIR)/gnl

$(OBJ) : | $(OBJDIR)
$(OBJB) : | $(OBJDIR)

clean:
	@printf "\nclean... \n"
	@make fclean -C $(LIBDIR)/
	@make clean -C $(MLXDIR)/
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "\nfclean... \n"
	@rm -f $(NAME)
	@rm -f $(MLX)
	@rm -f $(LIBFT)

re: fclean all