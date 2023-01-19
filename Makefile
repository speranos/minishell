
NAME = minishell
#CC = cc
<<<<<<< HEAD
CFLAGS = -lreadline -Wall -Wextra -Werror #-L/Users/aoueldma/goinfre/homebrew/opt/readline/lib -I /Users/aoueldma/goinfre/homebrew/opt/readline/include -fsanitize=address
SRCS = lexer/*.c syntax_check/*.c parser/*.c expand/*.c *.c execution/built/*.c execution/libft/*.c
=======
CFLAGS = -lreadline -Wall -Wextra -Werror -fsanitize=address -g3 #-L/Users/aoueldma/goinfre/homebrew/opt/readline/lib -I /Users/aoueldma/goinfre/homebrew/opt/readline/include -fsanitize=address
SRCS = lexer/*.c syntax_check/*.c parser/*.c expand/*.c *.c execution/built/*.c execution/LIBFT/*.c
>>>>>>> 6ded913c7dd048de9aa388486f49797f72da67b2
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