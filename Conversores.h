//
// Created by Oska on 3/25/2019.
//

#ifndef CODIGOSBINARIOS_CONVERSORES_H
#define CODIGOSBINARIOS_CONVERSORES_H

#include <stdlib.h>
#include <cstdio>
#include <string>
#include <sstream>

using std::string;

class Conversores {
public:
    int binary2decimal(long long int input);
    string decimal2binarySTR(int input);
    string binary2decimalSTR(int input);
    string decimal2hexa(int input);
    string decimal2BDC(int input);
    string binary2BCD(string input);

};


#endif //CODIGOSBINARIOS_CONVERSORES_H