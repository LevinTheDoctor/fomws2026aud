#include <stdio.h>

float fahrenheit_zu_celsius(float fahrenheit)
{
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main()
{
    printf("Gebe bitte eine temperatur in fahrenheit ein:");

    float fahrenheit;
    scanf("%f", &fahrenheit);

    float celsius = fahrenheit_zu_celsius(fahrenheit);
    printf("Diene eingeben %f Fahrenheit sind %f in Celsius.", fahrenheit, celsius);

    return 0;
}