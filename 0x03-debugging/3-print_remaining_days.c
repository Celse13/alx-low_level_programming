#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - prints the number of days remaining in the year
* for a given date, taking leap years into account
* @month: month (1-12)
* @day: day of the month (1-31)
* @year: year (four digits)
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
// Check if the year is a leap year
if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0))
{
// If it is a leap year and it is after February 29th, add one day to account for the leap year
if (month > 2 && day >= 60)
{
day++;
}

// Print the day of the year and the number of remaining days
printf("Day of the year: %d\n", day);
printf("Remaining days: %d\n", 366 - day);
}
else
{
// If it is not a leap year, print the day of the year and the number of remaining days accordingly
if (month == 2 && day == 60)
{
// Handle the case of an invalid date (February 30th)
printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
}
else
{
printf("Day of the year: %d\n", day);
printf("Remaining days: %d\n", 365 - day);
}
}
}

