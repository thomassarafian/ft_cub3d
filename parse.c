#include "cub.h"
#include "parsing_res.c"
#include "parsing_texture.c"
#include "parsing_rgb.c"
#include "parsing_map.c"

// tsarafia je tenais a te dire que tu est vraimet un exemple au quotidien, tu me donne la cefor tous les jours. Reste tel quel. Ne bouge pas.

void	ft_error(char *str)
{

	write(1, str, ft_strlen(str));
	// system("leaks a.out");
	exit(0);
}


int		parsing(t_cub *cub, char *line)
{
	int i;

	i = 0;
	char *str;
	// while (line[i])
	// {
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
		else if (line[i] == 'F')
			parsing_floor(cub, line);
		else if (line[i] == 'C')
			parsing_ceiling(cub, line);
		else if (line[i] == '1' && (!ft_strrchr(line, 'R') && !ft_strrchr(line, 'C') && !ft_strrchr(line, 'F')))
			return (parsing_map(cub, line));
		// i++;
	// }
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
	t_cub cub;
	// printf("coucoucou\n");
	cub.parse.map = malloc(sizeof(char **));
	// cub.parse.map = malloc(sizeof(char **)); //mallcoc la double chaien 1 fois
	// cub = malloc(sizeof(t_cub));
	// cub->parse = malloc(sizeof(t_parse));

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(parsing(&cub, line)))
			ft_error("parsing fail");
	}

	// printf("%s\n", cub.parse.map[2]);
	// int k = 0;
	// int j = 0;
	// while (k < 100)
	// {
	// 	j = 0;
	// 	while (j < 100)
	// 	{
	// 		printf("%c", cub.parse.map[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	k++;
	// }
	//tmp[i] = line;
	//tmp[i] = ft_strjoin(tmp[i], "\n");
	//printf("%s", line);
	//printf("%s\n", cub->parse.res);

	printf("\nres_x : |%s| res_y : |%s| south : |%s| north : |%s| east : |%s| weast |%s|\n", cub.parse.res_x, cub.parse.res_y, cub.parse.south, cub.parse.north, cub.parse.east, cub.parse.west);
	printf("FLOOR | R : %d - G : %d - B : %d\n", cub.parse.floor_rgb[0], cub.parse.floor_rgb[1], cub.parse.floor_rgb[2]);
	printf("CEILING | R : %d - G : %d - B : %d\n", cub.parse.ceiling_rgb[0], cub.parse.ceiling_rgb[1], cub.parse.ceiling_rgb[2]);
	// // free(t_parse);
	// // free(cub);

	// system("leaks a.out");
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


// char	*ft_strcut(char *str, char first, char last)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	char *ret;
// 	if (!(ret = malloc(sizeof(char) * ft_strlen(str)) + 1))
// 		ft_error("malloc fail");
// 	while (str[i] == first)
// 		i++;
// 	while (str[i] != last)
// 	{
// 		ret[j] = str[i];
// 		j++;
// 		i++;
// 	}
// 	while (str[i] == last)
// 		i++;
// 	ret[j] = '\0';
// 	return ret;
// }
