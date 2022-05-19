# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 17:34:53 by sbombadi          #+#    #+#              #
#    Updated: 2022/01/26 20:44:34 by sbombadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SERVER_B = server_bonus

CLIENT_B = client_bonus

FT_PRINTF = ft_printf/libftprintf.a

HEADER = minitalk.h

HEADER_B = minitalk_bonus.h

CFLAGS = -Wall -Wextra -Werror

all: $(FT_PRINTF) $(CLIENT) $(SERVER) $(HEADER)

$(SERVER): server.c $(HEADER)
	@cc server.c $(FT_PRINTF) -o $@

$(CLIENT): client.c $(HEADER)
	@cc $(CFLAGS) client.c $(FT_PRINTF) -o $@

$(SERVER_B): server_bonus.c $(HEADER_B)
	@cc server_bonus.c $(FT_PRINTF) -o $@

$(CLIENT_B): client_bonus.c $(HEADER_B)
	@cc client_bonus.c $(FT_PRINTF) -o $@

$(FT_PRINTF):
	@make -C./FT_PRINTF
bonus: $(FT_PRINTF) $(SERVER_B) $(CLIENT_B) $(HEADER_B)

clean:
	@make clean -C ./FT_PRINTF

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	make fclean -C ./FT_PRINTF

re: fclean all

.PHONY: all re clean fclean bonus
