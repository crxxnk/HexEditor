#include "hex_editor.h"

bool HxE::read(const char* input) {
  this->file = input;
  std::ifstream file(input, std::ios::binary);
  if(!file.is_open()) {
    std::cerr << "Couldn't open file!" << std::endl;
    return false;
  }
  std::vector<uint8_t> char_list;
  while(file.read(&this->buf, 1)) {
    char r = buf;
    static_cast<uint8_t>(r);
    // std::cout << std::left << std::setw(3) << std::hex << static_cast<uint8_t>(r) << " ";
    char_list.push_back(r);
  }
  this->v = char_list;
  file.close();
  std::cout << "File was read successfully" << std::endl;
  return true;
}

bool HxE::read(const char* input, unsigned int offset) {
  this->file = input;
  std::ifstream file(input, std::ios::binary);
  if(!file.is_open()) {
    std::cerr << "Couldn't open file!" << std::endl;
    return false;
  }
  file.seekg(offset, std::ios::beg);
  std::vector<uint8_t> char_list;
  while(file.read(&this->buf, 1)) {
    char r = buf;
    static_cast<uint8_t>(r);
    // std::cout << std::left << std::setw(3) << std::hex << static_cast<uint8_t>(r) << " ";
    char_list.push_back(r);
  }
  this->v = char_list;
  file.close();
  std::cout << "File was read successfully" << std::endl;
  return true;
}

void HxE::edit(unsigned int offset, char byte) {
  std::fstream file(this->file, std::ios::binary | std::ios::in | std::ios::out);
  if(!file.is_open()) {
    std::cerr << "Couldn't open file!" << std::endl;
    return;
  }
  unsigned int temp_offset = offset;
  file.seekp(temp_offset);
  char old;
  file.read(&old, 1);
  std::ofstream old_char("old_char.txt");
  if(!old_char.is_open()) {
    std::cerr << "Couldn't open file!" << std::endl;
    return;
  }
  old_char << old;

  std::ofstream last_offset_file("last_offset.txt");
  if(!last_offset_file.is_open()) {
    std::cerr << "Couldn't open file!" << std::endl;
    return;
  }
  last_offset_file << temp_offset;
  
  file.seekp(offset); // go to the specific byte offset

  file.write(&byte, sizeof(byte));
  file.close();
}

void HxE::display() {
  for(auto ve : this->v)
    std::cout << ve;
  std::cout << std::endl;
}

void HxE::bDisplay(bool show_base){
  if(show_base) {
    for(auto ve : this->v)
      std::cout << std::left << std::setw(3) << std::hex << std::showbase << static_cast<int>(ve) << " ";
  } else {
    for(auto ve : this->v)
      std::cout << std::left << std::setw(3) << std::hex << static_cast<int>(ve) << " ";
  }
  std::cout << std::endl;
}

void HxE::undoEdit() {
  if(utils::isFileEmpty("old_char.txt") || utils::isFileEmpty("last_offset.txt")) {
    std::cout << "Nothing to undo" << std::endl;
    return;
  }
  std::ifstream old_char("old_char.txt");
  std::ifstream last_offset("last_offset.txt");
  char old;
  unsigned int offset;
  old_char >> old;
  last_offset >> offset;
  edit(offset, old);
}