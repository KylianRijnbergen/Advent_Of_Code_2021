#include <stdio.h>

#define LINES 1000


int power(int num, int pow);
int bin2dec(long long bin);
long long dec2bin(int nr);
void read_input_arr(long long arr[]);
void print_arr(long long arr[], int len);

int main(void)
{
    long long bins[LINES];
    read_input_arr(bins);
    print_arr(bins, LINES);
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

void read_input_arr(long long arr[])
{
    FILE* fptr; // File pointer
    fptr = fopen("input.txt", "r"); // Open file read only
    int i = 0; // Line counter

    if (fptr)
    {
        while (fscanf(fptr, "%lld", &arr[i]) != EOF) // Read line to array as int 
        {
            i++; // Increment i
        }
        fclose(fptr);
    }
}

void print_arr(long long arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%lld\n", arr[i]);
    }
}