#pragma once

double calculate_pi() {
    double sum = 0.0;
    int sign = 1;
    
    for (int i = 0; i < (int)1e+9; i++) {
        sum += sign / (2.0 * i + 1.0);
        sign *= -1;
    }
    
    return 4.0 * sum;
}

double calculate_sqrt2() {
    double x = 1.0;

    for (int i = 0; i < (int)1e+9; i++) {
        x = 0.5 * (x + 2.0 / x);
    }

    return x;
}

int calculate_fib(int n) {
    if (n <= 1) {
        return n;
    }

    return calculate_fib(n - 1) + calculate_fib(n - 2);
}