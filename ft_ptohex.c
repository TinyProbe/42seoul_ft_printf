/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:28:02 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 12:48:52 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_rev(char *str, int begin, int end);
static void	_swap(char *a, char *b);

void	ptohex(t_elem *info, void *p)
{
	const char *const	hexchr = "0123456789abcdef";
	long long			pp;

	pp = (long long) p;
	if (!pp)
	{
		info->res[info->end++] = '0';
		return ;
	}
	while (pp)
	{
		info->res[info->end++] = hexchr[pp % 16];
		pp /= 16;
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
