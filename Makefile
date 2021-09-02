# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 12:05:15 by ysoroko           #+#    #+#              #
#    Updated: 2021/09/02 16:52:57 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

EXECUTABLE = philo

GCC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

UTILS	=	utils/ft_output_utils.c \
			utils/ft_strings_utils.c \
			utils/ft_structure_utils.c \

PHILOS	=	philosophers/ft_thread_function.c \
			philosophers/ft_time_utils.c \
			philosophers/ft_states.c \
			philosophers/ft_forks.c \
			philosophers/ft_death.c \

SRC		=	$(UTILS) \
			$(PHILOS) \
			ft_main.c \

OBJS	=	$(SRC:.c=.o)

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

COMPILED = echo "\n📖 $(BOLD_PURPLE)Executable $(BOLD_CYAN)\"$(EXECUTABLE)\" $(BOLD_PURPLE)created and ready for use!\n$(NO_COLOR)"

# ------------------------------ Rules ------------------------------

all:	$(NAME)

$(NAME): $(OBJS)
		@$(COMP_START)
		@$(GCC) $(FLAGS) $(OBJS) -o $(EXECUTABLE)
		@$(COMPILED)

wrun:
		@$(COMP_START)
		@$(GCC) $(SRC) -o $(EXECUTABLE)
		@$(COMPILED)

clean:
		@rm -rf $(OBJS)
		@$(CLEANED)

fclean:	clean
		@rm -rf $(EXECUTABLE)
		@$(FCLEANED)

re:		fclean all

.c.o:
	@${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

# ------------------------------ Tests ------------------------------

# 1 - number of philosophers
# 2 - time to die
# 3 - time to eat
# 4 - time to sleep
# (optionnal) 5 - number of times they need to eat

# Test 1: no one should die
test1:	all
		./$(EXECUTABLE) 5 800 200 200

# Test 2: no one should die and the philosophers each eats 7 times
test2:	all
		./$(EXECUTABLE) 5 800 200 200 7

test2_count:
		make test2 | grep eating | wc -l
# grep < eating

# Test 3: no one should die
test3:	all
		./$(EXECUTABLE) 4 410 200 200

# Test 4: A philosopher should die
test4:	all
		./$(EXECUTABLE) 4 310 200 100

# -------------------------------------------------------------------

.PHONY:	all clean fclean re
