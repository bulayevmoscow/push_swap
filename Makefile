TARG_PS	:= push_swap
TARG_CH	:= checker
CFLAGS 	:= -Wall -Werror -Wextra
CC 		:= gcc

# Source and object direct
LIBFT	:= ./libft/libft_full.a
INC		:= ./includes/
LFT_DIR := ./libft/
OBJ_DIR	:= ./obj/

# Source files
FILE	:=  srcs/validation.c srcs/init.c srcs/operations.c srcs/get_arg.c srcs/utility.c srcs/sort.c srcs/quicksort.c
SRCS	+= $(notdir $(FILE))
HEADER	:= includes/*.h

# Object files
OBJF	:= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

vpath %.c srcs/

RED 	:= \033[31;1m
GREEN 	:= \033[32;1m
DBLUE 	:= \033[34m
WHITE	:= \033[39;1m
EOC		:= \033[00m

all: $(TARG_PS) $(TARG_CH)

$(TARG_PS): obj $(LIBFT) $(OBJF)
	@$(CC) $(OBJF) $(LIBFT) -o $@ srcs/push_swap.c
	@printf "\n$(GREEN)compiled: $(WHITE)$(TARG_PS)$(EOC)\n"

$(TARG_CH): obj $(LIBFT) $(OBJF)
	@$(CC) $(OBJF) $(LIBFT) -o $@ srcs/checker.c
	@printf "\n$(GREEN)compiled: $(WHITE)$(TARG_CH)$(EOC)\n"

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER) Makefile
	@printf "$(DBLUE) - Compiling $< into $@\r$(EOC)"
	@$(CC) $(CFLAGS) -I $(INC) -I $(LFT_DIR)/includes -c $< -o $@

$(LIBFT): FORCE
	@make -C $(LFT_DIR)

clean:
	@rm -rf *.o obj
	@make clean -C $(LFT_DIR)
	@echo "$(RED)deleted: $(WHITE)obj files$(EOC)"

fclean: clean
	@rm -f $(TARG_PS) $(TARG_CH)
	@make fclean -C $(LFT_DIR)
	@echo "$(RED)deleted: $(WHITE)$(TARG_PS)$(EOC)"
	@echo "$(RED)deleted: $(WHITE)$(TARG_CH)$(EOC)"

re: fclean all

FORCE:

.PHONY: clean fclean re all FORCE
