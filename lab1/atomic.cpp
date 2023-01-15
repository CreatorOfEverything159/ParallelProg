#include <thread>
#include <vector>
#include <atomic>
#include <omp.h>
#include "../helper/threads.h"

#include "atomic.h"

double averageAtomicOmp(const unsigned *v, size_t n) {
    auto globalSum = 0U;

#pragma omp parallel shared(globalSum)
    {
        auto t = omp_get_thread_num();
        auto T = omp_get_num_threads();

        auto localSum = 0U;
        size_t nt, i0;

        if (t < n % T) {
            nt = n / T + 1;
            i0 = nt * t;
        } else {
            nt = n / T;
            i0 = nt * (n % T);
        }

        for (auto i = i0; i < nt + i0; ++i) {
            localSum += v[i];
        }
#pragma omp atomic
        globalSum += localSum;
    }

    return globalSum / (double) n;
}

double averageAtomicCpp(const unsigned *v, size_t n) {
    std::atomic<unsigned> globalSum{0};
    std::vector<std::thread> workers;

    auto worker = [&globalSum, v, n](unsigned t) {
        unsigned T = getThreadsNum();
        unsigned localSum = 0;
        size_t nt, i0;

        if (t < n % T) {
            nt = n / T + 1;
            i0 = nt * t;
        } else {
            nt = n / T;
            i0 = nt * (n % T);
        }

        for (size_t i = i0; i < nt + i0; ++i) {
            localSum += v[i];
        }

        globalSum.fetch_add(localSum, std::memory_order_relaxed);
    };

    for (unsigned t = 1; t < getThreadsNum(); ++t) {
        workers.emplace_back(worker, t);
    }
    worker(0);
    for (auto &w: workers) {
        w.join();
    }

    return globalSum / (double) n;
}
