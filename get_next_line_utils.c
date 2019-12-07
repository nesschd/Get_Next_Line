/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchahed <nchahed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:53:40 by nchahed           #+#    #+#             */
/*   Updated: 2019/12/06 19:34:51 by nchahed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

int		gnl_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = gnl_strlen(s1) + gnl_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		str[i]= s1[i];
		i++;
	}
	free(s1);
	j = -1;
	while (s2[++j])
	{
		str[i + j] = s2[j];
	}
	str[len] = '\0';
	return (str);
}
