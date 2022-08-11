/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:27:18 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 12:46:07 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_rev(char *str, int begin, int end);
static void	_swap(char *a, char *b);

void	lltohex(t_elem *info, long long ll, int up)
{
	const char	*hexchr;

	hexchr = "0123456789abcdef";
	if (up)
		hexchr = "0123456789ABCDEF";
	if (!ll)
	{
		info->res[info->end++] = '0';
		return ;
	}
	while (ll)
	{
		info->res[info->end++] = hexchr[ll % 16];
		ll /= 16;
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
