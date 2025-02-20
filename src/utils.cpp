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

bool utils::b_compare(const char *input, const char* _input) {
  std::ifstream file(input, std::ios::binary);
  std::ifstream _file(_input, std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return false;
  }

  char f;
  char s;

  std::vector<uint8_t> char_list {};
  std::vector<uint8_t> _char_list {};

  while(file.read(&f, 1)) {
    char r = f;
    static_cast<uint8_t>(r);
    char_list.push_back(r);
  }

  while(_file.read(&s, 1)) {
    char r = s;
    static_cast<uint8_t>(r);
    _char_list.push_back(r);
  }

  file.close();
  _file.close();
  return char_list == _char_list;
}

std::pair<int, int> utils::p_compare(const char *input, const char *_input) {
  std::ifstream file(input, std::ios::binary);
  std::ifstream _file(_input, std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {-1, -1};
  }

  char f;
  char s;

  std::vector<uint8_t> char_list {};
  std::vector<uint8_t> _char_list {};

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    if(f != s)
      return {static_cast<int>(f), static_cast<int>(s)};
  }

  file.close();
  _file.close();

  return {-1,-1};
}

std::pair<std::pair<char, char>, unsigned int> utils::po_compare(const char *input, const char *_input) {
  std::ifstream file(input, std::ios::binary);
  std::ifstream _file(_input, std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {{' ', ' '}, 0};
  }

  char f;
  char s;
  unsigned int offset; //TODO MAKE OFFSET COMPARISON, CHANGE THE FUNCTION TO RETURN 2 CHARS AND 2 OFFSETS FOR EACH FILE

  std::vector<uint8_t> char_list {};
  std::vector<uint8_t> _char_list {};

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    if(f != s)
      return {{f, s}, offset};
  }

  file.close();
  _file.close();

  return {{'-','-'}, 0};
}

std::pair<int, int> utils::o_compare(const char *input, const char *_input) {
  std::ifstream file(input, std::ios::binary);
  std::ifstream _file(_input, std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {-1, -1};
  }

  char f;
  char s;
  unsigned int offset;
  unsigned int _offset;

  std::vector<uint8_t> char_list {};
  std::vector<uint8_t> _char_list {};

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    offset = static_cast<int>(file.tellg()) - 1;
    _offset = static_cast<int>(_file.tellg()) - 1;
    if(f != s)
      return {offset, _offset};
  }

  file.close();
  _file.close();

  return {-1, -1};
}