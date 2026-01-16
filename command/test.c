int	main(void)
{
	swap();
}

void	swap_value(int *a, int *b)
{
	int	c;

	c = *a;
	a = *b;
	b = c;
}
