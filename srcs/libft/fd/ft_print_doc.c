/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:36:42 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/04 12:23:15 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_doc(char *str)
{
	int		fd;
	char	*line;

	fd = ft_open_fd(str, 1);
	if (fd == -1)
	{
		printf("Error: heredoc file could not be opened\n");
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_putstr_fd(line, 1);
		ft_free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_free(line);
}
