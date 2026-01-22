/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:23:03 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/22 20:19:58 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

static int	atoi_loop(char *str, int base)
{
	int	digit;
	int	result;

	result = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'A' && *str <= 'Z')
			digit = *str - 'A' + 10;
		else if (*str >= 'a' && *str <= 'z')
			digit = *str - 'a' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		result = result * base + digit;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, int base)
{
	int	sign;

	if (!str)
		return (0);
	if (base < 2 || base > 32)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*(str++) == '-')
		sign = -1;
	else if (*str == '+')
		str++;
	return (atoi_loop(str, base) * sign);
}
