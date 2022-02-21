#include <stdio.h>
#include <string.h>

void handleCalenderInput();
void printYearCalendar(int year);
void printMonthCalendar(int *firstDayOfMonth, int month, int year);
int dayOftheWeek(int y, int m, int d);
int noOfDaysInMonth(int month, int year);
char *getMonthName(int monthNumber);

int main()
{
    printf("\n          Welcome to Calender\n");
    int flag = 1;
    while (flag)
    {
        char input[20];
        printf("cal -> to see calendar.\n");
        printf("exit -> to exit program.\n> ");
        scanf("%s", input);

        if (!strcmp(input, "cal"))
        {
            handleCalenderInput();
        }
        else
        {
            flag = 0;
        }
    }

    return 0;
}

void handleCalenderInput()
{
    int choice, month, year;
    printf("1 - to see Calendar of month\n");
    printf("2 - to see Calendar of whole year\n> ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter Year -> ");
        scanf("%d", &year);
        printf("Enter Month -> ");
        scanf("%d", &month);
        int firstDayOfMonth = dayOftheWeek(1, 02, 2022);
        printMonthCalendar(&firstDayOfMonth, 02, 2022);
    }
    else
    {
        printf("Enter Year -> ");
        scanf("%d", &year);
        printYearCalendar(year);
    }
}

void printYearCalendar(int year)
{
    printf("          Calendar - %d\n\n", year);
    int days;

    // Index of the day from 0 to 6
    int firstDayOfMonth = dayOftheWeek(1, 1, year);

    // i loop is for months
    // j loop is for days
    for (int i = 1; i <= 12; i++)
    {
        printMonthCalendar(&firstDayOfMonth, i, year);
    }
}

void printMonthCalendar(int *firstDayOfMonth, int month, int year)
{
    int days = noOfDaysInMonth(month, year);

    // Print the current month name
    printf("\n ============== %s ==============\n\n", getMonthName(month));

    printf(" Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Printing spaces
    // here k is tracking which column at it is
    int k;
    for (k = 0; k < *firstDayOfMonth; k++)
        printf("     ");

    for (int j = 1; j <= days; j++)
    {
        printf("%5d", j);

        if (++k == 7)
        {
            k = 0;
            printf("\n");
        }
    }
    printf("\n");

    *firstDayOfMonth = k;
}

// here we are finding day of week from given date using Tomohiko Sakamoto's Algorithm
// this method gives num between 0 to 6 according to day
int dayOftheWeek(int y, int m, int d)
{
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    if (m < 3)
        y -= 1;

    return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}

int noOfDaysInMonth(int month, int year)
{

    switch (month)
    {
    case 1:
        return (31);
        break;
    case 2:
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
        break;
    case 3:
        return (31);
        break;
    case 4:
        return (30);
        break;
    case 5:
        return (31);
        break;
    case 6:
        return (30);
        break;
    case 7:
        return (31);
        break;
    case 8:
        return (31);
        break;
    case 9:
        return (30);
        break;
    case 10:
        return (31);
        break;
    case 11:
        return (30);
        break;
    case 12:
        return (31);
        break;
    }
}

char *getMonthName(int monthNumber)
{
    char *month;

    switch (monthNumber)
    {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
    }
    return month;
}