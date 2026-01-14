CC = gcc
LIBFT = ./libft
MINILIBX = ./mlx_linux
CFLAGS = -Wextra -Wall -Werror -O3 -g3 -I. -I$(LIBFT)

NAME = fdf

SOURCES = fdf_main.c 

BUILD = build
OBJECTS = $(addprefix $(BUILD)/, $(SOURCES:.c=.o))
HEADERS = fdf.h $(LIBFT)/libft.h $(MINILIBX)/mlx.h 

all: $(NAME)

$(BUILD):
	@mkdir -p $(BUILD)

$(BUILD)/%.o: %.c $(HEADERS) | $(BUILD)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)/libft.a $(MINILIBX)/liblmx.a
	@$(CC) $(OBJECTS) $(LIBFT)/libft.a -o $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(MINILIBX)/liblmx.a:
	@make -C $(MINILIBX)

clean:
	@rm -rf $(BUILD)
	@make -C $(LIBFT) clean
	@make -C $(MINILIBX) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re

