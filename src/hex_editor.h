#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdint>
#include "utils.h"

class HxE {
  char buf;
  char old;
  const char* file;
  std::vector<uint8_t> v;
public:
  bool read(const char* input);
  bool read(const char* input, unsigned int offset);
  void edit(unsigned int offset, char byte);
  void display();
  void bDisplay(bool show_base);
  void undoEdit();
};