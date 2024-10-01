#include <stdio.h>

double power(double x, int p) {
    double result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    double x = 1.4142;
    for (int p = 2; p <= 100; p++) {
        if (prime(p)) {
            printf("%d, %.4f^%d = %.6f\n", p, x, p, power(x, p));
        }
    }
    return 0;
}

