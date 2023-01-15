#include <thread>
#include "../helper/threads.h"
#include "../helper/tester.h"
#include "../helper/vector.h"

#include "cs.h"
#include "fs.h"
#include "average.h"
#include "atomic.h"


int main() {
    auto v = std::make_unique<unsigned[]>(N);
    fillVector(v.get(), 1U);

    std::cout << "Average (CS, OMP):" << std::endl;
    measureScalability(averageCsOmp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (CS, C++):" << std::endl;
    measureScalability(averageCsCpp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (STATIC REDUCTION, OMP):" << std::endl;
    measureScalability(averageStaticOmp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (DYNAMIC REDUCTION, OMP):" << std::endl;
    measureScalability(averageDynamicOmp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (FS, OMP):" << std::endl;
    measureScalability(averageFsOmp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (FS, C++):" << std::endl;
    measureScalability(averageFsCpp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (FS ALIGNED, OMP):" << std::endl;
    measureScalability(averageAlignedOmp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (FS ALIGNED, C++):" << std::endl;
    measureScalability(averageAlignedCpp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (ATOMIC, OMP):" << std::endl;
    measureScalability(averageAtomicOmp, v.get(), N);
    std::cout << std::endl;

    std::cout << "Average (ATOMIC, C++):" << std::endl;
    measureScalability(averageAtomicCpp, v.get(), N);
    std::cout << std::endl;

}