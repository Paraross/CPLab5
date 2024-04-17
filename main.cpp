#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

#include "things.h"

using namespace std::chrono;

int main()
{
    system_clock::time_point start = system_clock::now();

    // auto future = std::async(delayed_print);

    // // std::this_thread::sleep_for(milliseconds(1));
    // std::this_thread::sleep_for(microseconds(1000));

    // std::cout << "main thread\n";

    // future.get();

    // std::cout << "pi: " << estimate_pi(1e+6) << '\n';
    std::cout << "pi: " << estimate_pi_async<4>(1e+6) << '\n';

    auto end = system_clock::now();
    auto diff = duration_cast<milliseconds>(end - start).count();
    std::cout << "Total Time Taken = " << diff << "ms" << std::endl;
}
