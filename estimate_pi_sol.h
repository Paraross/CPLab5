#pragma once

#include <random>
#include <future>

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

float estimate_pi_async(uint32_t point_count) {
    std::future<float> pi_val_future[4];

    for (size_t i = 0; i < 4; i++) {
        pi_val_future[i] = std::async(estimate_pi, point_count / 4);
    }

    auto pi = 0.0f;

    for (size_t i = 0; i < 4; i++) {
        pi += pi_val_future[i].get();
    }

    pi /= 4;

    return pi;
}
