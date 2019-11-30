/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchahed <nchahed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:44:31 by nchahed           #+#    #+#             */
/*   Updated: 2019/11/30 17:57:36 by nchahed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		write (1, "Error\n", 6);
	else
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, &line);
		ft_putendl_fd(line, 1);
		free(line);
	}
	return (0);
}
