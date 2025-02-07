
NAME= server
NAME_CLIENT= client
DEFAULT= chess
CC= cc
CFLAGS = -g  -I $(INCLUDES)
LDFLAGS =  -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
INCLUDES= ./includes
LIBFT_DIR= ./libs/libft
MLX_DIR= ./libs/mlx
MLX= $(MLX_DIR)/libmlx.a
LIBFT= $(LIBFT_DIR)/libft.a
SRCS_DIR= ./srcs/minitalk
DEFAULT_DIR= ./srcs/chess

DEFAULT_SRCS= $(DEFAULT_DIR)/main.c $(DEFAULT_DIR)/free_displays.c $(DEFAULT_DIR)/drawboard.c $(DEFAULT_DIR)/load_images.c \
$(DEFAULT_DIR)/drawpieces.c $(DEFAULT_DIR)/input_handler.c $(DEFAULT_DIR)/highlight.c $(DEFAULT_DIR)/moves.c

SRCS_SERVER= $(SRCS_DIR)/server.c $(SRCS_DIR)/free_displays.c $(SRCS_DIR)/drawboard.c $(SRCS_DIR)/load_images.c $(SRCS_DIR)/utils.c \
$(SRCS_DIR)/drawpieces.c $(SRCS_DIR)/input_handler.c $(SRCS_DIR)/highlight.c $(SRCS_DIR)/moves.c

SRCS_CLIENT= $(SRCS_DIR)/client.c $(SRCS_DIR)/free_displays.c $(SRCS_DIR)/drawboard.c $(SRCS_DIR)/load_images.c $(SRCS_DIR)/utils.c \
$(SRCS_DIR)/drawpieces.c $(SRCS_DIR)/input_handler.c $(SRCS_DIR)/highlight.c $(SRCS_DIR)/moves.c


OBJS_SERVER=$(SRCS_SERVER:.c=.o)
OBJS_CLIENT=$(SRCS_CLIENT:.c=.o)
OBJS_CHESS=$(DEFAULT_SRCS:.c=.o)


all: $(NAME) $(NAME_CLIENT)
	@echo "Project built, execute ./server, and ./client <PID of Server>!"

$(NAME) : $(OBJS_SERVER) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(LDFLAGS) -o $(NAME)


$(NAME_CLIENT) : $(OBJS_CLIENT) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LDFLAGS) -o $(NAME_CLIENT)

$(DEFAULT) : $(OBJS_CHESS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS_CHESS) $(LDFLAGS) -o $(DEFAULT)

%.o : %.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@make -C $(MLX_DIR) --no-print-directory

default: $(DEFAULT) fclean
	@echo "Project built, execute with ./chess"

clean:
	@rm -rf $(OBJS_SERVER)
	@rm -rf $(OBJS_CLIENT)OBJS_CHESS
	@rm -rf $(OBJS_CHESS)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@make clean -C $(MLX_DIR) --no-print-directory
	@echo "Cleaning Objects!"
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_CLIENT)
	@rm -rf $(DEFAULT)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "Cleaning Objects and game!"

re: fclean all

.PHONY: all clean fclean re


