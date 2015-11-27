/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:13:34 by qstemper          #+#    #+#             */
/*   Updated: 2015/11/27 14:31:14 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	static char	storage_buffer[BUFF_SIZE + 1];
	char		buffer[BUFF_SIZE + 1];
	char		*find;
	t_list		*listbuff;
	t_list		*elem;
	t_list		*tmp;
	int			storage_read;
	int			size_line;
	int			flag;
	int			sum;

	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	flag = 0;
	listbuff = NULL;
	sum = ft_strlen(storage_buffer);
	while (flag != 1)
	{
		storage_read = read(fd, buffer, BUFF_SIZE);
		if (storage_read == -1)
			return (storage_read);
		buffer[storage_read] = '\0';
		find = ft_strchr(buffer, '\n');
		if (find == NULL)
		{
			elem = ft_lstnew((void *)buffer, storage_read * sizeof(char));
			if (elem == NULL)
				return (-1);
			ft_lstaddback(&listbuff, elem);
			sum += storage_read;
		}
		else
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
			if (storage_read == 0)
				return (0);
			return (1);
		}
	}

/*	while (buffer[size_line] != '\n' && buffer[size_line] != '\0')
		size_line++;
	if (buffer[size_line] == '\n')
	{
		*line = ft_strndup(buffer, size_line);
		store_buff(buffer + size_line);
	}
	else if (buffer[size_line] == sub)
		*line = ft_strndup(buffer, size_line);
	else
		store_buff(buffer);
*/
}
