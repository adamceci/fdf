/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:42:19 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/01 17:03:38 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int				ft_isspace(const char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\v' || *str == '\f' || *str == ' ')
		return (1);
	return (0);
}

static int				ft_sign(const char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (1);
	}
	else if (**str == '+')
	{
		(*str)++;
		return (0);
	}
	return (0);
}

static void				ft_check_long_limit(unsigned long long *result, int i,
											int sign)
{
	if (!sign && *result > 9223372036854775807 && i >= 19)
		*result = -1;
	if (sign && *result > 9223372036854775807 && i >= 19)
		*result = 0;
}

int						ft_atoi(const char *str)
{
	unsigned long long	result;
	int					current_digit;
	int					sign;
	int					i;

	result = 0;
	while (ft_isspace(str))
		str++;
	sign = ft_sign(&str);
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		current_digit = *str - '0';
		result = current_digit + (result * 10);
		str++;
		i++;
	}
	ft_check_long_limit(&result, i, sign);
	if (sign)
		result = -result;
	return (result);
}
