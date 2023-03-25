/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:45:19 by khle              #+#    #+#             */
/*   Updated: 2023/03/21 05:24:54 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"


char	*ft_get_line(char *buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!buff[0])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_rest(char *buff)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	while (buff[i])
		rest[j++] = buff[i++];
	rest[j] = '\0';
	free(buff);
	return (rest);
}

char	*ft_get_buff(int fd, char *buff)
{
	int		i;
	char	*str;

	i = 1;
	str = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (!ft_strchr(buff, '\n') && i != 0)
	{
		i = read (fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		buff = ft_strjoin(buff, str);
	}
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!buff)
	{
		buff = malloc(sizeof(char));
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	buff = ft_get_buff(fd, buff);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	line = ft_get_line(buff);
	buff = ft_get_rest(buff);
	return (line);
}

// int main()
// {
// 	int fd;
// 	int i;
// 	int fd2;
// 	char *test;
// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("line %s\n", line);
// 	free(line);
// 	/* i = 1;
//  	 while (1)
// 	{
// 		test = get_next_line(fd);
// 		if (!test)
// 			break;
// 		printf("\nline [%d]:%s", i, test);
// 		free(test);
// 		i++;
// 	} */
// 	// printf("\nline1:%s", get_next_line(fd));
// 	// printf("\nline1:%s", get_next_line(fd));
// 	// printf("\nline2:%s", get_next_line(fd2));
// 	// printf("\nline2:%s", get_next_line(fd2));
// 	// printf("\nline1:%s", get_next_line(fd));
// 	// close(fd);
// 	// close(fd2);
// }