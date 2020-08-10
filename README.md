## Synopsis

Instructions and information about this repository.  

## Installation
```
git clone https://github.com/CryosisOS/README_Creator
cd README_Creator
g++ main.cpp -o readme_creator -std=c++17 -lstdc++fs
```
Feel free to add to your path for your respective OS if you want to use it as a command line tool.  

## Usage

```
readme_creator -p path/to/directory/to/read/from
```

FLAGS:
- ``-p``: path to get filenames from (recursively).


## Contents

./README.md  
./main.cpp  

## Dependencies

iostream  
sstream  
fstream  
string  
vector  
filesystem  
algorithm  

## Version information

Version 1.0  
Tested on ``Ubuntu 18.04`` both native and in WSL.  
Built with: ``gcc version 8.4.0``  
