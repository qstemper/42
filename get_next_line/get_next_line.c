/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:13:34 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/27 19:26:58 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//testbranch

#include "get_next_line.h"

static int	ft_checkstore(char *storage)
{
	char		*find;
	char		**line;

	find = ft_strchr(storage, '\n');
	if (find == NULL)
		return (0);
	*find = 0;
	*line = ft_strdup(storage);
	ft_strcpy(storage, find + 1);
	return (1);
}

static int	ft_readton(char *buffer)
{
	int		storage_read;
	char	*find;

	storage_read = read(fd, buffer, BUFF_SIZE);
	if (storage_read == -1)
		return (storage_read);
	buffer[storage_read] = '\0';
	ft_bzero((void *)(buffer + storage_read), (BUFF_SIZE - storage_read));
	return (storage_read);
}

static void		ft_lstcons()
{
	
}

int			get_next_line(int const fd, char **line)
{
	static char	storage_buffer[BUFF_SIZE + 1];
	char		buffer[BUFF_SIZE + 1];
	char		*find;
	t_list		*listbuff;
	t_list		*elem;
	t_list		*tmp;
	int			storage_read;
	int			flag;
	int			sum;

	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (ft_checkstore(storage_buffer) == 1)
		return (1);
	flag = 0;
	listbuff = NULL;
	sum = ft_strlen(storage_buffer);
	storage_read = ft_readton(buffer);
	while (flag != 1)
	{
		if (storage_read == -1)
			return (storage_read);
		find = ft_strchr(buffer, '\n');
		if (find == NULL && storage_read != 0)
		{
			elem = ft_lstnew((void *)buffer, storage_read * sizeof(char));
			if (elem == NULL)
				return (-1);
			ft_lstaddback(&listbuff, elem);
			sum += storage_read;
		}

		else if (find != NULL)
		{
			flag = 1;
			sum += (find - buffer + 1);
			if ((*line = (char *)ft_memalloc(sizeof(char) * sum)) == NULL)
				return (-1);
			ft_strcat(*line, storage_buffer);
			while (listbuff)
			{
				ft_strcat(*line, (char *)listbuff->content);
				tmp = listbuff->next;
				ft_lstdelone(&listbuff, NULL);
				listbuff = tmp;
			}
			*find = 0;
			ft_strcat(*line, buffer);
			ft_strcpy(storage_buffer, find + 1);
		}
		else
		{
			flag = 1;
			sum += (ft_strlen(buffer + 1));
			if ((*line = (char *)ft_memalloc(sizeof(char) * sum)) == NULL)
				return (-1);
			ft_strcat(*line, storage_buffer);
			while (listbuff)
			{
				ft_strcat(*line, (char *)listbuff->content);
				tmp = listbuff->next;
				ft_lstdelone(&listbuff, NULL);
				listbuff = tmp;
			}
			ft_strcat(*line, buffer);
			ft_strcpy(storage_buffer, buffer);
		}
	}
	if (storage_read == 0)
		return (0);
	return (1);
}

/*#include <fcntl.h>
int 	main()
{
	int fd;
	char *line;

	fd = open("test", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("[%d]\n", get_next_line(1, NULL));
	printf("[%d]\n", get_next_line(42, &line));
	while (get_next_line(fd, &line) > 0)
	{
		printf("[%s]\n", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
