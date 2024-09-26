
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	len = 1;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		len++;
	}
	while (n /= 10)
		len++;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}