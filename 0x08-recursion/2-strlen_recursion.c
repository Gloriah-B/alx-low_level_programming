/**
 * _strlen_recursion - computes length of a string recursively
 * @s: pointer to a string
 *
 * Return: integer rep. length of a string
 */

int _strlen_recursion(char *s)

{
	return (*s ? (1 + _strlen_recursion(++s)) : 0);

}
