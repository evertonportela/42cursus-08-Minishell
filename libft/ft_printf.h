/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:58:45 by evportel          #+#    #+#             */
/*   Updated: 2023/06/22 17:36:49 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		add_one_more(int flag);
void	ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(unsigned long nbr, int flag);
void	ft_putnbr(int nb);
void	ft_putnbr_unsigned(unsigned int nb);
void	ft_put_hex_lower(unsigned int nb);
void	ft_put_hex_upper(unsigned int nbr);

#endif