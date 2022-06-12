#include <stdio.h>

int power(int num, int pow);
int bin2dec(long long bin);
long long dec2bin(int nr);

int main(void)
{
    long long binary = 0; // Binary number, type is long long as binary numbers are generally large.

    int base = 5;
    int exp = 3;
    printf("%d to the power %d equals %d \n", base, exp, power(base, exp));

    printf("1101 in binary is %d in decimal \n", bin2dec(1101));
    printf("13 in decimal is %d in binary \n", dec2bin(13));
    return 0;
}

int bin2dec(long long nr)
{
    int dec = 0; // Decimal number
    int i = 0; // Counter for "place" of digit
    int remainder = 0; // Track the remainder of the division

    while (nr != 0)
    {
        remainder = nr % 10;
        nr /= 10; 
        dec += remainder * power(2, i);
        i++;
    }
    return dec;
}

long long dec2bin(int nr)
{
    long long bin = 0;
    int i = 0;
    int remainder = 0;

    while (nr != 0)
    {
        remainder = nr % 2;
        nr /= 2;
        bin += remainder * power(10, i);
        i++;
    }
    return bin;
}

int power(int num, int pow) // Raises numbers to power. Only nonnegative exponents are allowed.
{
    if (pow == 0)
    {
        return 1;
    }
    if (pow == 1)
    {
        return num;
    }
    return num * power(num, pow - 1);
}