#include <stdio.h>
#include <string.h>
#define STRSIZE 12 // We have 12 long strings
#define LINES 1000 // We have 1000 lines

void readln(char arr[0], int *val, FILE *fptr); // Read line
void cleanstr(char arr[]); // Clean string
void forward(int dist, int *hpos); // Forward
void up(int dist, int *vpos); // Up
void down(int dist, int *vpos); // Down 

int main(void)
{
    FILE* fptr; // File pointer
    fptr = fopen("input.txt", "r"); // Open file read only
    unsigned char str[STRSIZE]; // Create an array that can store our string
    int val = 0; // Store value associated to command

    // Tracking position of submarine
    int hpos = 0;
    int vpos = 0;

    for (int i = 0; i < LINES; i++) // Do this for every line
    {
        readln(str, &val, fptr); // Read a single line. we fill the str, update val, and pass fptr such that it knows what file to read.
        printf("%s %d\n", str, val); // Prints line and value

        if (strcmp(str, "forward") == 0)
        {
            forward(val, &hpos);
        }
        else if (strcmp(str, "up") == 0)
        {
            up(val, &vpos);
        }
        else if (strcmp(str, "down") == 0)
        {
            down(val, &vpos);
        }
        cleanstr(str); // Clear string memory
    }
    printf("Horizontal position is %d \n", hpos);
    printf("vertical position is %d \n", vpos);
    printf("Multiplied position is %lld \n", hpos * vpos);
    return 0;
}


void readln(char arr[], int *val, FILE *fptr)
{
    char c; // Store current character
    int i = 0; // Create counter
    while (i < STRSIZE)
    {
        c = getc(fptr);
        if (c >= 'a' && c <= 'z'){
            arr[i] = c;
            i++;
        }
        else if (c >= '0' && c <= '9')
        {
            *val = c - '0';
            i++;
        }
        else if (c == '\n')
        {
            arr[i] = c;
            arr[i + 1] = '\0';
            i = STRSIZE;
        }

    }
}

void cleanstr(char arr[])
{
    memset(&arr[0], 0, sizeof(char) * STRSIZE);
}

void forward(int dist, int *hpos)
{
    *hpos = *hpos + dist;
}

void up(int dist, int *vpos)
{
    *vpos = *vpos - dist;
}

void down(int dist, int *vpos)
{
    *vpos = *vpos + dist;
}