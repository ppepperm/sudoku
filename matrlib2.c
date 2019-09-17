/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrlib2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:33:12 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/11 16:16:14 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrlib.h"
#include <stdlib.h>

int		ft_find_free(int **src, int *row, int *coll)
{
	while (*row < 9)
	{
		while (*coll < 9)
		{
			if (src[*row][*coll] == 0)
				return (1);
			*coll += 1;
		}
		*row += 1;
		*coll = 0;
	}
	return (0);
}

int		ft_num_match(int **src, int row, int coll, int num)
{
	return (!ft_check_coll(src, coll, num)\
		&& !ft_check_row(src, row, num)\
		&& !ft_check_qadrant(src, row, coll, num));
}

void	ft_delete(int **src)
{
	free(src);
}
