#include <iostream>
#include <string>
#include <algorithm>

// Given two strings, determine if one is the permutation of the other


bool check_permutation(std::string input1, std::string input2){
    if (input1.length() != input2.length()){
            return false;
    }

    std::sort(input1.begin(), input1.end());
    std::sort(input2.begin(), input2.end());

    return (input1.compare(input2) == 0);

}

int main(int argc, char* argv[]){
        if (argc != 3){
                std::cout << "ERROR";
                return 1;
        }

        std::string input_string_1 = argv[1];
        std::string input_string_2 = argv[2];

        std::cout << check_permutation(input_string_1, input_string_2);
        return 0;
}
