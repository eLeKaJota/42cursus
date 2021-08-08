#include "includes/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_terrain;
	void	*img_collectable;
	void	*img_exit;
	void	*img_wall;
	char	*file;
	char    **map;
	int		map_size_x;
	int		map_size_y;
	int		img_pos_x;
	int		img_pos_y;
	int     player_pos_x;
	int     player_pos_y;
	int     exit_pos_x;
	int     exit_pos_y;
	int		img_width;
	int		img_height;
	int     collectables;
	int     moves;
}			t_vars;

void    ft_draw_map(t_vars *vars)
{
    int i;
    int j;
    int sprite_size;

    i = 0;
    sprite_size = 50;
    vars->img_pos_x = 0;
    vars->img_pos_y = 0;
    printf("x: %d, y: %d\n", vars->player_pos_x, vars->player_pos_y);
    while (i < vars->map_size_y)
    {
        j = 0;
        while (j < vars->map_size_x)
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->img_terrain, vars->img_pos_x, vars->img_pos_y);
            if (vars->map[i][j] == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall, vars->img_pos_x, vars->img_pos_y);
            if (vars->map[i][j] == 'C')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img_collectable, vars->img_pos_x, vars->img_pos_y);
            if (vars->map[i][j] == 'E')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img_exit, vars->img_pos_x, vars->img_pos_y);
            if (vars->map[i][j] == 'P')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, vars->img_pos_x, vars->img_pos_y);


            vars->img_pos_x += sprite_size;
            j++;
        }
        vars->img_pos_x = 0;
        vars->img_pos_y += sprite_size;
        i++;
    }
}

void	ft_map_count(t_vars *vars)
{
	int		fd;
	int		x;
	int		y;
	char	buf;

	x = -1;
	y = 2;
	fd = open(vars->file, O_RDONLY);
	while (read(fd, &buf, 1) != 0)
	{
		x++;
		if (buf == '\n')
			break;
	}
	while (read(fd, &buf, 1) != 0)
	{
		if (buf == '\n')
			y++;
	}
	close(fd);
	vars->map_size_x = x;
	vars->map_size_y = y;
}

void    ft_map_alloc(t_vars *vars)
{
    int i;
    char    **map;

    i = 0;
    map = malloc(sizeof(char*) * vars->map_size_y);
    while (i < vars->map_size_y)
    {
    	map[i] = malloc(vars->map_size_x + 1);
        i++;
    }
    vars->map = map;
}

void	ft_map_write(t_vars *vars)
{
	int		fd;
	int		x;
	int		y;
	char	buf;

	x = 0;
	y = 0;
	fd = open(vars->file, O_RDONLY);
	printf("Lineas: %d, Columnas: %d\n", vars->map_size_y, vars->map_size_x);
	while (read(fd, &buf, 1) != 0)
	{
		if (buf != '\n')
		{
			vars->map[y][x] = buf;
			if (buf == 'P')
			{
				vars->player_pos_x = x;
				vars->player_pos_y = y;
			}
			if (buf == 'C')
				vars->collectables++;
			if (buf == 'E')
			{
			    vars->exit_pos_x = x;
			    vars->exit_pos_y = y;
			}
			x++;
		}
		else if (buf == '\n')
		{
			vars->map[y][x] = 0;
			y++;
			x = 0;
		}
	}
	close(fd);
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 123 || keycode == 97 || keycode == 0)
	{
	    if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] != '1'){
	        if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] == 'C')
	            vars->collectables--;
	        if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] == 'E' && vars->collectables != 0)
	            printf("Aún no tienes todos los coleccionables");
	        else
	            vars->player_pos_x--;
	    }
	}
	if (keycode == 124 || keycode == 100 || keycode == 2)
	{
	    if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] != '1')
	    {
	        if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] == 'C')
	            vars->collectables--;
	        if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] == 'E' && vars->collectables != 0)
	            printf("Aún no tienes todos los coleccionables");
	        else
	            vars->player_pos_x++;
	    }
	}
	if (keycode == 125 || keycode == 115 || keycode == 1)
	{
	    if (vars->map[vars->player_pos_y + 1][vars->player_pos_x] != '1')
	    {
	        if (vars->map[vars->player_pos_y + 1][vars->player_pos_x] == 'C')
	            vars->collectables--;
	        if (vars->map[vars->player_pos_y + 1][vars->player_pos_x ] == 'E' && vars->collectables != 0)
	            printf("Aún no tienes todos los coleccionables");
	        else
	            vars->player_pos_y++;
	    }
	}
	if (keycode == 126 || keycode == 119 || keycode == 13)
	{
	    if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] != '1')
	    {
	        if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] == 'C')
	            vars->collectables--;
	        if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] == 'E' && vars->collectables != 0)
	            printf("Aún no tienes todos los coleccionables");
	        else
	            vars->player_pos_y--;
	    }
	}
	printf("[Collectables: %d]", vars->collectables);
	if (vars->collectables == 0 && vars->player_pos_x == vars->exit_pos_x && vars->player_pos_y == vars->exit_pos_y)
	    printf("TA TA TA CHAAAAAAN!!!!!");
	vars->map[vars->player_pos_y][vars->player_pos_x] = 'P';
    ft_draw_map(vars);
	return (0);
}

void    ft_get_sprites(t_vars *vars)
{
    char	*player_path = "img/player.xpm";
    char	*terrain_path = "img/terrain.xpm";
    char	*collectable_path = "img/collectable.xpm";
    char	*exit_path = "img/exit.xpm";
    char	*wall_path = "img/wall.xpm";

    vars->img_player = mlx_xpm_file_to_image(vars->mlx, player_path, &vars->img_width, &vars->img_height);
    vars->img_terrain = mlx_xpm_file_to_image(vars->mlx, terrain_path, &vars->img_width, &vars->img_height);
    vars->img_collectable = mlx_xpm_file_to_image(vars->mlx, collectable_path, &vars->img_width, &vars->img_height);
    vars->img_exit = mlx_xpm_file_to_image(vars->mlx, exit_path, &vars->img_width, &vars->img_height);
    vars->img_wall = mlx_xpm_file_to_image(vars->mlx, wall_path, &vars->img_width, &vars->img_height);
}


int	main(int argc, char** argv)
{
	t_vars vars;

	vars.file = argv[1];
	ft_map_count(&vars);
	vars.img_width = 50;
	vars.img_height = 50;
	vars.img_pos_x = 0;
	vars.img_pos_y = 0;
	vars.collectables = 0;
    ft_map_alloc(&vars);
	ft_map_write(&vars);
	int i = 0;
	while (i < vars.map_size_y)
	{
		printf("linea %d - %s\n", i + 1, vars.map[i]);
		i++;
	}

//	ft_map_generator(&vars);
	vars.mlx = mlx_init();
	ft_get_sprites(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.map_size_x * 50,vars.map_size_y * 50,"./so_long");
	ft_draw_map(&vars);
	mlx_key_hook(vars.win, ft_key_hook ,&vars);
	mlx_loop(vars.mlx);
	return (0);
}

