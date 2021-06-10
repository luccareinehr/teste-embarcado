// This file contains functions related to reading, sampling and averaging
// the data coming from the ACS712 current sensor

// Libraries
#include "sampling.hpp"
                                #include <stdint.h>
    #include <stdlib.h>
#include "ACS712.h"
                







        #include "ACS712_fix.hpp"

int16_t getma(ACS712 acs, uint16_t samples) {
    int16_t avg = 0;
    int32_t total = 0;  // total value
    int16_t mamp;       // value in mA

    // Capturing all samples
    for (int i = 0; i < samples; i++) {
        mamp = acs.mA_DC();  // Get data from sensor (in miliamps)
        total += mamp;       // Add current reading to total
    }

    // Divides sum of all readings by the number of samples (average)
    // and returns the absolute value
    avg = total / samples;
    if (avg >= 0) {
        return avg;
    } else
        return -avg;
}
