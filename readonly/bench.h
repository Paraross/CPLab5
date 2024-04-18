#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <future>

#include "estimate_pi.h"
#include "../solutions/estimate_pi_async.h"

using namespace std::chrono;

void bench_sync(uint32_t point_count) {
    std::cout << "Benchmarking function 'estimate_pi' with " << point_count << " points\n";

    system_clock::time_point start = system_clock::now();

    std::cout << "pi: " << estimate_pi(point_count) << '\n';

    auto end = system_clock::now();
    auto diff = duration_cast<milliseconds>(end - start).count();

    std::cout << "Time taken: " << diff << "ms" << std::endl;
}


template<uint32_t ThreadCount>
void bench_async(uint32_t point_count) {
    std::cout << "Benchmarking function 'estimate_pi_async' with " << point_count << " points and " << ThreadCount << " threads\n";

    system_clock::time_point start = system_clock::now();

    std::cout << "pi: " << estimate_pi_async<ThreadCount>(point_count) << '\n';

    auto end = system_clock::now();
    auto diff = duration_cast<milliseconds>(end - start).count();

    std::cout << "Time taken: " << diff << "ms" << std::endl;
}

void bench_async_vec(uint32_t point_count, uint32_t thread_count) {
    std::cout << "Benchmarking function 'estimate_pi_async_vec' with " << point_count << " points and " << thread_count << " threads\n";

    system_clock::time_point start = system_clock::now();

    std::cout << "pi: " << estimate_pi_async_vec(point_count, thread_count) << '\n';

    auto end = system_clock::now();
    auto diff = duration_cast<milliseconds>(end - start).count();

    std::cout << "Time taken: " << diff << "ms" << std::endl;
}
