#include "cub.h"

char	*parsing_res_x(t_cub *cub, char **line)
{
	int start;
	int i;

	start = 0;
	i = 0;
	i++;
	while (!ft_isdigit(line[0][i]))
		i++;
	while (ft_isdigit(line[0][start]))
		start++;
	if (!(cub->parse->res_x = malloc(start + 1)))
		return (NULL);
	start = 0;
	printf("|%c|\n", **line);
	while (ft_isdigit(line[0][i]))
	{
		cub->parse->res_x[start] = line[0][i];
		printf("--------%d\n", start);
		//printf("VOILI : %c\n", **line);
	//	printf("VOILA : %c | %d\n", cub->parse->res_x[start], start);
		i++;
		start++;
	}
	cub->parse->res_x[start] = '\0';
	return (cub->parse->res_x);
}

char	*parsing_res_y(t_cub *cub, char **line)
{
	int start;
	int i;

	start = 0;
	i = 0;
	while (!ft_isdigit(**line))
		(*line)++;
	while (ft_isdigit(*line[start]))
		start++;
	if (!(cub->parse->res_y = malloc(start + 1)))
		return (NULL);
	start = 0;
	while (ft_isdigit(**line))
	{
		cub->parse->res_y[start] = **line;
		start++;
		(*line)++;
	}
	cub->parse->res_y[start] = '\0';
	return (cub->parse->res_y);
}


int parsing_res(t_cub *cub, char *line)
{
	line = malloc(sizeof(line));
//		return (NULL);
	parsing_res_x(cub, &line);	
	parsing_res_y(cub, &line);
	return (1); //ERROR A CORIGER
}

int		parsing_north(t_cub *cub, char *line)
{
	while (*line != '.')
		line++;
	if (!(cub->parse->north = ft_strdup(line)))
		return (-1);
	return 1;
}
int		parsing_west(t_cub *cub, char *line)
{
	while (*line != '.')
		line++;
	if (!(cub->parse->west = ft_strdup(line)))
		return (-1);
	return 1;
}

int		parsing_east(t_cub *cub, char *line)
{
	while (*line != '.')
		line++;
	if (!(cub->parse->east = ft_strdup(line)))
		return (-1);
	return 1;
}

int		parsing_south(t_cub *cub, char *line)
{
	while (*line != '.')
		line++;
	if (!(cub->parse->south = ft_strdup(line)))
		return (-1);
	return 1;
}
int		parsing(t_cub *cub, char *line)
{
	int i;

	i = 0;
	
	while (line[i])
	{
		if (line[i] == 'R')
			parsing_res(cub, line);
		else if (line[i] == 'N' && line[i + 1] == 'O')
			parsing_north(cub, line);
		else if (line[i] == 'S' && line[i + 1] == 'O')
			parsing_south(cub, line);
		else if (line[i] == 'W' && line[i + 1] == 'E')
			parsing_west(cub, line);
		else if (line[i] == 'E' && line[i + 1] == 'A')
			parsing_east(cub, line);
		else if (line[i] == 'S')
			parsing_south(cub, line);
/*		else if (line[i] == 'F')
			parsing_floor(cub, line);
		else if (line[i] == 'C')
			parsing_ceiling(cub, line);
*/
		i++;
	}
	return 0;	 
}



//parsing ce sera toujours le meme ordre mais il peut y avoir des espaces et des \n


int main(int ac, char **av)
{
	char *line;
	int fd;
	int rdbytes;
	int ret;
	int i;

	fd = open(av[1], O_RDONLY);
	ret = 0;
	i = 0;
	t_cub *cub;
	cub = malloc(sizeof(cub));
	cub->parse = malloc(sizeof(cub->parse));
	//cub->parse->linee = malloc(sizeof(cub->parse->linee) * 12);
	//cub->parser->res = ft_strdup("salut");
	//cub->parser->line = malloc(sizeof());
	//	printf("%s\n", cub->parse->line[0]);


	while ((ret = get_next_line(fd, &line)) > 0)
	{
		parsing(cub, line);
	}
	//tmp[i] = line;
	//tmp[i] = ft_strjoin(tmp[i], "\n");
	//printf("%s", line);
	//printf("%s\n", cub->parse->res);

	printf("res_x : |%s| res_y : |%s| south : |%s| north : |%s| east : |%s| weast |%s|\n", cub->parse->res_x, cub->parse->res_y, cub->parse->south, cub->parse->north, cub->parse->east, cub->parse->west);

//	system("leaks a.out");
	return 0;

}


// |
// 	map_raw = ft_strdup("");
// 	line;
// 	map_raw = ft_strjoin(map_raw, line);
// 	map_raw = ft_strjoin(map_raw, "\n");
// |
/*
   strcuture de char 

*/
