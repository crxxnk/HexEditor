#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <map>
#include "hex_editor.h"

namespace utils {
  class Comparator {

  };
  bool isFileEmpty(const char* input); // works

  bool b_compare(const HxE &input, const HxE &_input); // works

  // First occurence
  // Hex
  std::pair<int, int> p_compare(const HxE &input, const HxE &_input); // works
  std::pair<int, int> p_compare(const HxE &input, const HxE &_input, unsigned int &offset); // works

  // Char
  std::pair<char, char> c_p_compare(const HxE &input, const HxE &_input); // works
  std::pair<char, char> c_p_compare(const HxE &input, const HxE &_input, unsigned int &offset); // works

  // All
  std::vector<std::pair<int, int>> a_compare(const HxE &input, const HxE &_input); // works
  std::vector<std::pair<int, int>> a_compare(const HxE &input, const HxE &_input, std::vector<unsigned int> &offset); //! I THINK IT WORKS GONNA TEST
  std::vector<std::pair<char, char>> ca_compare(const HxE &input, const HxE &_input); // works
  std::vector<std::pair<char, char>> ca_compare(const HxE &input, const HxE &_input, unsigned int &offset); // almost
}