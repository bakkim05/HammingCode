#ifndef HAMMING_H
#define HAMMING_H
#include <vector>
#include <math.h>
#include <string>

class Hamming
{
public:
    std::vector<int> decode(std::vector<int> input, int parity);
    int findError(std::vector<int> input, int parity);
    void print(std::vector<int> input);
    std::vector<int> reduce(std::vector<int> input);
    int findNParity(std::vector<int> input, int n , int parity);
    int checkNParity(std::vector<int> input, int n , int parity);
    bool isPowerOfTwo(int x);
	std::string showAtLength(const std::string& number, int index);

	std::vector<int> integerToArray(long long int x);
	static std::string printIf(const std::vector<int>& vector, int index);



//    Hamming();

	std::vector<int> encode(const std::vector<int> &input, int parity);



	std::vector<int> createParityVector(std::vector<int> input, int n, int parity);

	std::vector<int> extend(std::vector<int> input);

	static std::vector<int> stringToArray(std::string str);
};

#endif // HAMMING_H
