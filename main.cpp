#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>

void writeFile(std::vector<std::string> filenames){
    std::ofstream myfile;
    const auto readme_filename = "README.md";
    myfile.open(readme_filename);
    myfile << "## Synopsis" <<"\n";
    myfile << "\n";
    myfile << "README file for current folder" << "\n";
    myfile << "\n";
    myfile << "## Contents" << "\n";
    myfile << "\n";
    for(auto& filename : filenames){
        if(filename[2] != '.'){
            myfile << filename << "\n";
            std::cout << filename << std::endl;
        }
    }
    myfile << "\n";
    myfile << "## Dependencies" << "\n";
    myfile << "\n";
    myfile << "None" << "\n";
    myfile << "\n";
    myfile << "## Version information" << "\n";
    myfile.close();
}

std::vector<std::string> grabFileNamesRecursively(std::string path){
    std::vector<std::string> filenames;
    for (auto& entry : std::filesystem::recursive_directory_iterator(path)){
        filenames.push_back(entry.path());
    }
    return filenames;
}

std::string removeFlag(std::string str){
    auto word = str.find(" ");
    if (word != std::string::npos){
        str = str.substr(word + 1);
    }
    auto it = std::find_if(str.rbegin(), str.rend(), [](char c) { return !std::isspace<char>(c, std::locale::classic()); });
    str.erase(it.base(), str.end());
    return str;
}

void performActions(std::vector<std::string> actions){
    for(auto& str : actions) {
        switch(str[0]){
            case 'p':
                str = removeFlag(str);
                auto filenames = grabFileNamesRecursively(str);
                writeFile(filenames);
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
    //auto current_executable_name = argv[0];
    std::vector<std::string> all_args;

    if (argc > 1){
        all_args.assign(argv + 1, argv + argc);
    }

    //Convert argument list into single string
    std::string argument_string;
    for(auto& str : all_args){
        argument_string += str;
        argument_string += ' ';
    }

    auto parsed_argument_list = parseArgumentString(argument_string);
    parsed_argument_list.erase(parsed_argument_list.begin());

    performActions(parsed_argument_list);


    return 0;
}
