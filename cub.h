/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <tsarafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:59:08 by tsarafia          #+#    #+#             */
/*   Updated: 2020/03/11 14:57:45 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# define BUFFER_SIZE 2048

struct		s_parse
{
//	char **linee;
	char *res_x;
	char *res_y;
	char *north;
	char *south;
	char *west;
	char *east;
	char *sprite;
	char *floor;
	char *ceiling;
	char **map;
};
typedef	struct	s_parse	t_parse;


struct		s_cub
{
	t_parse *parse;
};
typedef struct	s_cub t_cub;




#endif
