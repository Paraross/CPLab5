#include "estimate_pi_async.h"
#include "bench.h"

const uint32_t POINT_COUNT = (uint32_t)1e+6;
const uint32_t THREAD_COUNT = 4;

int main()
{
    bench_sync(POINT_COUNT);
    bench_async<THREAD_COUNT>(POINT_COUNT);
    bench_async_vec(POINT_COUNT, THREAD_COUNT);
}
