/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:10:53 by nadesjar          #+#    #+#             */
/*   Updated: 2022/05/22 16:11:06 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_array_len(int *nbrs)
{
    int len;
    int i;

    len = 0;
    i = -1;
    if (!nbrs)
        return (0);
    while (nbrs[++i] != '\0')
        len += 1;
    return (len);
}