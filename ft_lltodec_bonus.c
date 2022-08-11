/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltodec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:26:47 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 12:45:36 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	_rev(char *str, int begin, int end);
static void	_swap(char *a, char *b);

void	lltodec(t_elem *info, long long ll)
{
	info->neg = ((UINT64) ll & (1ull << 63) || 0);
	if (!ll)
	{
		info->res[info->end++] = '0';
		return ;
	}
	if (ll < 0)
		ll = -ll;
	while (ll)
	{
		info->res[info->end++] = ll % 10 + '0';
		ll /= 10;
	}
	_rev(info->res, info->begin, info->end);
}

static void	_rev(char *str, int begin, int end)
{
	--begin;
	while (++begin < --end)
		_swap(str + begin, str + end);
}

static void	_swap(char *a, char *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
