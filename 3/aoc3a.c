#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 1000
#define COLS 13

void read_arr(char array[ROWS][COLS]);
void print_array(char array[ROWS][COLS]);
void count_occs(int *zeroes, int *ones, char array[ROWS][COLS], int row);
void comp_g_e(char g[COLS], char e[COLS], char array[ROWS][COLS]);
int bin2dec(long long bin);
long long dec2bin(int nr);
int power(int num, int pow);

int main(void)
{
    char A[ROWS][COLS]; // Create array
    read_arr(A); // Fill array
    print_array(A); // Print array

    // We now need to write some code that checks the most common bits.

    // We do this to construct GAMMA and EPSILON
    
    //First, allocate some memory to GAMMA and EPSILON
    char GAMMA[COLS]; // Set GAMMA
    char EPSILON[COLS]; // Set EPSILON 
    memset(&GAMMA, 0, sizeof(char) * COLS); // Clear GAMMA
    memset(&EPSILON, 0, sizeof(char) * COLS); // Clear EPSILON

    // We now need to write a function that can compute the entire GAMMA and EPSILONS
    comp_g_e(GAMMA, EPSILON, A);
    printf("Gamma is %s, Epsilon is %s\n", GAMMA, EPSILON);
    
    long long gbin = 0;
    long long ebin = 0;
    gbin = atoll(GAMMA);
    ebin = atoll(EPSILON);
    
    int gdec = 0; 
    int edec = 0;
    gdec = bin2dec(gbin);
    edec = bin2dec(ebin);
    
    printf("In decimal, Gamma is %d, Epsilon is %d. The product of these 2 numbers is %lld.\n", gdec, edec, gdec*edec);
    
    return 0;
}

void read_arr(char array[ROWS][COLS])
{
    FILE* fptr; // File pointer
    fptr = fopen("input.txt", "r");
    int i = 0; // Line counter
    int j = 0; // Column counter

    for ( int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fscanf(fptr, "%c", &array[i][j]);
        }
        array[i][COLS-1] = '\0';
    }
}

void print_array(char array[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
            printf("%s\n", array[i]);
    }
}

void count_occs(int *zeroes, int *ones, char array[ROWS][COLS], int col)
{
    int zerocount = 0;
    int onecount = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if ((array[i][col]) == '0')
        {
            zerocount++;
        }
        else if ((array[i][col]) == '1')
        {
            onecount++;
        }
    }
    *zeroes = zerocount;
    *ones = onecount;
}

void comp_g_e(char g[COLS], char e[COLS], char array[ROWS][COLS])
{
    for (int i = 0; i < COLS - 1; i++) // We use cols - 1 here as the last column consists of null terminators
    {
        int zeroes = 0;
        int ones = 0;
        count_occs(&zeroes, &ones, array, i);
        if (zeroes > ones)
        {
            g[i] = '0';
            e[i] = '1';
        }
        else
        {
            g[i] = '1';
            e[i] = '0';
        }
    }
    g[COLS-1] = '\0'; // Null terminator
    e[COLS-1] = '\0'; // Null terminator
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