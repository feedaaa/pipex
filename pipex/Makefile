NAME = pipex

# LIBFT 		= libft.a

LFT_PATH 	= ./libft/libft/

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

SRCS = 	pipex.c \
		utils2.c \
		utils.c \
		error.c

# SRCS_BONUS = 	./srcs_bonus/pipex_bonus.c\
# 				./srcs_bonus/utls_bonus.c\
# 				./srcs_bonus/error_bonus.c\

OBJ=$(notdir $(SRCS:.c=.o))

# OBJ_BONUS=$(notdir $(SRCS_BONUS:.c=.o))

$(NAME) : $(OBJ) 
# $(LIBFT)
	@echo "\n$(CY)Generating pipex executable...$(RC)\n"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L $(LFT_PATH) -lft
	@echo "$(GR)Done!$(RC)\n\n"

$(OBJ): $(SRCS)
	@echo "\n$(CY)Compiling source files...$(RC)\n"
	@$(CC) $(CFLAGS) -g -c -I ./includes/ $(SRCS)
	@echo "$(GR)Objects ready!$(RC)\n\n"

$(OBJ_BONUS): $(SRCS_BONUS)
	@echo "\n$(CY)Compiling source files...$(RC)\n"
	@$(CC) $(CFLAGS) -g -c -I ./includes/ $(SRCS_BONUS)
	@echo "$(GR)Objects ready!$(RC)\n\n"

# $(LIBFT):
# 	@echo "\n$(GR)Generating Libft...$(RC)\n"
# 	@make all -C libft/libft/
# 	@echo "$(GR)Libft created!$(RC)\n"
	
bonus : $(OBJ_BONUS) $(LIBFT)
	@echo "\n$(CY)Generating pipex bonus executable...$(RC)\n"
	@gcc $(CFLAGS) $(OBJ_BONUS) -o $(NAME) -L $(LFT_PATH) -lft
	@echo "$(GR)Pipex bonus Done!$(RC)\n\n"

all : $(NAME)

fclean : clean
	@echo "\n$(YE)Cleaning all additional objects and libraries...$(RC)\n"
	@$(RM) $(NAME)
	# @make fclean -C libft/libft/
	@echo "$(RE)All libraries removed!$(RC)\n"

clean :
	@echo "\n$(YE)Cleaning all object files...$(RC)\n"
	@$(RM) $(OBJ) $(OBJ_BONUS)
	# @make clean -C libft/libft/
	@echo "$(RE)objects removed!$(RC)\n"

re : fclean all

.PHONY: clean fclean re all