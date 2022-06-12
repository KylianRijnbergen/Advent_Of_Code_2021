#include <stdio.h>

void read_input_arr(int arr[]);
void print_arr(int arr[], int len);
int check_larger_than_prev(int arr[], int len);
int check_larger_than_prev_3(int arr[], int len);

int main(void)
{
    int LINES = 2000; // There are 2000 numbers in our file
    int nums[LINES]; // Create int array of size 2000

    read_input_arr(nums);
    printf("There are %d numbers greater than the previous\n", check_larger_than_prev(nums, LINES));
    printf("There are %d windows greater than the previous\n", check_larger_than_prev_3(nums, LINES));
    return 0;
}

int check_larger_than_prev(int arr[], int len)
{
    int ctr = 0;
    int current = arr[0];

    for (int i = 1; i < len; i++)
    {
        if (arr[i] > current)
        {
            ctr++;
        }
        current = arr[i];
    }
    return ctr;
}

int check_larger_than_prev_3(int arr[], int len)
{
    int ctr = 0;
    int curr = 0;
    int prev = arr[0] + arr[1] + arr[2];

    for (int i = 3; i < len; i++)
    {
        curr = arr[i-2] + arr[i-1] + arr[i];
        if (curr > prev)
        {
            ctr++;
        }
        prev = curr;
    }
    return ctr;
}

void read_input_arr(int arr[])
{
    FILE* fptr; // File pointer
    fptr = fopen("input.txt", "r"); // Open file read only
    int i = 0; // Line counter

    if (fptr)
    {
        while (fscanf(fptr, "%d", &arr[i]) != EOF) // Read line to array as int 
        {
            i++; // Increment i
        }
        fclose(fptr);
    }
}

void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }
}