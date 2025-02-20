#include "utils.h"

bool utils::isFileEmpty(const char *input) {
  std::ifstream file(input, std::ios::binary);  // Open in binary mode
  if(!file) {
    std::cerr << "Failed to open the file!" << std::endl;
    return false;
  }

  file.seekg(0, std::ios::end);

  return file.tellg() == 0;
}