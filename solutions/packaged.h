#pragma once

#include <functional>
#include <iostream>
#include <future>
#include <chrono>

#include "../readonly/est.h"

typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

//Task3
void task3() {
    std::packaged_task<int(int)> fi(calculate_fi);
    fi(6);
    std::packaged_task<int()> fi2(std::bind(calculate_fi, 6));
    fi2();
    std::cout << fi.get_future().get() << ' ' << fi2.get_future().get();
}

//Task4
void task4() {
    std::packaged_task<double()> packt2(calculate_sqrt2);

    std::future<double> future = packt2.get_future();
  
    calculate_pi();
    packt2();
    
    std::cout << future.get();

}

//Task5
void task5() {
    auto start = HRC::now();

    std::packaged_task<double()> packt1(calculate_pi);
    std::packaged_task<double()> packt2(calculate_sqrt2);

    std::future<double> future1 = packt1.get_future();
    std::future<double> future2 = packt2.get_future();

    std::thread threadpi(std::move(packt1)); //threadpi starts running
    std::thread threade(std::move(packt2));

    double result1 = future1.get();
    double result2 = future2.get();

    threadpi.join();
    threade.join();

    auto end = HRC::now();
    auto exec_time = std::chrono::duration_cast<MSEC>(end - start);

    std::cout << result1 << ' ' << result2 << ' ' << exec_time.count() << " <- Notice how these values were printed all at once.\n";

    start = HRC::now();
    std::cout << calculate_pi() << ' ' << calculate_sqrt2() << ' ';
    end = HRC::now();
    exec_time = std::chrono::duration_cast<MSEC>(end - start); 
    std::cout << exec_time.count() << " <- Notice how these values were printed one after another.";

}
