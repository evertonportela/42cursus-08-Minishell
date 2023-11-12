/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:12:04 by evportel          #+#    #+#             */
/*   Updated: 2023/05/27 19:56:00 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(size_t number)
{
	size_t	digit;

	if (number == 0)
		return (1);
	digit = 0;
	while (number > 0)
	{
		digit++;
		number = number / 10;
	}
	return (digit);
}

static int	flag_negative(long int number)
{
	if (number < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	unsigned int	len_digits;
	unsigned int	is_negative;
	long int		number;
	char			*string_digit;

	number = n;
	is_negative = flag_negative(number);
	if (is_negative == 1)
		number = number * (-1);
	len_digits = count_digit(number);
	string_digit = (char *) malloc((len_digits + is_negative) + 1);
	if (!string_digit)
		return (NULL);
	string_digit[len_digits + is_negative] = '\0';
	while (len_digits > 0)
	{
		len_digits--;
		string_digit[len_digits + is_negative] = number % 10 + '0';
		number = number / 10;
		if (is_negative == 1 && len_digits == 0)
			string_digit[len_digits] = '-';
	}
	return (string_digit);
}
