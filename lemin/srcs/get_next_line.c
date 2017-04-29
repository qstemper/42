/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:14:21 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/20 08:31:50 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_checkstatic(char **line, char *storage_buffer)
{
	char		*find;

	find = ft_strchr(storage_buffer, '\n');
	if (find == NULL)
		return (-1);
	*find = 0;
	*line = ft_strdup(storage_buffer);
	ft_strcpy(storage_buffer, find + 1);
	return (1);
}

static void		ft_lsttoline(char **line, t_list **lst)
{
	t_list		*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_strcat(*line, (char *)(*lst)->content);
		ft_lstdelone(lst, NULL);
		*lst = tmp;
	}
}

static int		ft_linecons(char **line, \
				char *storage_buffer, t_list **lst, char *buffer)
{
	int			len;
	t_list		*tmp;
	char		*find;

	len = ft_strlen(storage_buffer);
	tmp = *lst;
	while (tmp)
	{
		len += tmp->content_size;
		tmp = tmp->next;
	}
	find = ft_strchr(buffer, '\n');
	if (find == NULL && *lst == NULL)
		return (1);
	else if (find)
		*find = '\0';
	len += ft_strlen(buffer);
	if ((*line = ft_memalloc((len + 1) * sizeof(char))) == NULL)
		return (-1);
	ft_strcpy(*line, storage_buffer);
	ft_lsttoline(line, lst);
	ft_strcat(*line, buffer);
	return (1);
}

static int		ft_readton(int fd, char *buffer, t_list **lst)
{
	char		*find;
	int			check;
	t_list		*elem;

	find = NULL;
	check = -1;
	while (find == NULL && check != 0)
	{
		ft_bzero((void *)buffer, MY_SIZE);
		check = read(fd, buffer, MY_BUFF_SIZE);
		if (check == -1)
			return (-1);
		buffer[check] = '\0';
		find = ft_strchr(buffer, '\n');
		if (find == NULL && check != 0)
		{
			if ((elem = ft_lstnew((void *)buffer, \
							(check + 1) * sizeof(char))) == NULL)
				return (-1);
			ft_lstaddback(lst, elem);
		}
	}
	if (check == 0)
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	storage_buffer[OPENED_FILE_LIMIT][MY_SIZE];
	char		buffer[MY_SIZE];
	t_list		*lst;
	int			check;

	*line = NULL;
	if (MY_BUFF_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (ft_checkstatic(line, storage_buffer[fd]) == 1)
		return (1);
	lst = NULL;
	if ((check = ft_readton(fd, buffer, &lst)) == -1)
		return (-1);
	if (ft_linecons(line, storage_buffer[fd], &lst, buffer) == -1)
		return (-1);
	ft_strcpy(storage_buffer[fd], buffer + ft_strlen(buffer) + 1);
	return (*line ? 1 : 0);
}
