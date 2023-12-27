# CSearch CLI Tool
## Overview
**CSearch** is a lightweight command-line utility built with C, offering basic grep-like functionality with a focus on simplicity and efficiency. The tool allows users to search for keywords within files, providing highlighted text results for enhanced readability.

## Table of Contents
* [Features]()
* Getting Started
    * Prerequisities
    * Installation
* Usage
    * Options
* Examples
* Contributing
* License

## Features
* Keyword Search: Locate words or phrases within files.
* File Highlighting: Highlighted text results for easy identification.
* Efficient Codebase: Built in C for optimal performance and minimal resource usage.

## Getting Started
### Prerequisites
* GNU/Linux system
* GCC compiler
### Installation
1. Clone the repository:

```bash
git clone https://github.com/your-username/csearch.git
```

2. Compile the source code:

```bash
cd csearch
gcc -o csearch main.c
```

## Usage
### Options
`-f`, `--file` FILE: Specify the filename from which you want to search.


`-w`, `--word` WORD: Specify the word you want to search.


`-h`, `--help`: Display help about the flags and usage.


`-v`, `--version`: Display the version of the tool currently installed.


## Examples
Search for the word "example" in the file "sample.txt":

```bash
csearch -f sample.txt -w example
```
Perform a case-insensitive search for the word "error" in the file "log.txt":

```bash
csearch -f log.txt -w error
```

## Contributing
Contributions are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue or submit a pull request.

## License
This project is licensed under the MIT License.

###### Happy Searching in C! 🚀




