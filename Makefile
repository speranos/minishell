
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -lreadline#-fsanitize=address
SRCS = *.c
all : $(NAME)

$(NAME) : $(SRCS)
	@$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
	@echo YOUR ARE READY TO GO !!!
clean :
	@rm -rf $(NAME)
	@echo CLEAN !!!
fclean :
	@rm -rf $(NAME)
	@echo RESET ...
re : fclean all