#include <stdio.h>

int main(void)
{
    int x = 2;
    int y = x - 1;

    printf("%i\n", y);

    char my_char = 'h';
    printf("My char is %c\n", my_char);

    if (my_char)
    {
        printf("my_char is a non-null value\n");
    }
}
