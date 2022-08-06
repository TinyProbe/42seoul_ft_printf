/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:25:59 by tkong             #+#    #+#             */
/*   Updated: 2022/08/05 14:45:52 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	scan_flag(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = 0;
	while (1)
	{
		tmp = is_flag(form[idx++]);
		if (!tmp)
			break ;
		info->flag |= tmp;
	}
	return (idx);
}

int	scan_wid(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = 0;
	while (1)
	{
		tmp = is_wid(form[idx++]);
		if (!tmp)
			break ;
		info->wid |= tmp;
	}
	return (idx);
}

int	scan_prec(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = 0;
	while (1)
	{
		tmp = is_flag(form[idx++]);
		if (!tmp)
			break ;
		info->flag += tmp;
	}
	return (idx);
}

int	scan_len(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = 0;
	while (1)
	{
		tmp = is_flag(form[idx++]);
		if (!tmp)
			break ;
		info->flag += tmp;
	}
	return (idx);
}

int	scan_spec(char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = 0;
	while (1)
	{
		tmp = is_flag(form[idx++]);
		if (!tmp)
			break ;
		info->flag += tmp;
	}
	return (idx);
}
