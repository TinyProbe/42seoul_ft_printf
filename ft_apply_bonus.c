
#include "ft_printf_bonus.h"

void	apply_prec(t_elem *info)
{
	if (info->prec)
		while (info->end - info->begin < info->precis)
			info->res[--(info->begin)] = '0';
}

void	apply_base(t_elem *info)
{
	if (info->flag & FLAG_SHARP)
	{
		if (info->spec & SPEC_O)
			info->res[--(info->begin)] = '0';
		else if (info->spec & SPEC_X)
		{
			info->res[--(info->begin)] = 'x';
			info->res[--(info->begin)] = '0';
		}
		else if (info->spec & SPEC_X_UP)
		{
			info->res[--(info->begin)] = 'X';
			info->res[--(info->begin)] = '0';
		}
	}
}

void	apply_wid(t_elem *info)
{
	if (!info->wid)
		return ;
	if (info->flag & FLAG_ZERO
			&& (info->flag & (FLAG_PLUS | FLAG_SPACE) || info->neg))

}

void	apply_sign(t_elem *info)
{
	if (info->neg)
		info->res[--(info->begin)] = '-';
	else if (info->flag & FLAG_PLUS)
		info->res[--(info->begin)] = '+';
	else if (info->flag & FLAG_SPACE)
		info->res[--(info->begin)] = ' ';
}
