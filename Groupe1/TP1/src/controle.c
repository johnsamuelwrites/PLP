#include <stdio.h>

/**
 * Author:    Rémi Jara
 * Created:   16/09/2024
 *
 **/

int main()
{
    for (int i = 1; i < 1001; i++)
    {
        if (i % 4 == 0 && i % 6 != 0)
        {
            printf("%d\n", i);
        }

        if (i % 2 == 0 && i % 8 == 0)
        {
            printf("%d\n", i);
        }

        if ((i % 5 == 0 || i % 7 == 0) && i % 10 != 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}