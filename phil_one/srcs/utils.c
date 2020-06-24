#include "error.h"
#include "utils.h"
#include <limits.h>

int		util_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		util_atoui(unsigned int *ui, const char *a)
{
	unsigned long int	tmp;

	tmp = 0;
	if (!a)
		return (ERROR);
	while (util_isdigit(*a))
	{
		tmp = (tmp * 10) + ((*a) + 48);
		if (tmp > UINT_MAX)
			return (ERROR);
		++a;
	}
	if (*a)
		return (ERROR);
	*ui = tmp;
	return (SUCCESS);
}

void	util_uitoa(char *a, unsigned int ui, unsigned int width, unsigned int *len)
{
	unsigned long long int	pow;
	unsigned int			i;

	*len = 1;
	pow = ui;
	while (pow >= 10 && ++(*len))
		pow = pow / 10;
	util_strinit(a, '0', ((width) ? width : *len));
	i = *len;
	while (i-- > 0)
	{
		a[i] = (ui % 10) + '0';
		ui = ui / 10;
	}
}

void	util_strcpy(char *cpy, const char *str, unsigned int *len)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		++i;
	}
	*len = i;
}

void	util_strinit(char *str, char c, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		++i;
	}
}

