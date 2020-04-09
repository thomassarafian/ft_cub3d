#include "cub.h"


int	parsing_map(t_cub *cub, char *line)
{
	int size_map;
	cub->parse.map[cub->parse.i++] = ft_strdup(line);
	return 1;
}


int		check_around(t_cub cub, char c, int i, int j)
{

	if (cub.parse.map[j][i - 1] == c ||
		cub.parse.map[j][i + 1] == c ||
		cub.parse.map[j - 1][i] == c ||
		cub.parse.map[j + 1][i] == c ||

		cub.parse.map[j - 1][i + 1] == c ||
		cub.parse.map[j][i + 1] == c ||
		cub.parse.map[j - 1][i] == c ||
		cub.parse.map[j + 1][i] == c ||)
	{
		return 1;
	}
	else
		return 0;
}

void	line_check(t_cub cub, int j)
{
	int i;

	i = 0;
	// while (cub.parse.map[j][i] == ' ')
	// 	i++;
	while (cub.parse.map[j][i])
	{
		if (cub.parse.map[j][i] == ' ')
		{
			if ((check_around(cub, ' ', i, j) || check_around(cub, '1', i, j)) && !check_around(cub, '0', i, j))
			{
				i++;
			}
			else
				ft_error("invalid map line check space");
		}
		if (cub.parse.map[j][i] == '1')
		{
			if (check_around(cub, '1', i, j) || check_around(cub, ' ', i, j) || check_around(cub, '0', i, j) )
			{
				i++;
			}
			else
				ft_error("invalid map line check space");
		}
		if (cub.parse.map[j][i] == '0')
		{
			if ((check_around(cub, '0', i, j) || check_around(cub, '1', i, j)) && !check_around(cub, ' ', i, j))
			{
				i++;
			}
			else
				ft_error("invalid map line check");
		}
		// i++;
	}
}
void	first_line_check(t_cub cub)
{
	int i;

	i = 0;
	while (cub.parse.map[0][i])
	{
		if (cub.parse.map[0][i] == '1' || cub.parse.map[0][i] == ' ')
			i++;
		else
			ft_error("invalid map first line check");
	}
}


int check_map(t_cub cub)
{

	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;

	while (y < cub.parse.nbline)
	{
		x = 0;
		while (x < cub.parse.strlen)
		{
			if (y == 0)
				first_line_check(cub);
			else
				line_check(cub, y);
			x++;
		}
		y++;
	}
	x = 0;
	i = 0;
	while (x < cub.parse.nbline)
	{

		printf("%d - ", i);
		printf("%s\n", cub.parse.map[x]);
		i++;
		x++;
	}



	return 0;
}

