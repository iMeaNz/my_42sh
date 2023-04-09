##
## EPITECH PROJECT, 2021
## Makefile DAY10
## File description:
## Makefile used to create lib
##

OBJ1 =	my_compute_power_it.o			\
		my_compute_square_root.o		\
		my_find_prime_sup.o				\
		my_getnbr_base.o				\
		my_getnbr.o						\
		my_is_prime.o					\
		my_isneg.o						\
		my_put_nbr.o					\
		my_dput_nbr.o					\
		my_sput_nbr.o					\
		my_putchar.o					\
		my_putnbr_base.o				\
		my_putstr.o						\
		my_putstderr.o					\
		my_revstr.o						\
		my_show_word_array.o			\
		my_sort_int_array.o				\
		my_str_isalpha.o				\
		my_str_islower.o				\
		my_str_isnum.o					\
		my_str_isprintable.o			\
		my_str_isupper.o				\
		my_str_to_word_array.o			\
		my_strcat.o						\
		my_strcmp.o						\
		my_strcpy.o						\
		my_strlen.o						\
		my_strlowcase.o					\
		my_strncat.o					\
		my_strncmp.o					\
		my_strncpy.o					\
		my_strstr.o						\
		my_strupcase.o					\
		my_swap_char.o					\
		my_swap.o						\
		is_alpha.o						\
		is_lower.o						\
		is_num.o						\
		is_upper.o						\
		init_int_array.o				\
		init_matrix.o					\
		init_str_array.o				\
		init_str.o						\
		open_file.o						\
		open_file_with_stat.o			\
		my_printf.o						\
		my_dprintf.o					\
		my_sprintf.o					\
		int_to_str.o 					\
		delete_node_with_key.o 			\
		my_list_size.o 					\
		my_rev_list.o 					\
		my_sort_list.o 					\
		print_linked_list.o				\
		push_in_linked_list.o			\
		append_in_linked_list.o 		\
		my_strtok.o 					\
		my_strtok_alpha.o				\
		insert_substring.o				\
		delete_char.o

OBJ_PATH = obj/

RM := rm

OBJ := $(patsubst %, $(OBJ_PATH)%, $(OBJ1))

NAME = libmy.a

all:
	@$(MAKE) -s $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(dir $@)
				@echo [CC] $<
				@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)

$(NAME):	$(OBJ)
			@echo [INFO] Creating library [$(NAME)]
			ar -rc $(NAME) $(OBJ_PATH)*

clean:
		@$(RM) -rfv $(OBJ_PATH)*

fclean:		clean
		@$(RM) -rfv $(NAME)
		@$(RM) -rfv $(OBJ_PATH)

re:		fclean all

.PHONY:		all clean fclean re
