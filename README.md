# Array Operations Program

## Overview
This is a simple C program that allows users to perform various operations on an array of fixed size (`SIZE = 5`). Users can fill the array, calculate the sum and average, find the maximum and minimum values, reverse the array, sort it in ascending or descending order, and search for a specific value.

## Features
- Fill the array with user-input values.
- Display the array elements.
- Calculate the sum and average of the array elements.
- Find the maximum and minimum values in the array.
- Reverse and display the array.
- Sort the array in ascending or descending order.
- Search for a specific value in the array.

## Menu Options
When the program runs, it presents the following menu options:

- `a` - Refill the array.
- `b` - Get the sum of the array.
- `c` - Get the average of the array.
- `d` - Find the maximum value.
- `e` - Find the minimum value.
- `f` - Display the reversed array.
- `g` - Sort the array (Ascending or Descending).
- `h` - Search for a specific value.
- `i` - Exit the program.

## How to Use
1. Compile the program using a C compiler (e.g., GCC):
   ```sh
   gcc array_operations.c -o array_operations
   ```
2. Run the executable:
   ```sh
   ./array_operations
   ```
3. Follow the on-screen instructions to select different operations.
4. Enter the required values when prompted.
5. To exit the program, enter `i` in the menu.

## Functions Overview
- `void fillArray(int[])` - Allows the user to input values for the array.
- `void displayArr(int[])` - Displays the current array elements.
- `int sumArray(int[])` - Returns the sum of array elements.
- `float averageArray(int[])` - Returns the average of array elements.
- `int maxValue(int[])` - Returns the maximum value in the array.
- `int minValue(int[])` - Returns the minimum value in the array.
- `void reverseArray(int[])` - Prints the reversed array.
- `void sortArray(int[], char)` - Sorts the array in ascending (`A`) or descending (`D`) order.
- `int searchArray(int[], int)` - Searches for a value in the array and returns its index or `-1` if not found.

## Requirements
- A C compiler (GCC, MSVC, or Clang).
- Windows OS (for `gotoxy()` and `textattr()` functions which use Windows-specific headers).

## Notes
- The program uses Windows-specific functions (`gotoxy()` and `textattr()`) for console positioning and text formatting. If running on a different OS, these functions may need to be modified or removed.
- The array size is fixed (`SIZE = 5`). To change this, update the `#define SIZE` directive at the beginning of the file.

