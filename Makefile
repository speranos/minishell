
NAME = minishell
#CC = cc
CFLAGS = -Wall -Wextra -Werror -lreadline -fsanitize=address
SRCS = lexer/*.c syntax_check/*.c parser/*.c expand/*.c *.c 
all : $(NAME)

$(NAME) : $(SRCS)
	@cc $(SRCS) $(CFLAGS) -o $(NAME)
	@echo YOUR ARE READY TO GO !!!
clean :
	@rm -rf $(NAME) *.o
	@echo CLEAN !!!
fclean :
	@rm -rf $(NAME)
	@echo RESET ...
re : fclean all