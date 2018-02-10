/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 22:18:00 by tyang             #+#    #+#             */
/*   Updated: 2018/02/04 23:08:20 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char		*read_file(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*str;
	char	*del;

	ret = 0;
	str = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			del = ft_strjoin(str, buff);
			free(str);
			str = del;
		}
	}
	return (str);
}

static t_list	*find_fd(t_list *list, int fd)
{
	t_list	*temp;
	t_gnl	*curr;

	temp = list;
	while (temp != NULL)
	{
		curr = (t_gnl*)temp->content;
		if (curr->fd == fd)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

static t_list	*make_list(t_list *head, int fd)
{
	t_gnl	new;
	t_list	*curr;
	t_list	*new_list;

	if (head == NULL)
	{
		new.fd = fd;
		new.store = read_file(fd);
		new_list = ft_lstnew(&new, sizeof(new));
		return (new_list);
	}
	curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	new.fd = fd;
	new.store = read_file(fd);
	new_list = ft_lstnew(&new, sizeof(new));
	curr->next = new_list;
	return (head);
}

static char		*get_line(t_gnl *curr, char *line)
{
	char	*temp;
	int		count;

	count = 0;
	temp = curr->store;
	if (temp == NULL)
		return (NULL);
	if (*temp == '\0')
		return (NULL);
	while (*temp)
	{
		if (*temp == '\n')
		{
			line = ft_strsub(curr->store, 0, count);
			curr->new_store = ft_strdup(temp + 1);
			free(curr->store);
			curr->store = curr->new_store;
			return (line);
		}
		count++;
		temp++;
	}
	line = ft_strsub(curr->store, 0, count);
	curr->store = NULL;
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*curr_list;
	t_gnl			*curr;
	char			buff[BUFF_SIZE + 1];

	if (read(fd, buff, 0) < 0 || line == NULL || BUFF_SIZE < 0 || fd > 4864)
		return (-1);
	if ((curr_list = find_fd(list, fd)) == NULL)
		list = make_list(list, fd);
	curr_list = find_fd(list, fd);
	curr = (t_gnl*)curr_list->content;
	if ((*line = get_line(curr, *line)) != NULL)
		return (1);
	else
		return (0);
}
