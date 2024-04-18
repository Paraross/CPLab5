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
float estimate_pi_async_vec(uint32_t point_count, uint32_t thread_count) {
    // TODO
}
