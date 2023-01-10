#include <stdio.h>
#include <cs50.h>
#include <string.h>

int atoi(int value, string number, int length, int power_of_ten);

int main(void){
    string get_value = get_string("Number: ");

    int subtraction_value = 48;

    int value = atoi(subtraction_value, get_value, strlen(get_value) - 1, 1);
    printf("%i\n", value);
}

int atoi(int value, string number, int length, int power_of_ten){
    if (length < 0)
    {
        return 0;
    }

    return ((number[length] - value) * power_of_ten) + atoi(value, number, length - 1, power_of_ten * 10);
}