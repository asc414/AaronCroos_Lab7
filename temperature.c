//temperature.c
/*
Author: Aaron Croos
KUID: 3047275
Creation Date: 03/27/2025
Name: temperature
Purpose: converts temperatures and advises
Colloborators: None
Other Sources: None
*/
#include<stdio.h>

float celsius_to_fahrenheit(float celsius){ //Converts celsius to fahrenheit
    float F = ((celsius * 9) / 5) + 32;
    return F;
}
float fahrenheit_to_celsius(float fahrenheit){ //Converts fahrenheit to celsius
    float C = ((fahrenheit-32) * 5)/9;
    return C;
}
float celsius_to_kelvin(float celsius){ //Converts celsius to kelvin
    float K = celsius + 273.15;
    return K;
}
float kelvin_to_celsius(float kelvin){ //Converts kelvin to celsius
    float C = kelvin - 273.15;
    return C;
}

void categoorize_temperature(float celsius){ //Gives recommendatios for outdoor activities based on what range the given temperature lies in
    if (celsius < 0){
        printf("Below freezing, stay inside\n");
    } else if (celsius >= 0 && celsius < 10){
        printf("Cold, wear a jacket\n");
    } else if (celsius >= 10 && celsius < 25){
        printf("Comfortable weather. Go outside\n");
    } else if (celsius >= 25 && celsius < 35){
        printf("Hot, drink lots of water\n");
    } else if (celsius >= 35){
        printf("Extreme heat, stay cool and indoors\n");
    }
}

int main(){

    float temp; //Declares temp float
    int temp_scale; //Declares scale int
    int temp_target; //Declares target int

    do { //Loops asking the user for values until they enter all three correctly
        printf("Enter the temperature value: ");
        scanf("%f", &temp);
        printf("Choose the temperature scale of the input value (1.Fahrenheit, 2. Celsius, or 3. Kelvin): ");
        scanf("%d", &temp_scale);
        printf("Choose the conversion target (1.Fahrenheit, 2. Celsius, or 3. Kelvin): ");
        scanf("%d", &temp_target);
        if (temp_scale == 3 && temp < 0) { //Checks if Kelvin value entered is negative
            printf("Invalid Kelvin Value\nPlease choose valid values\n");
            continue;
        } else if(temp_scale < 1 || temp_scale > 3){ //Checks if temp scale value is valid
            printf("Invalid scale. Please choose valid values\n");
            continue;
        } else if (temp_target < 1 || temp_target > 3) { //Checks if temp target value is valid
            printf("Invalid scale. Please choose valid values\n");
            continue;
        } else if(temp_scale == temp_target){ //Checks if user is trying to convert a temperature to itself
            if(temp_scale == 1){
                printf("Cannot convert Fahrenheit to Fahrenheit");
            } else if (temp_scale == 2){
                printf("Cannot convert Celsius to Celsius");
            } else if (temp_scale == 3){
                printf("Cannot convert Kelvin to Kelvin");
            }
            printf("Please choose valid values\n");
            continue;
        }
        break;

    }  while (1);

    switch (temp_target){
        float new_temp;
        case 1: //Runs case 1 if desired output temp is Fahrenheit
            if (temp_scale == 2) {
                new_temp = celsius_to_fahrenheit(temp);
                printf("New temperature: %f F\n", new_temp);
                categoorize_temperature(fahrenheit_to_celsius(new_temp));
            } else if (temp_scale == 3){
                new_temp = kelvin_to_celsius(temp);
                new_temp = celsius_to_fahrenheit(new_temp);
                printf("New temperature: %f F\n", new_temp);
                categoorize_temperature(fahrenheit_to_celsius(new_temp));
            }
            break;

        case 2: //Runs case 2 if desired output temp is Celsius
            if (temp_scale == 1) {
                new_temp = fahrenheit_to_celsius(temp);
                printf("New temperature: %f C\n", new_temp);
                categoorize_temperature(new_temp);
            } else if (temp_scale == 3){
                new_temp = kelvin_to_celsius(temp);
                printf("New temperature: %f C\n", new_temp);
                categoorize_temperature(new_temp);
            }
            break;
            
        case 3: //Runs case 3 if desired output temp is Kelvin
            if (temp_scale == 1) { //Converts fahrenheit to celsius then celsius to kelvin
                new_temp = fahrenheit_to_celsius(temp);
                new_temp = celsius_to_kelvin(new_temp);
                printf("New temperature: %f K\n", new_temp);
                categoorize_temperature(kelvin_to_celsius(new_temp));
            } else if (temp_scale == 2){
                new_temp = celsius_to_kelvin(temp);
                printf("New temperature: %f K\n", new_temp);
                categoorize_temperature(kelvin_to_celsius(new_temp));
            }
            break;

    }

    return 0;

}