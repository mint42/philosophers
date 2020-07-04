#include "error.h"
#include "utils.h"
#include <sys/time.h>
#include <limits.h>
#include <stddef.h>

unsigned int	util_tod(void)
{
	struct timeval	t;
	double			r;
	double			x;

	if (gettimeofday(&t, NULL) != 0)
		return (0);
	r = (t.tv_sec * 1000) + (t.tv_usec / 1000.0);
	x = (double)INT_MAX;
	while (r - x > (double)INT_MAX)
	{
		r = r - x;
		x = x + INT_MAX;
	}
	return ((unsigned int)r);
}

int				util_atoui(unsigned int *ui, const char *a)
{
	unsigned long int	tmp;

	tmp = 0;
	if (!a)
		return (ERROR);
	while (*a >= '0' && *a <= '9')
	{
		tmp = (tmp * 10) + ((*a) - 48);
		if (tmp > UINT_MAX)
			return (ERROR);
		++a;
	}
	if (*a)
		return (ERROR);
	*ui = tmp;
	return (SUCCESS);
}

void			util_uitoa(char *a, unsigned int ui, unsigned int width, unsigned int *len)
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

void			util_strcpy(char *cpy, const char *str, unsigned int *len)
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

void			util_strinit(char *str, char c, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		++i;
	}
}
