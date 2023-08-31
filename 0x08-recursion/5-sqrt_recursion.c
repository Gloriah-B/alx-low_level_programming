int actual_sqrt_recursion(int n, int i);

/**
 * _sqrt_recursion - function returns natural square root of a number
 * @n: number to calculate the square root
 *
 * Return: the square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (actual_sqrt_recursion(n, 0));
}

/**
 * actual_sqrt_recursion - recurses to find the natural square root of a number
 * @n: number to calculate the sqaure root
 * @j: iterator
 *
 * Return: square root of the number
 */
int actual_sqrt_recursion(int n, int j)
{
	if (j * j > n)
		return (-1);
	if (j * j == n)
		return (j);
	return (actual_sqrt_recursion(n, j + 1));
}
