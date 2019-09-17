/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:13:22 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/11 22:17:10 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "matrlib.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_solve_sudoku(int **src)
{
	int coll;
	int row;
	int num;

	row = 0;
	num = 1;
	if (!ft_find_free(src, &row, &coll))
		return (1);
	while (num <= 9)
	{
		if (ft_num_match(src, row, coll, num))
		{
			src[row][coll] = num;
			if (ft_solve_sudoku(src))
				return (1);
			src[row][coll] = 0;
		}
		num++;
	}
	return (0);
}

int		ft_read_and_check(int ac, char **av, int **dst)
{
	int error_flag;

	error_flag = 1;
	if (ac == 10)
		error_flag = ft_receve_matr(av + 1, dst);
	if (error_flag)
	{
		write(1, "Error", 5);
		write(1, "\n", 2);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int **sudoku;
	int row;
	int coll;

	sudoku = ft_create_matr();
	if (!ft_read_and_check(argc, argv, sudoku))
		return (0);
	if (ft_solve_sudoku(sudoku))
	{
		row = 0;
		while (row < 9)
		{
			coll = 0;
			while (coll < 9)
			{
				ft_putchar(sudoku[row][coll] - '0');
				coll++;
			}
			write(1, "\n", 2);
			row++;
		}
	}
	else
		write(1, "Error\n", 7);
	return (0);
}
