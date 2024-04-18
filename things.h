#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
#include <cmath>
#include <vector>

#include "estimate_pi.h"

void delayed_print() {
    std::cout << "delayed_print start\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "delayed_print end\n";
}

template<uint32_t ThreadCount>
float estimate_pi_async(uint32_t point_count) {
    std::future<float> pi_val_futures[ThreadCount];

    for (size_t i = 0; i < ThreadCount; i++) {
        pi_val_futures[i] = std::async(estimate_pi, point_count / ThreadCount);
    }

    auto pi = 0.0f;

    for (size_t i = 0; i < ThreadCount; i++) {
        pi += pi_val_futures[i].get();
    }

    pi /= ThreadCount;

    return pi;
}

float estimate_pi_async_vec(uint32_t point_count, uint32_t thread_count) {
    auto pi_val_futures = std::vector<std::future<float>>();

    for (size_t i = 0; i < thread_count; i++) {
        pi_val_futures.push_back(std::async(estimate_pi, point_count / thread_count));
    }

    auto pi = 0.0f;

    for (auto &future : pi_val_futures) {
        pi += future.get();
    }

    pi /= thread_count;

    return pi;
}
