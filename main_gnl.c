/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:39:14 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/02 09:56:28 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

int		main()
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line))
		printf("[%s]\n", line);
	close(fd);
	return (0);
}
