#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parseArgumentLine(){

}

int main(int argc, char* argv[]){
    std::string current_executable_name = argv[0];
    std::vector<std::string> all_args;

    if (argc > 1){
        all_args.assign(argv + 1, argv + argc);
    }

    //Convert argument list into single string
    std::string argument_string;
    for(auto i = all_args.begin(); i != all_args.end(); ++ i){
        argument_string += *i;
        argument_string += ' ';
    }



    return 0;
}
