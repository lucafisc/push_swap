#include "libft.h"

int ft_is_space(char x)
{
	if (x == '\t' || x == '\n' || x == '\v' || x == '\f' || x == '\r' || x == ' ')
		return (1);
	else
		return (0);
}