/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchahed <nchahed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:44:31 by nchahed           #+#    #+#             */
/*   Updated: 2019/11/30 18:03:38 by nchahed          ###   ########.fr       */
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
	int		ret;

	if (ac != 2)
		write (1, "Error\n", 6);
	else
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) && ret != -1)
		{
			ft_putendl_fd(line, 1);
			free(line);
		}
		close(fd);
	}
	return (0);
}
