/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:13:14 by jgo               #+#    #+#             */
/*   Updated: 2022/12/28 18:50:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"
#include "error.h"

t_bool	is_valid_dot(char *dot)
{
	size_t i;

	i = 0;
	if (dot[i] == '-' || dot[i] == '+')
		i++;
	while (ft_isdigit(dot[i]))
		i++;
	if (i)
		return (TRUE);
	else
		return (FALSE);
}

void	cal_z_max(t_dot *max, char **split_arr)
{
	int	i;
	int	maximum;

	i = 0;
	while (split_arr[i])
	{
		maximum = ft_atoi(&split_arr[i][0]);
		if (max->axis[Z] < maximum)
			max->axis[Z] = maximum;
		// if (map->zmin > max) do i needed?
		// 	map->zmin = max;
		if (!is_valid_dot(&split_arr[i][0]))
			err_terminate_process(ERR_INVALID_MAP);
			
		i++;
	}
}

size_t	cal_line_len(char **split_arr)
{
	size_t	len;

	len = 0;
	while (split_arr[len] && split_arr[len][0] != '\n')
		len++;
	return (len);
}