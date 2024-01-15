#include <cs50.h>
#include <stdio.h>

void block(int blocks);
void pad(int padding);

int main(void)
{
    // Prompt for input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Make pyramid
    for (int i = 0; i < height; i++)
    {
        int blocks = i + 1;
        int padding = height - blocks;

        pad(padding);
        block(blocks);
        printf("  ");
        block(blocks);
        printf("\n");
    }
}

void block(int blocks)
{
    for (int i = 0; i < blocks; i++)
    {
        printf("#");
    }
}

void pad(int padding)
{
    for (int i = 0; i < padding; i++)
    {
        printf(" ");
    }
}
