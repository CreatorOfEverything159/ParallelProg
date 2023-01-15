#ifndef PARALLELPROGRAMMING_ATOMIC_H
#define PARALLELPROGRAMMING_ATOMIC_H

#include <iostream>

double averageAtomicOmp(const unsigned *v, size_t n);

double averageAtomicCpp(const unsigned *v, size_t n);

#endif
