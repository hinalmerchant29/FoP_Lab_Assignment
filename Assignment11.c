#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    int i;
    if(n <= 1)
        return 0;
    for(i = 2; i <= n/2; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

long int factorial(int n) {
    int i;
    long int fact = 1;
    for(i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void primeFactors(int n) {
    int i;
    printf("Prime factors: ");
    for(i = 2; i <= n; i++) {
        while(n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(num >= 0)
        printf("Square root = %.2f\n", sqrt(num));
    else
        printf("Square root not defined for negative numbers\n");

    printf("Square = %d\n", num * num);

    printf("Cube = %d\n", num * num * num);

    if(isPrime(num))
        printf("%d is a Prime number\n", num);
    else
        printf("%d is not a Prime number\n", num);

    if(num >= 0)
        printf("Factorial = %ld\n", factorial(num));
    else
        printf("Factorial not defined for negative numbers\n");

    if(num > 1)
        primeFactors(num);
    else
        printf("No prime factors");

    return 0;
}
