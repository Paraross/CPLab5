#pragma once

#include <future>
#include <vector>

#include "../readonly/estimate_pi.h"

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
