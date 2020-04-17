/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_matrix4x4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:06:50 by xamartin          #+#    #+#             */
/*   Updated: 2020/04/17 22:56:18 by xamartin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "tools.h"

void			perspective_matrix4x4(t_matrix *m, float y_fov,
	float aspect, float n, float f)
{
	// y_fov in radians
	float		a;
	
	a = 1.f / tanf(y_fov / 2.f);
	m->values[0][0] = a / aspect;
	m->values[0][1] = 0.f;
	m->values[0][2] = 0.f;
	m->values[0][3] = 0.f;
	m->values[1][0] = 0.f;
	m->values[1][1] = a;
	m->values[1][2] = 0.f;
	m->values[1][3] = 0.f;
	m->values[2][0] = 0.f;
	m->values[2][1] = 0.f;
	m->values[2][2] = -((f + n) / (f - n));
	m->values[2][3] = -1.f;
	m->values[3][0] = 0.f;
	m->values[3][1] = 0.f;
	m->values[3][2] = -((2.f * f * n) / (f - n));
	m->values[3][3] = 0.f;
}

void			translate_in_place_matrix4x4(t_matrix *m,
	float x, float y, float z)
{
	float		t[4];
	float		r[4];
	int			i;

	i = -1;
	t[0] = x;
	t[1] = y;
	t[2] = z;
	t[3] = 0;
	while (++i < 4)
	{
		vertex4_row_matrix4x4(r, m, i);
		m->values[3][i] += vertex4_mul_inner(r, t);
	}
}

void		look_at_matrix4x4(t_matrix *m, float camera_pos[3], float up_data)
{
	float	up[3];
	float	tmp_f[3];
	float	tmp_s[3];
	float	tmp_t[3];
	float	center[3];

	ft_bzero(up, sizeof(float[3]));
	up[1] = up_data;
	ft_bzero(center, sizeof(float[3]));

	ft_bzero(tmp_f, sizeof(float[3]));
	vertex3_sub(tmp_f, center, camera_pos);	
	vertex3_norm(tmp_f, tmp_f);	
	
	ft_bzero(tmp_s, sizeof(float[3]));
	vertex3_mul_cross(tmp_s, tmp_f, up);
	vertex3_norm(tmp_s, tmp_s);

	ft_bzero(tmp_t, sizeof(float[3]));
	vertex3_mul_cross(tmp_t, tmp_s, tmp_f);

	m->values[0][0] =  tmp_s[0];
	m->values[0][1] =  tmp_t[0];
	m->values[0][2] = -tmp_f[0];
	m->values[0][3] =   0.0f;
	m->values[1][0] =  tmp_s[1];
	m->values[1][1] =  tmp_t[1];
	m->values[1][2] = -tmp_f[1];
	m->values[1][3] =   0.0f;
	m->values[2][0] =  tmp_s[2];
	m->values[2][1] =  tmp_t[2];
	m->values[2][2] = -tmp_f[2];
	m->values[2][3] =   0.0f;
	m->values[3][0] =  0.0f;
	m->values[3][1] =  0.0f;
	m->values[3][2] =  0.0f;
	m->values[3][3] =  1.0f;
	mat4x4_translate_in_place(m, -camera_pos[0],
		-camera_pos[1], -camera_pos[2]);
}