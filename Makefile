CC = gcc
LIBFT = ./libft
CFLAGS = -Wextra -Wall -Werror -O3 -g3 -I. -I$(LIBFT)

NAME = fdf

SOURCES = fdf_main.c 

BUILD = build
OBJECTS = $(addprefix $(BUILD)/, $(SOURCES:.c=.o))
HEADERS = fdf.h $(LIBFT)/libft.h

all: $(NAME)

$(BUILD):
	@mkdir -p $(BUILD)

$(BUILD)/%.o: %.c $(HEADERS) | $(BUILD)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	@$(CC) $(OBJECTS) $(LIBFT)/libft.a -o $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

clean:
	@rm -rf $(BUILD)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re

