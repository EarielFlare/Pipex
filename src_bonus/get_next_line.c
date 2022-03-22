/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:40:14 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/21 16:46:59 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_next_line(char **line)
{
	int			i;
	int			rd;
	char		letter;
	static char	first_line[0];

	i = 0;
	*line = first_line;
	rd = read(0, &letter, 1);
	while (rd > 0 && letter != '\n')
	{
		first_line[i++] = letter;
		rd = read(0, &letter, 1);
	}
	first_line[i] = '\0';
	return (rd);
}
