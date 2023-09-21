# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axel <axel@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 08:46:55 by jrenault          #+#    #+#              #
#    Updated: 2023/01/30 14:23:14 by axel             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) clear mkbuild lib clear clean fclean re sanitize

NAME					= pipex 

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= pipex.h
HEADERS_WITH_PATH		= $(addprefix $(HEADER_DIR),$(HEADER_FILE))

DIR						= src/
SRC			 			= pipex.c
							
OBJECTS			    	= ${addprefix ${BUILD_DIR},${SRC:.c=.o}}
	
LIBFT					= libft.a
LIB_DIR					= libft/
	
GCC						= cc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o:		$(DIR)%.c ${HEADERS_WITH_PATH}
						mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -c $< -o $@

all: 					clear mkbuild lib $(HEADER_DIR) $(NAME)
						
mkbuild:
						mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(CFLAGS) $(OBJECTS) $(LIB_DIR)$(LIBFT) -o $(NAME)

sanitize :				lib $(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)

lib:
						@make -C $(LIB_DIR)
						
clean:					
						${RM} $(OBJECTS)
						make clean -C $(LIB_DIR)
						${RM} $(BUILD_DIR)

fclean:					clean
						${RM} ${NAME}
						make fclean -C $(LIB_DIR)

re:						fclean all