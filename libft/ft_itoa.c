/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:03:36 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/11 17:09:29 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (2);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*str_rev(char *str)
{
	char	temp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}

long int	is_negative(int n)
{
	long int	num;

	num = n;
	if (num < 0)
		return (num * (-1));
	return (num);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	num;
	int			i;
	char		*pt;

	len = get_len(n);
	num = is_negative(n);
	pt = malloc(sizeof(char) * (len));
	if (!pt)
		return (0);
	i = 0;
	while (num > 9)
	{
		pt[i++] = (num % 10) + '0';
		num = num / 10;
	}
	pt[i] = num + '0';
	if (n < 0)
		pt[++i] = '-';
	pt[++i] = '\0';
	str_rev(pt);
	return (pt);
}

// int	main(void)
// {
// 	char *pt;
// 	pt = ft_itoa(0);
// 	printf("%s\n", pt);
// }