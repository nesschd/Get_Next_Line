/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchahed <nchahed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:57:07 by nchahed           #+#    #+#             */
/*   Updated: 2019/12/06 19:37:50 by nchahed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	int 		i;
	char		*tmp_begline;
	static char *tmp = NULL;
	int			j;

	tmp_begline = tmp;
	while ((ret = read(fd, buf, BUFFER_SIZE)) != -1)
	{
		buf[ret] = '\0';
		if (!(tmp_begline = gnl_strjoin(tmp_begline, buf)))
			return (-1);
		i = 0;
		while (tmp_begline[i] != '\n' && tmp_begline[i])
			i++;
		if (tmp_begline[i] == '\n')
		{
			if (!(tmp = (char *)malloc(sizeof(char) * gnl_strlen(tmp_begline + i))))
				return (-1);
			tmp_begline[i] = '\0';
			i++;
			j = 0;
			while (tmp_begline[i + j])
			{
				tmp[j] = tmp_begline[i + j];
				j++;
			}
			tmp[j] = '\0';
			*line = tmp_begline;
			return (1);
		}
		else if (ret == 0)
		{
			*line = (tmp_begline ? tmp_begline : malloc(1));
			tmp_begline = NULL;
			tmp = NULL;
			return (0);	
		}
	}
	return (-1);
}
