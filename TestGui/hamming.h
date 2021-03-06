#ifndef HAMMING_H
#define HAMMING_H
#include <vector>
#include <math.h>

class Hamming
{
public:
    std::vector<int> encode(std::vector<int> input, int parity);
    std::vector<int> decode(std::vector<int> input, int parity);
    int findError(std::vector<int> input, int parity);
    void print(std::vector<int> input);
    std::vector<int> extend(std::vector<int> input );
    std::vector<int> reduce(std::vector<int> input);
    int findNParity(std::vector<int> input, int n , int parity);
    int checkNParity(std::vector<int> input, int n , int parity);
    bool isPowerOfTwo(int x);

private:


//    Hamming();

};

#endif // HAMMING_H
