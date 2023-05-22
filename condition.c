/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhole2 <jinhole2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:52:44 by jinhole2          #+#    #+#             */
/*   Updated: 2023/02/19 12:52:46 by jinhole2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_overlap(int *arr, int index)
{
	int	i;

	i = 0;
	while (i < index % 4)
	{
		if (arr[(index / 4) * 4 + i] == arr[index])
			return (0);
		i++;
	}
	i = 0;
	while (i < index / 4)
	{
		if (arr[(i * 4) + index % 4] == arr[index])
			return (0);
		i++;
	}
	return (1);
}

int	check_condition_left(int *arr, int *cond, int index)
{
	int	i;
	int	max;
	int	cnt;

	cnt = 0;
	max = -1;
	i = 0;
	while (i < index % 4 + 1)
	{
		if (arr[(index / 4) * 4 + i] > max)
		{
			cnt++;
			max = arr[(index / 4) * 4 + i];
		}
		i++;
	}
	return (cond[index / 4 + 8] >= cnt);
}

int	check_condition_up(int *arr, int *cond, int index)
{
	int	i;
	int	max;
	int	cnt;

	cnt = 0;
	max = -1;
	i = 0;
	while (i < index / 4 + 1)
	{
		if (arr[(i * 4) + index % 4] > max)
		{
			cnt++;
			max = arr[(i * 4) + index % 4];
		}
		i++;
	}
	return (cond[index % 4] >= cnt);
}

int	check_condition_right(int *arr, int *cond, int index)
{
	int	i;
	int	max;
	int	cnt;

	cnt = 0;
	max = -1;
	i = 3;
	while (i >= 0)
	{
		if (arr[(index / 4) * 4 + i] > max)
		{
			cnt++;
			max = arr[(index / 4) * 4 + i];
		}
		i--;
	}
	return (cond[index / 4 + 12] == cnt);
}

int	check_condition_down(int *arr, int *cond, int index)
{
	int	i;
	int	max;
	int	cnt;

	cnt = 0;
	max = -1;
	i = 3;
	while (i >= 0)
	{
		if (arr[(i * 4) + index % 4] > max)
		{
			cnt++;
			max = arr[(i * 4) + index % 4];
		}
		i--;
	}
	return (cond[index % 4 + 4] == cnt);
}
