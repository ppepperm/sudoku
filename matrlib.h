/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:05:51 by ppepperm          #+#    #+#             */
/*   Updated: 2019/08/11 15:35:35 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRLIB_H
# define MATRLIB_H
# include <stdlib.h>

int		**ft_create_matr(void);
int		ft_receve_matr(char **argv, int **dst);
int		ft_check_row(int **src, int row, int num);
int		ft_check_coll(int **src, int coll, int num);
int		ft_check_qadrant(int **src, int row, int coll, int num);
int		ft_find_free(int **src, int *row, int *coll);
int		ft_num_match(int **src, int row, int coll, int num);
void	ft_delete(int **src);

#endif
