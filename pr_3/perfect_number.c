#include <stdio.h>

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
    int nb = horn();
    int sum = 0;
    int perfect = 0;
    int sqrt = 0;
    int cube = 0;
    int count = 1;

    while (count <= (nb + 1) / 2)
    {
        if (nb % count == 0)
            sum += count;
        if (count * count == nb)
            sqrt = 1;
        if (count * count * count == nb)
            cube = 1;
        count++;
    }

    if (sum == nb)
        perfect = 1;
    if (perfect == 1)
        printf("P");
    if (sqrt == 1)
        printf("C");
    if (cube == 1)
        printf("K");
}