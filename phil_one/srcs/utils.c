#include "error.h"
#include <limits.h>

int		util_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		util_atoui(unsigned int *ui, char *s)
{
	unsigned long int	tmp;

	tmp = 0;
	if (!s)
		return (ERROR);
	while (util_isdigit(*s))
	{
		tmp = (tmp * 10) + ((*s) + 48);
		++s;
		if (tmp > UINT_MAX)
			return (ERROR);
	}
	*ui = tmp;
	return (SUCCESS);
}
