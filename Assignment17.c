#include <stdio.h>

int factorial(int n) {
    int i, fact = 1;
    for(i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, i, sign = 1;
    float x, sum = 0;

    printf("Enter value of x (in radians): ");
    scanf("%f", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        int power = 2*i - 1;
        float term = sign * ( (float)pow(x, power) / factorial(power) );
        sum += term;
        sign = -sign;  // alternate signs
    }

    printf("Sum of sine series = %.5f\n", sum);

    return 0;
}
