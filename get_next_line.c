/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:38:29 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/06/10 19:09:40 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	crea un nuevo elemento de la lista y le introduce una nueva cadena sacada
	del archivo especificado.
*/
t_list	*ft_rdbuff(int fd)
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
	new->next = 0;
	return (new);
}

t_list	*ft_rdlst(int fd)
{
	t_list	*new;

	new = ft_rdbuff(fd);
	if (!new)
		return (0);
	if (new->nl == new->len)
		new->next = ft_rdlst(fd);
	return (new);
}

char	*ft_linespace(t_list *lst)
{
	int		i;
	char	*s;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i += lst->nl;
		lst = lst->next;
	}
	s = malloc(sizeof(char) * (i + 1));
	return (s);
}

void	ft_strcpylst(t_list *lst, char *s)
{
	int		i;

	if (!lst)
		return ;
	i = ft_strlcpy(lst->s, s, BUFFER_SIZE);
	ft_strcpylst(lst->next, s + i);
	free(lst);
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
		s1 = aux;
	else
	{
		new = ft_rdlst(fd);
		s1 = ft_linespace(new);
		ft_strcpylst(new, s1);
	}
	s2 = ft_substr(s1, '\n');
	ft_strlcpy(s1 + ft_strlen(s2), aux, BUFFER_SIZE);
	free(s1);
	return (s2);
}

/*
	int main(void)
	{
		int		fd;
		// t_list	*new;
		char	*s;

		fd = open("get_next_line.c", O_RDONLY);
		// new = ft_rdlst(fd);
		// s = ft_linespace(new);
		s = get_next_line(fd);
		// s = ft_substr("hola\nque tal", '\n');
		// ft_strcpylst(new, s);
		printf("%s\n", s);
		free(s);
		close(fd);
		while (1);
		return 0;
	}
*/