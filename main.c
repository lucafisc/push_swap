#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	else if (is_valid_input(argc - 1, argv))
		push_swap(argc - 1, argv);
	else
		throw_error();
	return (0);
}