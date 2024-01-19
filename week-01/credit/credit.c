#include <cs50.h>
#include <stdio.h>

int validate_checksum(long number);
int validate_american_express(long number);
int validate_mastercard(long number);
int validate_visa(long number);

int main(void)
{
    // Prompt for input
    long num = 0;
    while (!num)
    {
    num = get_long("Number: ");
    }

    // Calculate and validate checksum
    int checksum = validate_checksum(num);

    if (checksum)
    {
        printf("INVALID\n");
        return 0;
    }

    // Check card provider rules
    if (validate_american_express(num))
    {
        printf("AMEX\n");
    }
    else if (validate_mastercard(num))
    {
        printf("MASTERCARD\n");
    }
    else if (validate_visa(num))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int validate_checksum(long number)
{
    int checksum = 0;

    // Work back through the first set of numbers, starting with
    // the penultimate digit
    long odds = number / 10;
    do
    {
        int current_digit = odds % 10;
        int multiplied = current_digit * 2;
        if (multiplied > 9)
        {
            // `multiplied` will be between 10 (5 * 2), and 18 (9 * 2).
            // i.e. first digit is always 1
            multiplied = 1 + (multiplied % 10);
        }
        checksum += multiplied;

        odds = odds / 100;
    }
    while (odds != 0);

    // Add the second set of numbers to the checksum
    long evens = number;
    do
    {
        int current_digit = evens % 10;
        checksum += current_digit;
        evens = evens / 100;
    }
    while (evens != 0);

    int checksum_modulo = checksum % 10;
    return checksum_modulo;
}

int validate_american_express(long number)
{
    // 15 digits, starts with 34 or 37
    // Examples that should pass:
    // 378282246310005
    // 371449635398431

    int firsts = number / 1e13;
    if (firsts == 34 || firsts == 37)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validate_mastercard(long number)
{
    // 16 digits, starts with 51, 52, 53, 54, or 55
    // Examples that should pass:
    // 5555555555554444
    // 5105105105105100

    int firsts = number / 1e14;
    if (firsts >= 51 && firsts <= 55)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validate_visa(long number)
{
    // 13 or 16 digits, starts with 4
    // Examples that should pass:
    // 4111111111111111
    // 4012888888881881
    // 4222222222222
    int short_form = number / 1e12;
    int long_form = number / 1e15;
    if (short_form == 4 || long_form == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
