//
// Created by Oska on 3/25/2019.
//
#include <sstream>
#include <iostream>
#include "Conversores.h"

int Conversores::binary2decimal(long long int input) {
    long long int bin, dec = 0, rem, base = 1;

    bin = input;

    while (input > 0)
    {
        rem = input % 10;
        dec = dec + rem * base;
        base = base *2;
        input = input /10;
    }

    return dec;
}

string Conversores::decimal2hexa(int input) {

    std::stringstream ss;
    ss << std::hex << input;
    std::string output = ss.str();

    return output;
}

string Conversores::decimal2BDC(int input) {
    int rem;
    string output;

    while (input > 0){
        rem = input % 10;
        input = input / 10;

        output = binary2BCD(decimal2binarySTR(rem)) + output;
    }
    return output;
}

string Conversores::binary2decimalSTR(int input) {
    string output = std::to_string(input);

    return output;
}

string Conversores::decimal2binarySTR(int input) {
    int binaryNumber[16];
    string output;

    int i = 0;
    while (input > 0) {
        binaryNumber[i] = input%2;
        input = input / 2;
        i++;
    }
    for (int j = i -1; j >= 0; j--)
    {
        output += std::to_string(binaryNumber[j]);
    }

    return output;
}

string Conversores::binary2BCD(string input) {
    unsigned int temp = 4 - input.length();
    std::string stuff(temp,'0');

    return stuff + input;

}