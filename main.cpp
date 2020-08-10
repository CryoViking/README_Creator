#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool grabFileNamesRecursively(std::string path){
    return true;
}

void performActions(std::vector<std::string> actions){
    for(auto i = actions.begin(); i != actions.end(); ++ i){
        switch((*i)[0]){
            case 'p':
                std::cout << *i << std::endl;
                const std::string& chars = "\t\n\v\f\r ";
                (*i).erase((*i).find_first_not_of(chars));
                (*i).erase((*i).find_last_not_of(chars) + 1);
                std::cout << *i << std::endl;
                //grabFileNamesRecursively();
                break;
        }
    }
}

std::vector<std::string> parseArgumentString(std::string argument_string){
    std::stringstream string_to_split(argument_string);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(string_to_split, segment, '-')){
        seglist.push_back(segment);
    }

    return seglist;
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

    std::vector<std::string> parsed_argument_list = parseArgumentString(argument_string);
    parsed_argument_list.erase(parsed_argument_list.begin());

    //for(auto i = parsed_argument_list.begin(); i != parsed_argument_list.end(); ++ i){
    //    std::cout << *i << std::endl;
    //}

    performActions(parsed_argument_list);


    return 0;
}
