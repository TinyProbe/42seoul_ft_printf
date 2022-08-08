/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:25:59 by tkong             #+#    #+#             */
/*   Updated: 2022/08/08 12:50:58 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	scan_flag(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_flag(form[idx++]);
	while (tmp)
	{
		info->flag |= tmp;
		tmp = is_flag(form[idx++]);
	}
	return (idx - 1);
}

int	scan_wid(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_wid(form[idx++]);
	while (tmp)
	{
		info->wid |= tmp;
		if (tmp & WID_NUM)
			info->width = info->width * 10 + (form[idx - 1] - '0');
		tmp = is_wid(form[idx++]);
	}
	return (idx - 1);
}

int	scan_prec(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_prec(form[idx++]);
	if (tmp & PREC_DOT)
	{
		info->prec |= tmp;
		tmp = is_prec(form[idx++]);
		while (tmp)
		{
			info->prec |= tmp;
			if (tmp & PREC_NUM)
				info->precis = info->precis * 10 + (form[idx - 1] - '0');
			tmp = is_prec(form[idx++]);
		}
	}
	return (idx - 1);
}

int	scan_len(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_len(form[idx++]);
	while (tmp)
	{
		info->len += tmp;
		tmp = is_len(form[idx++]);
	}
	return (idx - 1);
}

int	scan_spec(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_spec(form[idx++]);
	if (tmp)
		info->spec |= tmp;
	return (idx);
}
