/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:13:43 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/06 18:50:37 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGS_H
# define IMGS_H

typedef struct s_wall {
	void	 	*wall_01;
	void		*circle;
}	t_wall;

typedef struct s_imgs {
	int			test;
	t_wall		wall;
}	t_imgs;


#endif