#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <map>
#include <memory>
#include "hex_editor.h"

namespace utils {
  class Comparator {

  };
  bool isFileEmpty(const char* input);

  bool b_compare(const HxE &input, const HxE &_input);

  const HxE &s_compare(const HxE &input, const HxE &_input);

  // First occurence
  // Hex
  std::pair<int, int> p_compare(const HxE &input, const HxE &_input);
  std::pair<int, int> p_compare(const HxE &input, const HxE &_input, unsigned int &offset);

  // Char
  std::pair<char, char> c_p_compare(const HxE &input, const HxE &_input);
  std::pair<char, char> c_p_compare(const HxE &input, const HxE &_input, unsigned int &offset);

  // All
  std::vector<std::pair<int, int>> a_compare(const HxE &input, const HxE &_input);
  std::vector<std::pair<int, int>> a_compare(const HxE &input, const HxE &_input, std::vector<unsigned int> &offset);

  // Char
  std::vector<std::pair<char, char>> c_a_compare(const HxE &input, const HxE &_input);
  std::vector<std::pair<char, char>> c_a_compare(const HxE &input, const HxE &_input, std::vector<unsigned int> &offset);

  HxE* getEmptyObject() { return nullptr; }
}