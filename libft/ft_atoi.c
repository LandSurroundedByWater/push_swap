/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:10:47 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 10:27:04 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	converttoint(const char *str, long i)
{
	long	ret;

	ret = 0;
	while (str[i] >= 48 && str[i] <= 57)
		ret = ret * 10 + str[i] - 48;
	return (ret);
}

long	ft_atol(const char *str)
{
	long	i;
	long	neg;

	neg = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	else if (!(str[i] >= 48 && str[i] <= 57))
	{
		return (0);
	}
	return (neg * converttoint(str, i));
}
