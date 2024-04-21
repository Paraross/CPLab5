#pragma once

#include <functional>
#include <iostream>
#include <future>
#include <chrono>

#include "../readonly/est.h"

typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

void task3() {
    std::packaged_task<int(int)> fib(calculate_fib);
    fib(6);
    std::packaged_task<int()> fib2(std::bind(calculate_fib, 6));
    fib2();
    std::cout << fib.get_future().get() << ' ' << fib2.get_future().get();
}

void task4() {
    std::packaged_task<double()> pack_task2(calculate_sqrt2);

    std::future<double> future = pack_task2.get_future();
  
    calculate_pi();
    pack_task2();
    
    std::cout << future.get();

}

void task5() {
    auto start = HRC::now();

    std::packaged_task<double()> pack_task1(calculate_pi);
    std::packaged_task<double()> pack_task2(calculate_sqrt2);

    std::future<double> future1 = pack_task1.get_future();
    std::future<double> future2 = pack_task2.get_future();

    std::thread thread_pi(std::move(pack_task1));
    std::thread thread_e(std::move(pack_task2));

    double result1 = future1.get();
    double result2 = future2.get();

    thread_pi.join();
    thread_e.join();

    auto end = HRC::now();
    auto exec_time = std::chrono::duration_cast<MSEC>(end - start);

    std::cout << result1 << ' ' << result2 << ' ' << exec_time.count() << " <- Notice how these values were printed all at once.\n";

    start = HRC::now();
    std::cout << calculate_pi() << ' ' << calculate_sqrt2() << ' ';
    end = HRC::now();
    exec_time = std::chrono::duration_cast<MSEC>(end - start); 
    std::cout << exec_time.count() << " <- Notice how these values were printed one after another.";
}
