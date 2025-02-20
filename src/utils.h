#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <map>

namespace utils {
  bool isFileEmpty(const char* input);
  bool b_compare(const char* input, const char* _input);
  std::pair<int, int> p_compare(const char* input, const char* _input);
  std::pair<std::pair<char, char>, unsigned int> po_compare(const char* input, const char* _input);
  std::pair<int, int> o_compare(const char* input, const char* _input);
}