/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:44:45 by tsarafia          #+#    #+#             */
/*   Updated: 2020/03/10 20:03:01 by tsarafia         ###   ########.fr       */
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
	char **linee;
	char *res;
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
	char **str;
	t_parse *parser;
};
typedef struct	s_cub t_cub;




#endif
