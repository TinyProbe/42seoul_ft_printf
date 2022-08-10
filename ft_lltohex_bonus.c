
#include "ft_printf_bonus.h"

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
