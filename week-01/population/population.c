// From https://cs50.harvard.edu/x/2023/labs/1/
#include <cs50.h>
#include <stdio.h>

#define MIN_POPULATION_SIZE 9

int main(void)
{
    // Prompt for start size
    int start;
    do
    {
        start = get_int("Enter population size at start: ");
    }
    while (start < MIN_POPULATION_SIZE);

    // Prompt for end size
    int end;
    do
    {
        end = get_int("Enter population size at end: ");
    }
    while (end < start);

    // Calculate pop growth and years taken
    int growth = start;
    int years = 0;
    while (growth < end)
    {
        int born = growth / 3;
        int died = growth / 4;
        growth = growth + born - died;
        years++;
    }

    // It takes this long
    printf("Years: %i\n", years);
}
