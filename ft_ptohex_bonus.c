
#include "ft_printf_bonus.h"

static void	_rev(char *str, int begin, int end);
static void	_swap(char *a, char *b);

void	ptohex(t_elem *info, void *p)
{
	const char	*const hexchr = "0123456789abcdef";

	if (!(long long) p)
	{
		info->res[info->end++] = '0';
		return ;
	}
	while ((long long) p)
	{
		info->res[info->end++] = hexchr[(long long) p % 16];
		(long long) p /= 16;
	}
	_rev(info->res, info->begin, info->end);
}

static void	_rev(char *str, int begin, int end)
{
	--begin;
	while (++begin < --end)
		swap(str + begin, str + end);
}

static void	_swap(char *a, char *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
