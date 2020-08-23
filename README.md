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
- `-p`: path to get filenames from (recursively).


## Contents

- ./README.md
- ./main.cpp

## Dependencies

- iostream
- sstream
- fstream
- string
- vector
- filesystem
- algorithm

## Version information

Version 2.0, tested on `Ubuntu 18.04`, `Windows 10` and `Kali Linux`.

Built with: `g++ version 9.3.0` and `cl.exe version 19.27.29111`
