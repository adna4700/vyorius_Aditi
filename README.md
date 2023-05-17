# vyorius_Aditi

# ARCHITECTURE

Language: C

This system consists of 5 temperature sensors generating temperature readings in the pre-defined range of 19 to 35 degree celcius.
The current temperature is assumed to be mean of all 5 temperature sensors. The desired temperature is taken as an input from the user to be maintained. 
A control logic is developed such that the Cooling System is turned ON when the current temperature is greature than the desired temperature. 
Logic for the Cooling System is a simple decrement operation with a usleep().

Similar logic is developed for the Heating System.  

# DESIGN DECISION
Required multiple sensors, so decided to have random number generator. Number of senors were taken 5 which was a random decison.

Control logic- As the system should be cooling - the temperature should drop kinda linearly so had a simple decrement operation for this functionality with asome usleep()

Similar logic used for Heating System.

Userinterface is the console itself. 
