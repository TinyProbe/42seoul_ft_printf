/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 07:08:58 by tkong             #+#    #+#             */
/*   Updated: 2022/08/08 14:43:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define FLAG_MINUS		1
# define FLAG_PLUS		2
# define FLAG_SPACE		4
# define FLAG_SHARP		8
# define FLAG_ZERO		16

# define WID_NUM		1
# define WID_STAR		2

# define PREC_DOT		1
# define PREC_NUM		2
# define PREC_STAR		4

# define LEN_H			1
# define LEN_HH			2
# define LEN_L			4
# define LEN_LL			8
# define LEN_J			16
# define LEN_Z			32
# define LEN_T			64
# define LEN_L_UP		128

# define SPEC_D_OR_I	1
# define SPEC_U			2
# define SPEC_O			4
# define SPEC_X			8
# define SPEC_X_UP		16
# define SPEC_F			32
# define SPEC_F_UP		64
# define SPEC_E			128
# define SPEC_E_UP		256
# define SPEC_G			512
# define SPEC_G_UP		1024
# define SPEC_A			2048
# define SPEC_A_UP		4096
# define SPEC_C			8192
# define SPEC_S			16384
# define SPEC_P			32768
# define SPEC_N			65536
# define SPEC_PERCENT	131072

typedef struct s_elem
{
	unsigned int	flag;
	unsigned int	wid;
	unsigned int	prec;
	unsigned int	len;
	unsigned int	spec;
	size_t			width;
	size_t			precis;
}	t_elem;

int	ft_printf(const char *format, ...);
int	ft_vfprintf(const char *format, va_list ap);

int	scan_flag(char *form, int idx, t_elem *info);
int	scan_wid(char *form, int idx, t_elem *info);
int	scan_prec(char *form, int idx, t_elem *info);
int	scan_len(char *form, int idx, t_elem *info);
int	scan_spec(char *form, int idx, t_elem *info);
int	is_flag(int c);
int	is_wid(int c);
int	is_prec(int c);
int	is_len(int c);
int	is_spec(int c);
int	is_spec_part1(int c);
int	is_spec_part2(int c);
int	check_flag(t_elem *info);
int	check_wid(t_elem *info);
int	check_prec(t_elem *info);
int	check_len(t_elem *info);
int	check_spec(t_elem *info);
int	check_combi_minus(t_elem *info);
int	check_combi_plus(t_elem *info);
int	check_combi_space(t_elem *info);
int	check_combi_sharp(t_elem *info);
int	check_combi_zero(t_elem *info);

#endif
