#include "push_swap.h"

void throw_error(void)
{
	ft_printf("Error");
}

int argument_is_invalid(char *str)
{
	int i;

	i = 0;
	if (ft_is_sign(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int input_is_invalid(int argc, char *argv[])
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (argument_is_invalid(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
