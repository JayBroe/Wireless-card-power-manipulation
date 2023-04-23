# Wireless-card-power-manipulation

Simple programme to mainpulate the power of the wireless card.
Made for the "Network Programming" university course.

# Requirements

Linux family OS
connection to the internet required only if case of confirmation 

# Example usage
1. For the first of course, start from compiling the code:
gcc -liw ./wireless_power.c -o ./wireless_power.c

2. Example commands:

sudo ./wireless_power.c wlo1 random_power <any value, it does not matter>
-setting the power from the random value from 0 to 22 (dBm)

sudo ./wireless_power.c wlo1 toff_power <any value, it does not matter>
-turns off the card

udo ./wireless_power.c wlo1 max_power <any value>
-setting the power vaue for the chosen value
