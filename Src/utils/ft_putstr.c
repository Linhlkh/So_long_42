/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:54:15 by khle              #+#    #+#             */
/*   Updated: 2023/03/22 04:35:43 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_putstr(char *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

char	**copy_map(char	**map)
{
	int		i;
	int		j;
	char	**new_char;

	i = ft_len_tab(map);
	new_char = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_char || !map)
		return (NULL);
	j = 0;
	while (map[j])
	{
		new_char[j] = ft_strdup(map[j]);
		j++;
	}
	new_char[j] = 0;
	return (new_char);
}

// int main()
// {
// 	int i = 0;
// 	char *str[] = {"These", "aress", "somes", "strin"};
// 	char **new;
// 	new = copy_map(str);
// 	while(new[i])
// 	{
// 		printf("%s\n", new[i]);
// 		i++;
// 	}
// }