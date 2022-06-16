/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:38:29 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/06/16 17:18:31 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Crea un nuevo conjunto elemento de lista que comprende una linea del archivo
	especificcado.
*/
t_list	*ft_rdlst(int fd)
{
	t_list	*new;
	int		i;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	i = read(fd, new->s, BUFFER_SIZE);
	if (i <= 0)
	{
		free(new);
		return (0);
	}
	new->s[i] = 0;
	new->len = i;
	new->nl = new->len - ft_strlen(ft_strchr(new->s, '\n'));
	if (!ft_strchr(new->s, '\n'))
		new->next = ft_rdlst(fd);
	else
		new->next = 0;
	return (new);
}

char	*ft_lsttostr(t_list *lst)
{
	t_list	*cur;
	char	*s;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	cur = lst;
	while (cur)
	{
		i += cur->len;
		cur = cur->next;
	}
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (0);
	i = 0;
	while (lst)
	{
		cur = lst;
		i += ft_strlcpy(cur->s, s + i, BUFFER_SIZE);
		lst = cur->next;
		free(cur);
	}
	return (s);
}

char	*get_next_line_aux(int fd, char *aux)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = get_next_line(fd);
	if (!s1)
		return (ft_substr(aux, '\0'));
	i = ft_strlen(aux) + ft_strlen(s1);
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (ft_substr(aux, '\0'));
	ft_strlcpy(s1, s2 + ft_strlcpy(aux, s2, BUFFER_SIZE), i);
	free(s1);
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	aux[BUFFER_SIZE + 1];
	char		*s1;
	char		*s2;
	t_list		*new;

	if (fd < 0 || fd > 1000 || BUFFER_SIZE <= 0)
		return (0);
	if (*aux != 0)
	{
		s1 = ft_substr(aux, '\n');
		ft_strlcpy(aux + ft_strlen(s1), aux, BUFFER_SIZE);
		if (ft_strlen(aux) != 0)
			return (s1);
		s2 = get_next_line_aux(fd, s1);
		free(s1);
		return (s2);
	}
	new = ft_rdlst(fd);
	s1 = ft_lsttostr(new);
	s2 = ft_substr(s1, '\n');
	ft_strlcpy(s1 + ft_strlen(s2), aux, BUFFER_SIZE);
	free(s1);
	return (s2);
}
