#include "cub.h"
//#include "gnl/get_next_line.h"
//#include "libft/libft.h"
int main(int ac, char **av)
{
	char *line;
	int fd;
	int rdbytes;
	int ret;
	int i;
	fd = open(av[1], O_RDONLY);
	ret = 0;
	t_cub *cub;
	cub = malloc(sizeof(cub));
	i = 0;
	//printf("dodisds\n");
	cub->str = malloc(sizeof(char *) * 1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
	//	printf("%s\n", line);
		cub->str[i] = ft_strdup(line);

		//parse(cub);
		//
		//appel d'une fonction qui va tout foutre dans une structure 
		//
	//	tmp[i] = line;
	//	tmp[i] = ft_strjoin(tmp[i], "\n");
	//	printf("%s", tmp[i]);
	//	printf("%s\n", cub->str[i]);
		i++;
		// if (line[0] == 'R')
		// 	res = ft_strdup(line);
		// else if (line[0] == 'S')
		// 	sprite_tex = ft_strdup(line);
	}
	//tmp[i] = line;
	//tmp[i] = ft_strjoin(tmp[i], "\n");
	//printf("%s", line);

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
