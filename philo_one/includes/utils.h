#ifndef UTILS_H
# define UTILS_H

int		util_isdigit(char c);
int		util_atoui(unsigned int *ui, const char *a);
void	util_uitoa(char *a, unsigned int ui, unsigned int width, unsigned int *len);
void	util_strcpy(char *cpy, const char *str, unsigned int *len);
void	util_strinit(char *str, char c, unsigned int len);

#endif
