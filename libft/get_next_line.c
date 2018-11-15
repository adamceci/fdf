/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:10:17 by aceciora          #+#    #+#             */
/*   Updated: 2018/11/15 15:42:21 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_error(int fd, char **line)
{
	if (fd <= -1 || fd >= OPEN_MAX || !line)
		return (0);
	return (1);
}

static int	check_tab(int fd, char tab[fd][BUFF_SIZE], char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[fd][i] && tab[fd][i] != '\n')
		i++;
	if (tab[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(tab[fd], 0, i)))
			return (-1);
		if (tab[fd][++i])
		{
			if (!(tmp = ft_strsub(tab[fd], i, ft_strlen(tab[fd]) - i)))
				return (-1);
			ft_bzero(tab[fd], BUFF_SIZE);
			ft_strcpy(tab[fd], tmp);
			free(tmp);
		}
		else
			ft_bzero(tab[fd], BUFF_SIZE);
		return (1);
	}
	return (0);
}

static int	check_buf(int fd, char tab[fd][BUFF_SIZE], char **line,
						char buf[BUFF_SIZE + 1])
{
	int		i;
	char	*tmp;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		tmp = ft_strsub(buf, 0, i);
		if (!tmp)
			return (-1);
		*line = ft_strjoin_free(*line, tmp, 1, 1);
		if (buf[++i])
		{
			tmp = ft_strsub(buf, i, ft_strlen(buf) - i);
			if (!tmp)
				return (-1);
			ft_strcpy(tab[fd], tmp);
			free(tmp);
		}
		return (*line == NULL ? -1 : 1);
	}
	return (0);
}

static int	read_file(int fd, char tab[fd][BUFF_SIZE], char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	int		result;

	if (check_tab(fd, tab, line))
		return (1);
	*line = ft_strdup(tab[fd]);
	ft_bzero(tab[fd], BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		result = check_buf(fd, tab, line, buf);
		if (result == -1)
			return (-1);
		else if (result == 1)
			return (1);
		if (!(*line = ft_strjoin_free(*line, buf, 1, 0)))
			return (-1);
	}
	if (ret < 0)
		return (-1);
	if (**line)
		return (1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	tab[OPEN_MAX][BUFF_SIZE];
	int			retour;

	if (!check_error(fd, line))
		return (-1);
	retour = read_file(fd, tab, line);
	if (retour == -1)
		return (-1);
	else if (retour == 0)
		return (0);
	else
		return (1);
}
