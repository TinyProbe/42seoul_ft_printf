/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:16:47 by tkong             #+#    #+#             */
/*   Updated: 2022/08/05 15:38:23 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*set_info(char *format, t_elem *info);
idx		cat_arg(char *buf, int idx, va_list ap, t_elem *info);

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
			format = (const char *) set_info(format + 1, &info); // need check format position
			if (!format)
				return (-1);
			idx = cat_arg(buf, idx, ap, &info); // is exact length?
		}
		else if (*format == '\\')
			format = esc_process(format + 1, buf, idx++);
		else
			buf[idx++] = *format++;
	}
	write(1, buf, idx);
	return (idx);
}

char	*set_info(char *format, t_elem *info)
{
	int		idx;

	idx = 0;
	idx = scan_flag(format, idx, info);
	idx = scan_wid(format, idx, info);
	idx = scan_prec(format, idx, info);
	idx = scan_len(format, idx, info);
	idx = scan_spec(format, idx, info);
	if (!check_spec(info) || !check_flag(info) || !check_wid(info) ||
			!check_prec(info) || !check_len(info))
		return (0);
	return (format + idx);
}

idx	cat_arg(char *buf, int idx, va_list ap, t_elem *info)
{
	return (0);
}
