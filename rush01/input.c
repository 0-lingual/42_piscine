/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yeonwkan < yeonwkan@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:52:53 by jinhole2          #+#    #+#             */
/*   Updated: 2023/02/19 15:34:21 by  yeonwkan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*make_array(char *str, int size)
{
	int	*ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ret = (int *)malloc(sizeof(int) * (size * 4));
	while (j < size * 8 - 1)
	{
		if (str[j] >= '1' && str[j] <= size + '0')
		{
			ret[i] = str[j] - '0';
			i++;
		}
		else
			return (0);
		j += 2;
	}
	if (str[j - 1] != 0)
		return (0);
	return (ret);
}

int	*input_check(char *str, int *size)
{
	int		i;
	int		word_size;

	word_size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			i++;
			word_size++;
		}
		if (str[i] != ' ')
			break ;
		i++;
	}
	if (word_size % 4 == 0)
		*size = word_size / 4;
	else
		return (0);
	return (make_array(str, *size));
}
