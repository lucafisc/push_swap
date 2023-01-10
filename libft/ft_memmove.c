/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:33:31 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/07 19:54:26 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pt_d;
	unsigned char	*pt_s;

	if (!dst && !src)
		return (NULL);
	pt_d = (unsigned char *)dst;
	pt_s = (unsigned char *)src;
	if (pt_d <= pt_s)
	{
		return (ft_memcpy(pt_d, pt_s, len));
	}
	while (len > 0)
	{
		pt_d[len - 1] = pt_s[len - 1];
		len--;
	}
	return (dst);
}

// int main ()
// {
//   char s1[] = "Hello, lorem ipsum dolum amet";
//   ft_memmove(s1, s1 + 99, 1);
//   return 0;
// }