#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
#include <random>
#include <cmath>

auto rand_int() -> unsigned int {
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);

    auto num = dist6(rng);

    return num;
}

void delayed_print() {
    std::cout << "delayed_print start\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "delayed_print end\n";
}

// https://en.wikipedia.org/wiki/Monte_Carlo_method#Overview
float estimate_pi(uint32_t point_count) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<float> zero_to_one(0.0, 1.0);

    uint32_t inside_count = 0;
    for (size_t i = 0; i < point_count; i++) {
        auto x = zero_to_one(rng);
        auto y = zero_to_one(rng);

        auto distance = sqrtf(x * x + y * y);

        if (distance <= 1.0f) {
            inside_count++;
        }
    }

    return (float)inside_count / (float)point_count * 4.0f;
}


template<uint32_t ThreadCount>
float estimate_pi_async(uint32_t point_count) {
    std::future<float> pi_val_future[ThreadCount];

    for (size_t i = 0; i < ThreadCount; i++) {
        pi_val_future[i] = std::async(estimate_pi, point_count / ThreadCount);
    }

    auto pi = 0.0f;

    for (size_t i = 0; i < ThreadCount; i++) {
        pi += pi_val_future[i].get();
    }

    pi /= ThreadCount;

    return pi;
}
