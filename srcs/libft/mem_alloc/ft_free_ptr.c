/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:59:54 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/20 16:29:19 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_ptr(void **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
	{
		if (array[i])
			array[i]= ft_free(array[i]);
	}
	ft_free(array);
}
