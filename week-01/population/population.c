// From https://cs50.harvard.edu/x/2023/labs/1/
#include <cs50.h>
#include <stdio.h>

#define MIN_POPULATION_SIZE 9

int main(void)
{
    int start_size;
    do
    {
        start_size = get_int("Enter population size at start: ");
    }
    while (start_size < MIN_POPULATION_SIZE);

    int end_size;
    do
    {
        end_size = get_int("Enter population size at end: ");
    }
    while (end_size < start_size);

    int growth_size = start_size;
    int years = 0;
    do
    {
        int born = growth_size / 3;
        int died = growth_size / 4;
        growth_size = growth_size + born - died;
        years++;
    }
    while (growth_size < end_size);

    printf("Years: %i\n", years);
}
