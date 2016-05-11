#include <stdio.h>
#include <stdlib.h>
#include "TutorialConfig.h" // Suck in preprocessor defines/configuration options from CMake
#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <math.h>
#endif

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = 0;
#ifdef USE_MYMATH
    outputValue = mysqrt(inputValue);
#else
    outputValue = sqrt(inputValue);
#endif
    fprintf(stdout,"The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}
