/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrlib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:53:25 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/11 15:58:30 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrlib.h"
#include <stdlib.h>

int		**ft_create_matr(void)
{
	int **dst;
	int i;
	int k;

	i = 0;
	dst = (int**)malloc(sizeof(int*) * 9);
	while (i < 9)
	{
		dst[i] = (int*)malloc(sizeof(int) * 9);
		while (k < 9)
		{
			dst[i][k] = 0;
			k++;
		}
		i++;
		k = 0;
	}
	return (dst);
}

int		ft_receve_matr(char **argv, int **dst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				dst[i][j] = argv[i][j] - '0';
			else if (argv[i][j] != '.')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		ft_check_row(int **src, int row, int num)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (src[row][j] == num)
			return (1);
		j++;
	}
	return (0);
}

int		ft_check_coll(int **src, int coll, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (src[i][coll] == num)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_qadrant(int **src, int row, int coll, int num)
{
	int i;
	int j;

	row = 3 * (row / 3);
	coll = 3 * (coll / 3);
	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			if (src[row + i][coll + j] == num)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
