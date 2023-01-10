#include "push_swap.h"

void	fill_array(int argc, char *argv[], int *array)
{
	int	i;

	i = 0;
	while (i < (argc))
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	push_swap(int argc, char *argv[])
{
	int	*a;
	// int *b;

	a = malloc(sizeof(int) * (argc - 1));
	// b = ft_calloc(sizeof(int), (argc - 1));
	fill_array(argc - 1, argv, a);
	ft_printf("%d", a[0]);
}