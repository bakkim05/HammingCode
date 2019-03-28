//
// Created by Oska on 3/25/2019.
//

#include <iostream>
#include "ErrorDetection.h"

bool ErrorDetection::checkBinary(long long int inputNumber) {
    int j = 0;

    while (inputNumber > 0)
    {
        j = inputNumber%10;

        if ((j!= 0) and (j != 1)) {
            return false;
        }

        inputNumber = inputNumber/10;

        if (inputNumber==0) {
            return true;
        }
    }
    return true;
}

bool ErrorDetection::lengthCheck(long long int inputNumber) {
	std::cout << inputNumber << std::endl;
    if (inputNumber <= 111111111111) // 1111 1111 1111 == 2^12 en binario
    {
        return true;
    }
    return false;
}
