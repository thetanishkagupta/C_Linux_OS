#include <stdio.h>

int main()
{
    static int num = 3;
    printf("%d",num);
    if (--num)
    {
        printf("%d",num);
        main();
        printf("%d",num);
    }

    return 0;
}
