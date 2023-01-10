/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:42:58 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/08 09:46:21 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		needle_l;

	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	i = 0;
	needle_l = ft_strlen((char *)needle);
	while (haystack[i] && i < len - needle_l + 1)
	{
		if (ft_strncmp((char *)&haystack[i], (char *)needle, needle_l) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char haystack[] = "Foo Bar Baz";
// 	char needle[] = "Bar";
// 	char *pt = ft_strnstr(haystack, needle, 0);
// 	printf("%s\n", pt);
// }