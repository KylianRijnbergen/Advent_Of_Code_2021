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
char * all_mem_cpy(int rows);
void copy_data_where(char *main_arr, int ydim, char *copy_arr, int col, char bitval);
void get_ogr(char *ogr, char *main_arr);

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

   get_ogr(ogr, A);
   // print_array(ogr, 490);

   

    
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
        arr[i * COLS - 1] = '\0'; // Null terminator
    }
}

void print_array(char *arr, int ydim)
{
    for (int i = 0; i < ydim; i++)
    {
        printf("%3d ", i);
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", arr[i * COLS + j]);
        }
        printf("\n");
    }
}

void count_occs(int *zeroes, int *ones, char *arr, int colnr, int ydim)
{
    for (int i = 0; i < ROWS; i++)
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

char * all_mem_cpy(int rows)
{
    char *ptr = malloc( sizeof(char) * rows * COLS);
    memset(ptr, 0, sizeof(char) * rows * COLS);
    return ptr;
}

void copy_data_where(char *main_arr, int ydim, char *copy_arr, int col, char bitval)
{
    for (int i = 0; i < ydim; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            copy_arr[i * COLS + j] = main_arr[i * COLS + j];
        }
    }
}

void get_ogr(char *ogr, char *main_arr)
{
    for (int currcol = 0; currcol < 1; currcol++)
    {
        int zeroes = 0, ones = 0;
        count_occs(&zeroes, &ones, main_arr, currcol, ROWS);
        printf("Zeroes are %d, ones are %d\n", zeroes, ones);
        if (zeroes < ones)
        {
            char *temparr = all_mem_cpy(zeroes);
            copy_data_where(main_arr, zeroes, temparr, currcol, '0');
            print_array(temparr, zeroes);
        }
    }
}