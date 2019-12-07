/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchahed <nchahed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:57:23 by nchahed           #+#    #+#             */
/*   Updated: 2019/12/06 16:54:56 by nchahed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20 
#endif

int		get_next_line(int fd, char **line);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strlen(char *s);

#endif
