CC = cc

CFLAGS = -Wall -Wextra -Werror 

ARGS= -Iinclude -lglfw   -L"/Users/$(USER)/goinfre/homebrew/opt/glfw/lib"

MLX42 = /Users/ylaaross/MLX42/build/libmlx42.a 

NAME = cub3D

BNAME = cub3DB

SRC =   P_Wall_check.c P_ft_split.c P_cube3d.c P_cube3d1.c P_cube3d2.c P_cube3d3.c P_cube3d4.c P_cube3d5.c P_get_next_line_utils.c P_get_next_line.c P_ft_substr.c P_file_store.c P_file_store1.c P_file_check.c P_ft_strdup.c P_ft_strstr.c P_ft_strstr1.c P_ft_strlen.c P_test_map.c P_test_map2.c P_var_check.c P_var_check1.c P_var_check2.c P_var_check3.c P_ft_strtrim.c P_ft_atoi.c P_size_calculate.c P_var_test.c P_map_create.c P_map_create1.c cub3d.c draw.c put_pixel.c move.c player.c checks.c raycasting.c drawing_tools.c raycasting_checks.c texters.c ft_split.c ft_strlen.c

SRCB = bonus/P_Wall_check.c bonus/P_ft_split.c bonus/P_cube3d.c bonus/P_cube3d1.c bonus/P_cube3d2.c bonus/P_cube3d3.c bonus/P_cube3d4.c bonus/P_cube3d5.c bonus/P_get_next_line_utils.c bonus/P_get_next_line.c bonus/P_ft_substr.c bonus/P_file_store.c bonus/P_file_store1.c bonus/P_file_check.c bonus/P_ft_strdup.c bonus/P_ft_strstr.c bonus/P_ft_strstr1.c bonus/P_ft_strlen.c bonus/P_test_map.c bonus/P_test_map2.c bonus/P_var_check.c bonus/P_var_check1.c bonus/P_var_check2.c bonus/P_var_check3.c bonus/P_ft_strtrim.c bonus/P_ft_atoi.c bonus/P_size_calculate.c bonus/P_var_test.c bonus/P_map_create.c bonus/P_map_create1.c bonus/cub3d.c bonus/draw.c bonus/put_pixel.c bonus/move.c bonus/player.c bonus/checks.c bonus/raycasting.c bonus/drawing_tools.c bonus/raycasting_checks.c bonus/texters.c bonus/ft_split.c bonus/ft_strlen.c

OBJS =  $(SRC:.c=.o)

OBJB = P_Wall_check.o P_ft_split.o P_cube3d.o P_cube3d1.o P_cube3d2.o P_cube3d3.o P_cube3d4.o P_cube3d5.o P_get_next_line_utils.o P_get_next_line.o P_ft_substr.o P_file_store.c P_file_store1.c P_file_check.c P_ft_strdup.o P_ft_strstr.o P_ft_strstr1.o P_ft_strlen.o P_test_map.o P_test_map2.o P_var_check.o P_var_check1.o P_var_check2.o P_var_check3.o P_ft_strtrim.o P_ft_atoi.o P_size_calculate.o P_var_test.o P_map_create.o P_map_create1.o cub3d.o draw.o put_pixel.o move.o bplayer.o bchecks.o braycasting.o bdrawing_tools.o braycasting_checks.o btexters.o bft_split.o bft_strlen.o

bonus :	$(BNAME) 

all : $(NAME) 

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS)  $(ARGS) $(MLX42) $^ -o $@

$(BNAME) : $(OBJB) 
		$(CC) $(CFLAGS)  $(ARGS) $(MLX42) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY = all clean fclean re