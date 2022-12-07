/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:40:00 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/08 13:13:07 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long int	ft_atoi(const char *str)
{
	int			i;
	int			ctmin;
	long int	numb;

	i = 0;
	ctmin = 1;
	numb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ctmin = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		numb = (str[i++] - '0') + (numb * 10);
		if (numb > INT_MAX || numb < INT_MIN)
			return (9);
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (numb * ctmin);
	}
	return (0);
}
