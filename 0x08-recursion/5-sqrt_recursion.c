/**
 * _sqrt_recursion - return natural square root of a number
 * @n: no for which natural square root should be returned
 *
 * Return: natural square root n(success) else return -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (number(1, n));
}
