#include <stdio.h>
#include <stdlib.h>

int	horn()
{
	int	res;
	int	negative;
    char chr;

	negative = 1;
	res = 0;
    chr = getchar();
	if (chr == '-')
    {
        negative = -1;
        chr = getchar();
    }
	while (chr != '\n' && chr != ' ')
    {
        res = res * 10 + (chr - 48);
        chr = getchar();
    }
	return (res * negative);
}

int main(void)
{
    int nb1;
    int nb2;

    nb1 = horn();
    nb2 = horn();
    if (nb2 == 0)
    {
        printf("IMPOSSIBLE");
        return (0);
    }
    else
        printf("%d", nb1 / nb2);
    return (0);
}