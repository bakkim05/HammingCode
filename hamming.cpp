#include "hamming.h"
#include <iostream>
#include <string>

//Hamming::Hamming()
//{

//}

std::vector<int> Hamming::stringToArray(std::string str) {
	std::vector<int> result;
	for (int i = 0; i < str.size(); i++){
		int data = str[i] - '0';
		result.push_back(data);
	}

	return result;
}

std::vector<int> Hamming::integerToArray(long long int x)
{
	std::vector <int> resultArray;
	while (true)
	{
		resultArray.insert(resultArray.begin(), x%10);
		x /= 10;
		if(x == 0)
			return resultArray;
	}
}

std::vector<int> Hamming::encode(const std::vector<int>& input, int parity){
    std::vector<int> result = extend(input);
    int n=0;
    while(std::pow(2,n)<=result.size()){
        result[int(std::pow(2,n))-1]= findNParity(result,n,parity);
        n++;
    }
    return result;
}
std::vector<int> Hamming::reduce(std::vector<int> input){
    std::vector<int> result = input;
    int max_n=0;
    while(std::pow(2,max_n+1)<result.size()){
        max_n++;
        }
    for (int n = max_n; n >= 0; n--) {
        result.erase(result.begin()+int( std::pow(2,n) )   -1  );
    }
    return result;
}

std::vector<int> Hamming::decode(std::vector<int> input, int parity){
    int error_index = findError(input,parity);
    if(error_index != -1){
            input[error_index] = !input[error_index];
    }
    std::vector<int> result = reduce(input);
    return result;
}


int Hamming::findError(std::vector<int> input, int parity){
    int error_index = -1;
    int n=0;
    while( std::pow(2,n)<input.size() ){

        if (! checkNParity(input, n, parity) ){
//            if(error_index == -1){

//                error_index = int(std::pow(2,n));

//            }
//            else{
                error_index+=int(std::pow(2,n));
//            }
        }
        n++;
    }
    return error_index;
}

std::vector<int> Hamming::extend(std::vector<int> input ){
    std::vector<int> result;
    int i = 0;
    while (i<input.size()) {
		while (isPowerOfTwo(result.size() + 1)) {
			result.push_back(0);
		}
		result.push_back(input[i]);
		i++;
	}
    return result;
}
int Hamming::findNParity(std::vector<int> input, int n , int parity){
    int step_lenght= std::pow(2,n);
    int parity_counter= parity;
    int i=step_lenght-1;
    while(i<input.size()){
        for (int j = 0; (j < step_lenght) and (j+i)<input.size(); ++j) {
            if(i+j != step_lenght-1){
            parity_counter+=input[i+j];
            }
        }
        i+=2*step_lenght;
    }

    return parity_counter%2;
}
int Hamming::checkNParity(std::vector<int> input, int n , int parity){
    int current_parity = input[int(std::pow(2,n))-1];
    return current_parity == findNParity(input,n,parity);
}

bool  Hamming::isPowerOfTwo(int x)
{
    return (x & (x - 1)) == 0;
}


void Hamming::print(std::vector<int> input){
        for (int n:input) {
            std::cout << n;
        }
        std::cout << std::endl;
}



std::vector<int> Hamming::createParityVector(std::vector<int> input2, int n , int parity){
	std::vector input = extend(input2);
    int step_lenght= std::pow(2,n);
    int parity_counter= parity;
    int i=step_lenght-1;
    for (int j = 0; j < i; ++j) {
        input[j]=9;
    }
    while(i<input.size()){
        for (int j = 0; (j < step_lenght) and (j+i)<input.size(); ++j) {
            if(i+j != step_lenght-1){
            parity_counter+=input[i+j];
            }
        }
        for (int j = i+step_lenght; (j < i+2*step_lenght)and j<input.size(); ++j) {
            input[j]=9;//CAMBIAR POR CARACTER NEUTRO
        }
        i+=2*step_lenght;
    }
    input[int(std::pow(2,n))-1]=parity_counter%2;
    return input;
}


std::string Hamming::showAtLength(const std::string& number, int index) {
	if (number.length() > index) {
		return number.substr(index, 1);
	} else {
		return " ";
	}
}

std::string Hamming::printIf(const std::vector<int>& vector, int index) {
	if (vector.size() > index) {
		if (vector.at(index) == 9) {
			return " ";
		} else {
			return std::to_string(vector.at(index));
		}
	} else {
		return " ";
	}
}

