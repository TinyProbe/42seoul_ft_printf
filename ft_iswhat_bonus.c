/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:46:09 by tkong             #+#    #+#             */
/*   Updated: 2022/08/05 16:08:06 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_flag(int c)
{
	if (c == '-')
		return (FLAG_MINUS);
	if (c == '+')
		return (FLAG_PLUS);
	if (c == ' ')
		return (FLAG_SPACE);
	if (c == '#')
		return (FLAG_SHARP);
	if (c == '0')
		return (FLAG_ZERO);
	return (0);
}

int	is_wid(int c)
{
	if (c >= '0' && c <= '9')
		return (WID_NUM);
	if (c == '*')
		return (WID_STAR);
	return (0);
}

int	is_prec(int c)
{
	if (c == '.')
		return (PREC_DOT);
	if (c >= '0' && c <= '9')
		return (PREC_NUM);
	if (c == '*')
		return (PREC_STAR);
	return (0);
}

int	is_len(int c)
{
	if (c == 'h')
		return (LEN_H);
	if (c == 'l')
		return (LEN_L);
	if (c == 'j')
		return (LEN_J);
	if (c == 'z')
		return (LEN_Z);
	if (c == 't')
		return (LEN_T);
	if (c == 'L')
		return (LEN_L_UP);
	return (0);
}

int	is_spec(int c)
{
	return (is_spec_part1(c) + is_spec_part2(c));
}
