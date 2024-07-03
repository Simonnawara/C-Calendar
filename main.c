#include <stdio.h>

int DayOfWeek(int d, int m, int y) //Function to find any day of the week based on a date
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d)
		% 7;
}

int main()
{
    //Part that takes care of the DayOfWeek function
    int dd, mm, yyyy;

    printf("Enter the date in the standard dd/mm/yyyy format \n");
    printf("Please enter your date : ");
    scanf("%d/%d/%d", &dd, &mm, &yyyy);

    int day = DayOfWeek(dd, mm, yyyy);

    switch (day) {  
        case 0 : printf("It's a Sunday"); break;
        case 1 : printf("It's a Monday"); break;
        case 2 : printf("It's a Tuesday"); break;
        case 3 : printf("It's a Wednesday"); break;
        case 4 : printf("It's a Thursday"); break;
        case 5 : printf("It's a Friday"); break;
        case 6 : printf("It's a Saturday"); break;
    }
    //End of part that takes care of the DarOfWeek function

	return 0;
}

