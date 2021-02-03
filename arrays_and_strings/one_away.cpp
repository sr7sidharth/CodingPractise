#include <iostream>
#include <string>

// given a pair of strings, determine if they are one(or zero) edits away
// there are 3 types of edits: insertion, deletion and replacement

bool one_away_different_length(std::string shorter, std::string longer){
    int i = 0, j = 0;
    while (i < shorter.length() && j < longer.length()){
            if (shorter[i] != longer[j]){
                    if (i != j){
                            return false;
                    }
                    j++;
            }else{
                    i++;
                    j++;
            }
    }
    return true;

}

// note that this can be easily modified to conform to the situation
// where one input string is larger or shorter than the other one by 
// more than 1. this just assumes that the strings input are only different by 
// 1 - either shorter or longer
bool one_away(std::string input, std::string edited_input){
        // insertion edit is only possible if the edited input
        // is larger than the original string
        if (input.length() < edited_input.length()){
            return one_away_different_length(input, edited_input);                
        }
        // deletion edit is only possible if the edited input
        // is smaller than the original string
        else if (input.length() > edited_input.length()){
            return one_away_different_length(edited_input, input);
        }
        // replacement edit is only possible if the edited input
        // is the same size as the original string
        else{
            bool is_different = false;
            for (int i = 0; i < input.length(); i++){
                    if (input[i] != edited_input[i]){
                            if (is_different){
                                    return false;
                            }
                            is_different = true;
                    }
            }
            return true;
        }
}   



int main(int argc, char* argv[]){
        if (argc != 3){
                std::cout << "ERROR";
                return 1;
        }
        std::string input = argv[1];
        std::string edit = argv[2];

        std::cout << one_away(input, edit);

        return 0;
}

