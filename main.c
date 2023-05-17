/******************************************************************************

File - main.c
Purpose- A temperature monitoring that maintains a desired temperature defined 
by user taken as an input and implements a simple logic for controlling the 
temperature. 
Author- Aditi Vijay Nanaware
*******************************************************************************/


// including header files.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define HIGHER_TEMP_RANGE 30
#define LOWER_TEMP_RANGE 19

// defining function definition
int generateRandomNumber(int min, int max);
void udelay(unsigned int microseconds);

int main()
{
    // 5 temoperature values from 5 sensors
    // using random function to take 5 random values 
    // that should be in the range of - 19- 30 degree celsius;
    // take user input for desired temperature. 
    // using the control logic to virtually conrtol the cooling/heating system 
    
    while(1) // because its embedded 
    {
        srand(time(NULL));
        int start = 19.0;
        int end = 35.0;
        int user_temperature;
        
        // Generate a random integer between start and end (inclusive)
        int random_number_1 = generateRandomNumber(start, end);
        int random_number_2 = generateRandomNumber(start, end);
        int random_number_3 = generateRandomNumber(start, end);
        int random_number_4 = generateRandomNumber(start, end);
        int random_number_5 = generateRandomNumber(start, end);
        
        int mean_temp_values = ((random_number_1+random_number_2+random_number_3+random_number_4+random_number_5)/5);
        
        printf("\nCurrent_temp value from five sensors %d\n", mean_temp_values);
        
        printf("What is your desired temperature: ");
        scanf("%d", &user_temperature);
        
        // check if the user input is within the valid range which is 19-30
        
        if(user_temperature >= LOWER_TEMP_RANGE && user_temperature  <= HIGHER_TEMP_RANGE)
        {

            // check the temp value from user to start the control logic functionality
            if(mean_temp_values > user_temperature)
            {
                static int value_1;
                value_1= mean_temp_values;
                printf(" Cooling system is on \n");
                while(value_1 > user_temperature)
                {
                    // action taken from cooling system
                    //random values genrated < current, but in the valid range i.e. >=19 && <= mean_temp_values 
                    printf("\n Cooling going on.. ");
                    value_1--;
                    printf("\n Current temperature: %d ", value_1);
                    if(value_1 == user_temperature)
                    {
                        printf(" \ncurrent temperature is : %d\n",value_1);
                        printf("Cooling done \n");
                        break;
                    }
                }
            }
            else if(mean_temp_values < user_temperature)
            {
                static int value_2;
                value_2= mean_temp_values;
                printf(" Heating system is on \n");
                while(value_2 < user_temperature)
                {
                    // action taken from cooling system
                    //random values genrated < current, but in the valid range i.e. >=19 && <= mean_temp_values 
                    value_2++;
                    printf("\n Current temperature: %d ", value_2);
                    if(value_2 == user_temperature)
                    {
                        printf(" \n\n current temperature is: %d\n ",value_2);
                        printf("\n Heating done");
                        break;
                    }
                }
            }
            else
                printf("\nThe desired temperature is achieved already"); 
        }
        else
        {
                printf("\nInvalid range: Please input between 19-30 inclusive");
                break;
        }
    }

    return 0;
}

void udelay(unsigned int microseconds) 
{
    usleep(microseconds);
}

int generateRandomNumber(int min, int max) 
{
    // Add 1 to the difference between max and min
    // to include the max value in the possible range
    int range = max - min + 1;
    
    // Generate a random number within the range
    int random_number = rand() % range;
    
    // Shift the random number to the appropriate range starting from min
    random_number = random_number + min;
    
    return random_number;
}
