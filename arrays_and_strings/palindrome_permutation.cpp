#include <iostream>
#include <string>
#include <unordered_map>

// Given a string, find if there is a permutation which is a palindrome
bool is_palindrome_permutation(std::string input){
// Logic for this function is as follows:
// Create a map that counts the frequency of each character
// If the input string has an even number of characters,
// then all characters in the string must be repeated multiple-of-two times
// Else, if input string has an odd number of characters,
// then there has to be a character that is the "odd one out", i.e,
// one character can be repeated an odd number of times
// eg, aabbccdde can be represented as a palindrome but so can
// aabbccddeeeee
        std::unordered_map<char, int> char_count;

        for (int i = 0; i < input.length(); i++){
                if (char_count.find(input[i]) == char_count.end()){
                        char_count.insert(std::make_pair(input[i], 1));
                }else{
                        char_count.at(input[i])++;
                }
        }

        if (input.length() % 2 == 0){  // is even
                for (auto& x: char_count){
                        if (x.second % 2 != 0){
                                return false;
                        }
                }
                return true;
        }else{
                int count = 0; // count how many elements have non-even counts
                for (auto& x: char_count){
                        if (x.second % 2 != 0){
                                count++;
                        }
                }
                if (count != 1){
                        return false;
                }
                return true;
        }
}

int main(int argc, char* argv[]){
        std::cout << is_palindrome_permutation(argv[1]);
        return 0;
}
