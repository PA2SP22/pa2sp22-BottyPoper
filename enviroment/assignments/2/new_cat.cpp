/*
 * Name        : Charles Clarke
 * Description : Assigment #2
 * Sources     : FILL IN
 */
#include <string>

#include <fstream>

#include <iostream>

#include <sstream>

int main(int argc, char * argv[]) {
  if (argc == 1) {
    while (!std::cin.eof()) {
      std::string input;
      getline(std::cin, input);
      std::cout << input << std::endl;
    }
  } else {
    for (int i = 1; i < argc; i++) {
      std::ifstream fin(argv[i]);
      if (fin.fail()) {
        std::cout << "At least one file failed to open"<< std::endl;
        return 0;
      }
    }
    for (int i = 1; i < argc; i++) {
      std::string filename = argv[i];
      std::ifstream fin(filename);
      std::string input;
      while (getline(fin, input)) {
        std::cout << input << '\n';
      }
    }
  }
  return 0;
}
