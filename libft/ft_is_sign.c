#include "libft.h"

int	ft_is_sign(char x)
{
	if (x == '-' || x == '+')
		return (1);
	else
		return (0);
}