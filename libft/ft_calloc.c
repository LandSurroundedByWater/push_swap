/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:25:11 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 14:14:20 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count && size && count > (UINT_MAX / size))
		return (0);
	ret = (malloc(count * size));
	if (ret == 0)
		return (0);
	ft_bzero (ret, count * size);
	return (ret);
}
