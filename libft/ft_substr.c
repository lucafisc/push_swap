/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:39 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/12 19:07:02 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pt;
	size_t	i;
	size_t	max_len;

	max_len = len;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= (ft_strlen(s)))
		max_len = ft_strlen(s) - start;
	pt = malloc(sizeof(char) * (max_len + 1));
	if (!pt)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		pt[i] = s[start];
		start++;
		i++;
	}
	pt[i] = '\0';
	return (pt);
}

// int main(void)
// {
// 	char str[] = "Hello eveyone";
// 	char *my_str = ft_substr(str, 50, 20);
// 	printf("%s", my_str);
// }