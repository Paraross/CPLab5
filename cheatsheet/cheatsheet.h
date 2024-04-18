#include <future>

int function1(int arg);

int function1(int arg) {
    return arg;
}

int future_array() {
    const int N = 4;

    std::future<int> futures[N];

    for (int i = 0; i < N; i++) {
        futures[i] = std::async(function1, i);
    }

    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += futures[i].get();
    }

    return sum;
}
