#include <stdio.h>

int DayOfWeek(int d, int m, int y) //Function to find any day of the week based on a date
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	int day_of_week = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d)
		% 7;
    
    return (day_of_week + 6) % 7; // Adjust to make 0 = Monday, ..., 6 = Sunday

}



int main() {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    int long_month[31]; //Array initialization for 31 day months
    for (int i = 0; i < 31; i++) {
        long_month[i] = i + 1;
    }

    int year;
    printf("Enter a valid year : ");
    scanf("%d", &year);
    
    for (int j = 0; j < 12; j++) {
        printf("\n");
        printf("%s\n", months[j]);
        printf(" Mo  Tu  We  Th  Fr  Sa  Su\n");
        printf("----------------------------\n");

                
        int firstDay = DayOfWeek(1, j + 1, year);
        int days_in_month;

        // Determine the number of days in the current month
        if (months[j] == "February") {
            // Check for leap year
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                days_in_month = 29;
            } 
            
            else 
            {
                days_in_month = 28;
            }
        } 
        
        else if (months[j] == "April" || months[j] == "June" || months[j] == "September" || months[j] == "November")
        {
            days_in_month = 30;
        } 
        
        else 
        {
            days_in_month = 31;
        }


        for(int i = 0; i < firstDay; i++) 
        {
            printf("    ");
        }

        
        for (int i = 0; i < days_in_month; i++) // Print days of the month
        {        
            printf("%3d ", long_month[i]);

            if ((firstDay + i + 1) % 7 == 0)
            {
                printf("\n");
            }
        }

        if ((firstDay + days_in_month) % 7 != 0) {
            printf("\n");
        }

    }

    return 0;
}