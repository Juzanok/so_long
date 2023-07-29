/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 04:23:32 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/07 14:08:49 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*read_file(int fd)
{
	char	*str;
	char	*buff;
	int		bytes;

	buff = (char *)malloc(sizeof(char));
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	if (!buff || !str || fd < 0)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buff, 1);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_join(str, buff);
	}
	free(buff);
	return (str);
}
