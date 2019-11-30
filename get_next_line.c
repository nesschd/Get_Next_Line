/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchahed <nchahed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:57:07 by nchahed           #+#    #+#             */
/*   Updated: 2019/11/30 18:00:09 by nchahed          ###   ########.fr       */
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
	while ((ret = read(fd, buf, BUFFER_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		i = 0;
		while (buf[i] != '\n' && buf[i])
			i++;
		if (buf[i] == '\n')
		{
			if(!(tmp = (char *)malloc(sizeof(char) * (ret - i))))
				return (-1);
			buf[i] = '\0';
			i++;
			j = 0;
			while (buf[i + j])
			{
				tmp[j] = buf[i + j];
				j++;
			}
			tmp[j] = '\0';
			if (!(*line = gnl_strjoin(tmp_begline, buf)))
				return (-1);
			return (1);
		}
		else
		{
			if(!(tmp_begline = gnl_strjoin(tmp_begline, buf)))
				return (-1);
		}
	}
	if (ret == -1)
		return (-1);
	else
	{
		*line = tmp_begline;
		return (0);
	}
}
