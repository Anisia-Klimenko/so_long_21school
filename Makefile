NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Imlx

OBJDIR	=	obj
SRCDIR	=	src
LIBDIR	=	libft

HEADER	=	so_long.h

SRC		= 	$(LIBDIR)/ft_putchar_fd.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))


.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@printf "Compilation OK! \n"

$(OBJDIR)/%.o: 	%.c $(HEADER)
				@printf "Sources compiling... \n"
				@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER)
				@printf "Sources compiling... \n"
				@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/$(LIBDIR)/%.o: 	$(LIBDIR)/%.c $(HEADER)
							@printf "Libft compiling... \n"
							@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@ $@/$(LIBDIR) $@/$(SRCDIR)

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... \n"
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "fclean... \n"
	@rm -rf $(NAME)

re: fclean all