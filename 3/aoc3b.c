#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 1000
#define COLS 13

void read_arr(char *arr);
void print_array(char *arr, int ydim);
void count_occs(int *zeroes, int *ones, char *arr, int colnr, int ydim);
int bin2dec(long long bin);
int power(int num, int pow);
void swap_rows(char *A, int row1, int row2);
void get_ogr(char *A);

int main(void)
{
    char *A = malloc( sizeof(char) * ROWS * COLS); // Create array for reading the initial data.
    read_arr(A); // Fill array
    // print_array(A, ROWS); // Print array

    char ogr[COLS]; // Oxygen generator rating
    memset(&ogr, 0, sizeof(char) * COLS); // Clear ogr

    // We start with the oxygen generator rating. We need the following:
    /*
    - A function that counts the number of zeroes and ones in bit x of the array (count_occs does this).
    - A function that copies the numbers having the most occuring bit in place x to a separate array. This will be the input array for our next step in case this is needed.
    - A function that manages the memory for this copying.
    */

    get_ogr(A);
    print_array(A, 1);


   

    
    return 0;
}

void read_arr(char *arr)
{
    FILE* fptr; // File pointer
    fptr = fopen("input.txt", "r");

    for ( int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fscanf(fptr, "%c", &arr[i * COLS + j]);
        }

        arr[(i+1)*COLS - 1] = '\0'; 
    }
}

void print_array(char *arr, int ydim)
{
    for (int i = 0; i < ydim; i++)
    {
        printf("%3d:", i);
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", arr[i * COLS + j]);
        }
        printf("\n");
    }
}

void count_occs(int *zeroes, int *ones, char *arr, int colnr, int ydim)
{
    for (int i = 0; i < ydim; i++)
    {
        if (arr[i * COLS + colnr] == '0')
        {
            (*zeroes)++;
        }
        else if (arr[i * COLS + colnr] == '1')
        {
            (*ones)++;
        }
    }
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

void swap_rows(char *A, int row1, int row2)
{
    char tmp;
    for (int j = 0; j < COLS; j++)
    {
        tmp = A[COLS * row1 + j];
        A[COLS * row1 + j] = A[COLS * row2 + j];
        A[COLS * row2 + j] = tmp;
    }
}

void get_ogr(char *A)
{
    int ydim = ROWS;
    for (int colindex = 0; colindex < COLS - 1; colindex++) // COLS - 1 as the last character is a NULL TERMINATOR character.
    {
        int ones = 0, zeroes = 0;
        count_occs(&zeroes, &ones, A, colindex, ydim);
        if (ones >= zeroes)
        { 
            int unchecked_row = 0;
            for (int row = 0; row < ydim; row++)
            {
                if (A[row * COLS + colindex] == '1')
                {
                    swap_rows(A, unchecked_row, row);
                    unchecked_row++;
                }
            }
            ydim = ones;
        }
        else
        {
            int unchecked_row = 0;
            for (int row = 0; row < ydim; row++)
            {
                if (A[row * COLS + colindex] == '0')
                {
                    swap_rows(A, unchecked_row, row);
                    unchecked_row++;
                }
            }
            ydim = zeroes;
        }
    }
}

