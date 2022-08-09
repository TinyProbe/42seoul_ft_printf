
#include "ft_printf_bonus.h"

void	set_arg_value(va_list ap, t_elem *info)
{
	if (info->spec & SPEC_D_OR_I)
		lltodec(info, va_arg(ap, int));
	else if (info->spec & SPEC_U)
		lltodec(info, va_arg(ap, UINT32));
	else if (info->spec & SPEC_X)
		lltohex(info, va_arg(ap, UINT32), LOWER);
	else if (info->spec & SPEC_X_UP)
		lltohex(info, va_arg(ap, UINT32), UPPER);
	else if (info->spec & SPEC_C)
		info->res[info->end++] = (char) va_arg(ap, int);
	else if (info->spec & SPEC_S)
		stores(info, va_arg(ap, const char *));
	else if (info->spec & SPEC_P)
		ptohex(info, va_arg(ap, void *));
	else if (info->spec & SPEC_PERCENT)
		info->res[info->end++] = '%';
}

static void	stores(t_elem *info, const char *s)
{
	// precision
	while (*s)
		info->res[info->end++] = *s++;
}
