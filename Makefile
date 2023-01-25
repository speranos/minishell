
NAME = minishell
#CC = cc
CFLAGS = -lreadline -Wall -Wextra -Werror -L/Users/abihe/homebrew/opt/readline/lib -I/Users/abihe/homebrew/opt/readline/include #-fsanitize=address
SRCS = lexer/*.c syntax_check/*.c parser/*.c expand/*.c *.c execution/built/*.c execution/libft/*.c
all : $(NAME)

$(NAME) : $(SRCS)
	@stty -echoctl
	@cc $(SRCS) $(CFLAGS) -o $(NAME)
	@echo YOUR ARE READY TO GO !!!
clean :
	@rm -rf $(NAME) *.o
	@echo CLEAN !!!
fclean :
	@rm -rf $(NAME)
	@echo RESET ...
re : fclean all