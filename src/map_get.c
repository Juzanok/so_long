/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:28:37 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/10 19:54:56 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map(t_game **game, char *file)
{
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	str = read_file(fd);
	close(fd);
	(*game)->map = struct_map(str, '\n', &(*game)->max_y);
	(*game)->max_x = ft_strlen((*game)->map[0]);
	if (map_unknown_components(*game) == 0 || map_components(str) == 0
		|| map_border(*game) == 0 || map_figure(*game) == 0)
	{
		free(str);
		return (0);
	}
	free(str);
	map_init(*game);
	return (1);
}

char	**struct_map(char *src, char s, int *max_y)
{
	char	**dest;
	int		size;
	int		i;
	int		j;

	size = line_count(src, s);
	dest = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	(*max_y) = size;
	i = 0;
	while (i < size)
	{
		while (*src == s)
			src++;
		j = word_length(src, s);
		dest[i] = ft_strcpy(src, j);
		src += j;
		i++;
	}
	dest[size] = 0;
	return (dest);
}

int	line_count(char *src, char s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (src[i])
	{
		if (src[i] == s)
			count++;
		i++;
	}
	count++;
	return (count);
}

int	word_length(char *src, char s)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != s)
		i++;
	return (i);
}

char	*ft_strcpy(char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((j + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
