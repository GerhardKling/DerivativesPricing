#include "Random1.h"
#include <cstdlib>
#include <cmath>

// The basic math functions should be in namespace std but aren't in VCPP6
// std but are not in VCPP6
// The following is information for compilers
#if !defined(_MSC_VER)
using namespace std;
#endif

// Irwin–Hall distribution: sum of uniform random variables (iid)
// For sufficient number of random variables, this approximates a normal distribution

double GetOneGaussianBySummation()
{
double result = 0;

    for (unsigned long j = 0; j < 12; j++)
        result += rand()/static_cast<double>(RAND_MAX);
    result -= 6; // ensures mean = 0
    return result;
}

// Box-Muller Transformation to obtain a standard normal random variable
double GetOneGaussianByBoxMuller()
{
    double result;
    double x;
    double y;
    double SizeSquared;
do
{
    x = 2.0*rand()/static_cast<double>(RAND_MAX) - 1;
    y = 2.0*rand()/static_cast<double>(RAND_MAX) - 1;
    SizeSquared = x * x + y * y;
}
while (SizeSquared >= 1.0);

result = x * sqrt(-2 * log(SizeSquared)/SizeSquared);
return result;
}

