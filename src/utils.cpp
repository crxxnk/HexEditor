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

bool utils::b_compare(const HxE &input, const HxE &_input) {
  std::ifstream file(input.getFile(), std::ios::binary);
  std::ifstream _file(_input.getFile(), std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return false;
  }

  char f;
  char s;

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    if(f != s)
      return false;
  }

  file.close();
  _file.close();
  return true;
}

//! First occurence
//* Hex
std::pair<int, int> utils::p_compare(const HxE &input, const HxE &_input) {
  std::ifstream file(input.getFile(), std::ios::binary);
  std::ifstream _file(_input.getFile(), std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {-1, -1};
  }

  char f;
  char s;

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    if(f != s)
      return {static_cast<int>(f), static_cast<int>(s)};
  }

  file.close();
  _file.close();

  return {-1,-1};
}

std::pair<int, int> utils::p_compare(const HxE &input, const HxE &_input, unsigned int &offset) {
  std::ifstream file(input.getFile(), std::ios::binary);
  std::ifstream _file(_input.getFile(), std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {-1, -1};
  }

  char f;
  char s;
  std::streampos cur_offset = 0;

  while (file.read(&f, 1) && _file.read(&s, 1)) {
    cur_offset = file.tellg();

    if (f != s) {
      offset = static_cast<unsigned int>(cur_offset) - 1;
      return {static_cast<int>(f), static_cast<int>(s)}; 
    }
  }
  return {-1, -1};
}

//* Char
std::pair<char, char> utils::c_p_compare(const HxE &input, const HxE &_input) {
  std::ifstream file(input.getFile(), std::ios::binary);
  std::ifstream _file(_input.getFile(), std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {'-', '-'};
  }

  char f;
  char s;

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    if(f != s)
      return {f, s};
  }

  file.close();
  _file.close();

  return {'-', '-'};
}

std::pair<char, char> utils::c_p_compare(const HxE &input, const HxE &_input, unsigned int &offset) {
  std::ifstream file(input.getFile(), std::ios::binary);
  std::ifstream _file(_input.getFile(), std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {'-', '-'};
  }

  char f;
  char s;
  std::streampos cur_offset = 0;

  while (file.read(&f, 1) && _file.read(&s, 1)) {
    cur_offset = file.tellg();

    if (f != s) {
      offset = static_cast<unsigned int>(cur_offset) - 1;
      return {f, s}; 
    }
  }
  offset = 0;
  return {'-', '-'};
}

//! All
//* Hex
std::vector<std::pair<int, int>> utils::a_compare(const HxE &input, const HxE &_input) {
  std::ifstream file(input.getFile(), std::ios::binary);
  std::ifstream _file(_input.getFile(), std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {{-1, -1}};
  }

  char f;
  char s;
  std::vector<std::pair<int, int>> diff;

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    if(f != s)
      diff.push_back({static_cast<int>(f), static_cast<int>(s)});
  }

  file.close();
  _file.close();

  if(diff.empty())
    return {{-1, -1}};
  return diff;
}

std::vector<std::pair<int, int>> utils::a_compare(const HxE &input, const HxE &_input, std::vector<unsigned int> &offset) {
  std::ifstream file(input.getFile(), std::ios::binary);
  std::ifstream _file(_input.getFile(), std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {{-1, -1}};
  }

  char f;
  char s;
  std::streampos cur_offset = 0;
  std::vector<std::pair<int, int>> diff;

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    cur_offset = file.tellg();
    if(f != s) {
      offset.push_back(static_cast<unsigned int>(cur_offset) - 1);
      diff.push_back({static_cast<int>(f), static_cast<int>(s)});
    }
  }

  file.close();
  _file.close();

  if(diff.empty())
    return {{-1, -1}};
  return diff;
}

//* Char
std::vector<std::pair<char, char>> utils::ca_compare(const HxE &input, const HxE &_input) {
  std::ifstream file(input.getFile(), std::ios::binary);
  std::ifstream _file(_input.getFile(), std::ios::binary);

  if(!file.is_open() || !_file.is_open()) {
    std::cerr << "Couldn't open file" << std::endl;
    return {{-1, -1}};
  }

  char f;
  char s;
  std::vector<std::pair<char, char>> diff;

  while(file.read(&f, 1) && _file.read(&s, 1)) {
    if(f != s)
      diff.push_back({f, s});
  }

  file.close();
  _file.close();

  if(diff.empty())
    return {{-1, -1}};
  return diff;
}

std::vector<std::pair<char, char>> utils::ca_compare(const HxE &input, const HxE &_input, unsigned int &offset) {
  
}