#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	else if (input_is_invalid(argc - 1, argv))
		throw_error();
	else
		push_swap(argc, argv);
	return (0);
}