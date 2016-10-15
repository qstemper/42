/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 02:09:14 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/14 02:35:49 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			put_pix_file(int file, int i, int j)
{
	t_color			pix;

	pix.color = light_diaph(&env->e_scene.rend[i * env->e_scene.width + j], \
			env->e_scene.scene.diaph);
	ft_fprintf(file, "%d", &pix.b);
	ft_fprintf(file, "%d", &pix.g);
	ft_fprintf(file, "%d", &pix.r);
}

static void			put_file_header(int file)
{
	int				data[3];

	ft_printf(file, "BM");
	data[0] = (unsigned int)(env->e_scene.width * env->e_scene->height);
	data[1] = 0;
	data[2] = 54;
	ft_printf(file, "%s", (char *)data);
}

static void			put_img_header(int file)
{
	int				data[10];

	data[0] = 40;
	data[1] = (int)env->e_scene.scene.width;
	data[2] = (int)env->e_scene.scene.height;
	data[3] = 1 + 24 * 256 * 256;
	data[4] = 0;
	data[5] = 0;
	data[6] = 0;
	data[7] = 0;
	data[8] = 0;
	data[9] = 0;
	ft_fprintf(file, "%s", (char *)data);
}

void				export_img(int file)
{
	unsigned int	i;
	unsigned int	j;

	put_file_header(file);
	put_img_header(file);
	i = env->e_scene.scene->height;
	while (i > 0)
	{
		j = -1;
		while (++j < env->e_scene.scene->height)
			put_pixel_file(file, j, i - 1);
		i--;
	}
}
