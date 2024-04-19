#pragma once

#include <future>
#include <vector>

#include "../readonly/estimate_pi.h"

// Should run 4 instances of `estimate_pi` in parallel.
// The futures may be stored as separate variables or in an array.
float estimate_pi_async(uint32_t point_count) {
    // TODO
}

// Should run `thread_count` instances of `estimate_pi` in parallel.
// The futures should be stored in an `std::vector`.
// Hint: there should be 2 loops: one for making and storing futures and one for getting the values out of the futures
float estimate_pi_async_vec(uint32_t point_count, uint32_t thread_count) {
    // TODO
}
