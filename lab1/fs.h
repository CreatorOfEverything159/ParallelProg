#ifndef PARALLELPROGRAMMING_FS_H
#define PARALLELPROGRAMMING_FS_H

#include <iostream>

double averageFsOmp(const unsigned *v, size_t n);

double averageFsCpp(const unsigned *v, size_t n);

double averageAlignedOmp(const unsigned *v, size_t n);

double averageAlignedCpp(const unsigned *v, size_t n);

#endif
