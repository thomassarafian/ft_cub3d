#include "cub.h"

char	*find_res_x(t_cub *cub, char *line)
{
	int start;
	int i;

	start = 0;
	i = 0;
	line++;
	while (!ft_isdigit(line[start]))
		start++;
	while (ft_isdigit(line[start]))
	{
		start++;
		i++;
	}
	if (!(cub->parse->res_x = malloc(i + 1)))
		return (NULL);
	start -= i;
	i = 0;
	while (ft_isdigit(line[start]))
	{
		cub->parse->res_x[i] = line[start];
		i++;
		start++;
	}
	cub->parse->res_x[i] = '\0';
	return cub->parse->res_x;
}



int		parsing(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		printf("%c", line[i]);
		if (line[0] == 'R')
			cub->parse->res_x = ft_strdup(line);
		printf("o K ::: %s\n", find_res_x(cub, line));
		//if (line[1]
		i++;
	}
	printf("\n");
	//	printf("%s\n", line);

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
		//
		//appel d'une fonction qui va tout foutre dans une structure 
		//
		//	tmp[i] = line;
		//	tmp[i] = ft_strjoin(tmp[i], "\n");
		//	printf("%s", tmp[i]);
		//	printf("%s\n", cub->str[i]);
		//	printf("i ->%d<-\n", i);
		//i++;
		// if (line[0] == 'R')
		// 	res = ft_strdup(line);
		// else if (line[0] == 'S')
		// 	sprite_tex = ft_strdup(line);
	}
	//tmp[i] = line;
	//tmp[i] = ft_strjoin(tmp[i], "\n");
	//printf("%s", line);
	//printf("%s\n", cub->parse->res);

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
