/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:16:47 by tkong             #+#    #+#             */
/*   Updated: 2022/08/08 19:13:23 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*set_info(char *format, t_elem *info);
static int	cat_arg(char *buf, int idx, va_list ap, t_elem *info);
static char	*form_calculation(va_list ap, t_elem *info);

int	ft_vfprintf(const char *format, va_list ap)
{
	char	buf[100000];
	int		idx;
	t_elem	info;

	idx = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_bzero(&info, sizeof(t_elem));
			format = (const char *) set_info(format + 1, &info);
			if (!format)
				return (-1);
			idx = cat_arg(buf, idx, ap, &info);
		}
		else
			buf[idx++] = *format++;
	}
	write(1, buf, idx);
	return (idx);
}

static char	*set_info(char *format, t_elem *info)
{
	int		idx;

	idx = 0;
	idx = scan_flag(format, idx, info);
	idx = scan_wid(format, idx, info);
	idx = scan_prec(format, idx, info);
	idx = scan_len(format, idx, info);
	idx = scan_spec(format, idx, info);
	if (!check_spec(info) || !check_flag(info) || !check_wid(info)
		|| !check_prec(info) || !check_len(info))
		return (0);
	return (format + idx);
}

static int	cat_arg(char *buf, int idx, va_list ap, t_elem *info)
{
	char	*form;

	form = form_calculation(ap, info);
	while (*form)
		buf[idx++] = *form++;
	free(form);
	return (idx);
}

static char	*form_calculation(va_list ap, t_elem *info)
{
	char	*res;
	char	*trg;

	trg = cvs_spec(ap, info);
	trg = app_prec(ap, info, trg);
	trg = app_base(ap, info, trg);
	trg = app_sign(ap, info, trg);
	if (!info->wid)
		return (trg);
}
