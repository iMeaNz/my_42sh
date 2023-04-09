##
## EPITECH PROJECT, 2021
## B-CPE-210-STG-2-1-stumper6-mehdy.morvan
## File description:
## Makefile
##

OBJ1 := main.o \
		parser/main_parser.o \
		parser/raw_parser.o \
		terminal/arrows.o \
		terminal/cursor_pos.o \
		terminal/delete.o

C_FLAGS := -Wall -Wextra -g
CC := gcc
RM := rm
LINKFLAGS := -lmy

SRC_PATH := ./src/
OBJ_PATH := ./obj/
LIB_PATH := -L ./lib/my/
INC_PATH := -I ./include

NAME := 42sh

OBJ := $(patsubst %, $(OBJ_PATH)%, $(OBJ1))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(dir $@)
				@echo [CC] $<
				@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)

$(NAME):      $(OBJ)
				make -C lib/my
				@echo [INFO] Creating Binary Executable [$(NAME)]
				@$(CC) -o $@ $^ $(LIB_PATH) $(LINKFLAGS)

clean:
				@echo "[Cleaning]"
				make clean -C lib/my
				@$(RM) -rfv $(OBJ_PATH)*

fclean:
				make clean
				make fclean -C lib/my
				@$(RM) -rfv $(NAME)

re: fclean all

.PHONY: all clean fclean re cli
