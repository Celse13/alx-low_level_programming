#include "main.h"

/**
 * largest_number - Returns the largest of three integers
 * @a: The first integer to compare
 * @b: The second integer to compare
 * @c: The third integer to compare
 *
 * This function takes three integers and returns the largest of the three.
 * If two or more integers are tied for the largest, the function returns one of them.
 *
 * Return: The largest of the three integers
 */
int largest_number(int a, int b, int c)
{
    int largest;

    // If a is the largest number
    if (a > b && a > c)
    {
        largest = a;
    }
    // If c is the largest number
    else if (a < b && c > b)
    {
        largest = c;
    }
    // If b is the largest number
    else
    {
        largest = b;
    }

    return (largest);
}

