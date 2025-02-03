#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define SIZE 5
COORD coord;

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

int *ptr;

void displayArr(int[]);
void fillArray(int[]);
int sumArray(int[]);
float averageArray(int[]);
int maxValue(int[]);
int minValue(int[]);
void reverseArray(int[]);
void sortArray(int[], char);
int searchArray(int[], int);

int main()
{
    textattr(14);
    printf("Hello In Array Operation Choices!\n");
    printf("====================================\n");
    int arr[SIZE];
    int filled = 0;
    char choice;

    do
    {
        if (!filled)
        {
            fillArray(arr);
            filled = 1;
        }

        printf("\nMenu:\n");
        printf("a. Refill array\n");
        printf("b. Get sum of array\n");
        printf("c. Get average of array\n");
        printf("d. Get max value\n");
        printf("e. Get min value\n");
        printf("f. Print reversed array\n");
        printf("g. Sort array (A for Asc, D for Desc)\n");
        printf("h. Search for a specific value\n");
        printf("i. Exit\n");
        printf("======================\n");
        printf("Please enter your choice\n");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            fillArray(arr);
            displayArr(arr);
            break;
        case 'b':
            printf("Sum = %d\n", sumArray(arr));
            break;
        case 'c':
            printf("Average = %.2f\n", averageArray(arr));
            break;
        case 'd':
            printf("Max value = %d\n", maxValue(arr));
            break;
        case 'e':
            printf("Min value = %d\n", minValue(arr));
            break;
        case 'f':
            reverseArray(arr);
            break;
        case 'g':
        {
            char order;
            printf("Enter (A) for Ascending, (D) for Descending: ");
            scanf(" %c", &order);
            sortArray(arr, order);
            displayArr(arr);
            break;
        }
        case 'h':
        {
            int key;
            printf("Enter value to search: ");
            scanf("%d", &key);
            int index = searchArray(arr, key);
            if (index != -1)
                printf("Value found at index %d\n", index);
            else
                printf("Value not found.\n");
            break;
        }
        case 'i':
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
            break;
        }
    }
    while (choice != 'i');

    return 0;
}

void displayArr(int arr[])
{
    ptr=arr;
    printf("{");
    for (int i = 0; i < SIZE; i++ , ptr++)
    {
        printf(" %d", *ptr);
        if (i < SIZE - 1) printf(",");
    }
    printf(" }\n");
}

void fillArray(int arr[])
{
    ptr=arr;
    printf("Please fill the array first!\n");
    for (int i = 0; i < SIZE; i++ , ptr++)
    {
        printf("Enter value for index %d: ", i + 1);
        scanf("%d", ptr);
    }
    displayArr(arr);
}

int sumArray(int arr[])
{
    ptr=arr;
    int sum = 0;
    for (int i = 0; i < SIZE; i++ , ptr++)
        sum += *ptr;
    return sum;
}

float averageArray(int arr[])
{
    return (float)sumArray(arr) / SIZE;
}

int maxValue(int arr[])
{
    ptr=arr;
    int max = arr[0];
    for (int i = 1; i < SIZE; i++ , ptr++)
        if (*ptr > max)
            max = *ptr;
    return max;
}

int minValue(int arr[])
{
    ptr=arr;
    int min = arr[0];
    for (int i = 1; i < SIZE; i++ , ptr++)
        if (*ptr < min)
            min = *ptr;
    return min;
}

void reverseArray(int arr[])
{
    ptr=arr+SIZE-1;
    printf("Reversed Array:\n{");
    for (int i = SIZE - 1; i >= 0; i-- , ptr--)
    {
        printf(" %d", *ptr);
        if (i > 0) printf(",");
    }
    printf(" }\n");
}

void sortArray(int arr[], char order)
{
    ptr = arr;
    for (int i = 0; i < SIZE - 1; i++ )
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if ((order == 'A' || order == 'a') && *(arr + i) > *(arr + j))
            {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
            else if ((order == 'D' || order == 'd') && *(arr + i) < *(arr + j))
            {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int searchArray(int arr[], int key)
{
    ptr=arr;
    for (int i = 0; i < SIZE; i++ , ptr++)
    {
        if (*ptr == key)
            return i;
    }
    return -1;
}
