#include <stdio.h>

float celsiusToFahrenheit(float c) {
    return (c * 9/5) + 32;
}

float fahrenheitToCelsius(float f) {
    return (f - 32) * 5/9;
}

int main() {
    float (*funcPtr)(float);
    float temp = 37;

    funcPtr = celsiusToFahrenheit;
    printf("Celsius to Fahrenheit: %.2f\n", funcPtr(temp));

    funcPtr = fahrenheitToCelsius;
    printf("Fahrenheit to Celsius: %.2f\n", funcPtr(temp));

    return 0;
}
