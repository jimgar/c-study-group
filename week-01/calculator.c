#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    int z = add(x, y);
    printf("%i\n", z);
}

int add(int a, int b)
{
    return a + b;
}
