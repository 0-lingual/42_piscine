/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yeonwkan < yeonwkan@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:55:11 by jinhole2          #+#    #+#             */
/*   Updated: 2023/02/19 15:30:00 by  yeonwkan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		rec_skyscrapper(int *arr, int *cond, int index);
void	print_arr(int *arr);
int		check_overlap(int *arr, int index);
int		check_condition_left(int *arr, int *cond, int index);
int		check_condition_up(int *arr, int *cond, int index);
int		check_condition_right(int *arr, int *cond, int index);
int		check_condition_down(int *arr, int *cond, int index);
int		check_condition_essentials(int *arr, int *cond, int index);
int		*make_array(char *str, int size);
int		*input_check(char *str, int *size);

int	main(int argc, char **argv)
{
	int	*arr;
	int	*cond;
	int	size;

	if (argc != 2)
		return (0 * write(1, "Error\n", 6));
	cond = input_check(argv[1], &size);
	arr = (int *)malloc(sizeof(int) * (size * size));
	if (cond == 0)
		return (0 * write(1, "cond error", 10)); // suzeong
	if (rec_skyscrapper(arr, cond, 0) == 0)
		return (0 * write(1, "Error\n", 6));
	free(cond);
	free(arr);
}

void	print_arr(int *arr)
{
	int		i;
	int		j;
	char	p;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			p = arr[i * 4 + j] + '1';
			write(1, &p, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}

int	rec_skyscrapper(int *arr,int *cond, int index)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (index == 16)
	{
		print_arr(arr);
		return (1);
	}
	while (i < 4)
	{
		arr[index] = i;
		if (check_condition_essentials(arr, cond, index))
		{
			if (!(((index % 4 == 3 && !check_condition_right(arr, cond, index))) ||
				  (index / 4 == 3 && !check_condition_down(arr, cond, index))))
				if (rec_skyscrapper(arr, cond, index + 1))
					return (1);
		}
		i++;
	}
	return (0);
}

int	check_condition_essentials(int *arr, int *cond, int index)
{
	return (check_overlap(arr, index) &&
		check_condition_left(arr, cond, index) &&
		check_condition_up(arr, cond, index));
}

//지울지 말지 결정해주세요
/*
int	check_rec_valid(int *arr, int *cond, int index)
{
	if (check_condition_essentials(arr, cond, index))
	{
		if (index % 4 == 3 && !check_condition_right(arr, cond, index))
			return (0);
		if (index / 4 == 3 && !check_condition_down(arr, cond, index))
			return (0);
	}
	else
		return (0);
	return (1);
}
*/