#include <iostream>
#include <unordered_map>
#include <string>

// Given a string, determine whether it has all unique characters

bool isUnique(std::string input){
    std::unordered_map<char, int> char_count;
    for (int i = 0; i < input.length(); i++){
            if (char_count.find(input[i]) != char_count.end()){
                    return false;
            }else{
                    char_count.insert(std::make_pair(input[i], 0));
            }
    }
    return true;
}


int main(int argc, char* argv[]){
        if (argc != 2){
                std::cout << "ERROR";
                return 1;
        }

        std::string input_string = argv[1];

        std::cout << isUnique(input_string);

        return 0;
}
