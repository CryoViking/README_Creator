#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>

void writeFile(const std::vector<std::string>& filenames){
    std::ofstream myfile{"README.md"};
    myfile << "## Synopsis" << "\n\n";
    myfile << "README file for current folder" << "\n\n";
    myfile << "## Installation" << "\n\n";
    myfile << "## Usage" << "\n\n";
    myfile << "## Contents" << "\n\n";
    for(const auto& filename : filenames){
        if(filename[2] != '.' && filename.compare("./README.md") != 0){
            myfile << filename <<"  "<< "\n";
            std::cout << filename << std::endl;
        }
    }
    myfile << "\n";
    myfile << "## Dependencies" << "\n\n";
    myfile << "None" << "\n\n";
    myfile << "## Version information" << "\n";
}

std::vector<std::string> grabFileNamesRecursively(const std::string& path){
    std::vector<std::string> filenames;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(path))
        filenames.push_back(entry.path().u8string());
    return filenames;
}

std::string removeFlag(const std::string& str){
    std::string ret;
    auto word = str.find(" ");
    if (word != std::string::npos)
        ret = str.substr(word + 1);

    auto it = std::find_if(ret.rbegin(), ret.rend(), [](char c){ return !std::isspace<char>(c, std::locale::classic()); });
    ret.erase(it.base(), ret.end());
    return ret;
}

void performActions(const std::vector<std::string>& actions){
    for(const auto& str : actions) {
        switch(str[0]){
            case 'p':
                auto filenames = grabFileNamesRecursively(removeFlag(str));
                writeFile(filenames);
                break;
        }
    }
}

std::vector<std::string> parseArgumentString(const std::string& argument_string){
    std::istringstream string_to_split{argument_string};
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(string_to_split, segment, '-'))
        seglist.push_back(segment);
    return seglist;
}

int main(int argc, const char *argv[]){
    if (argc < 2) {
        std::cerr << "Usage: prog -p <path>" << std::endl;
        return 1;
    }

    //Convert argument list into single string
    std::string argument_string;
    for (auto i{1}; i < argc; i++)
        argument_string += std::string(argv[i]) + ' ';

    auto parsed_argument_list = parseArgumentString(argument_string);
    parsed_argument_list.erase(parsed_argument_list.begin());
    performActions(parsed_argument_list);
    return 0;
}
