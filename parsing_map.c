#include "cub.h"


int	parsing_map(t_cub *cub, char *line)
{
	int size_map;
	cub->parse.map[cub->parse.i++] = ft_strdup(line);
	return 1;
}







// map
// {
// 	"111111111?",
// 	"100001111?",
// 	"100001110111111?",
// 	"10000111000101010111?"
// }

