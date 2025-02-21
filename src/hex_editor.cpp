#include "hex_editor.h"

bool HxE::read(const char *input)
{
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
  this->size = getSize();
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
  
  file.seekp(offset); // go to the specific byte offset

  file.write(&byte, sizeof(byte));

  undoStack.push({offset, old});

  while (!redoStack.empty()) {
    redoStack.pop();
  }
  file.close();
}

bool HxE::isDifferent(const HxE& other, size_t index) const {
  return this->v[index] != other.v[index];
}

void HxE::display() {
  for(auto ve : this->v)
    std::cout << ve;
  std::cout << std::endl;
}

void HxE::bDisplay(bool show_base) {
  std::ostringstream oss;
  if(show_base) {
    for(auto ve : this->v)
      oss << std::left << std::setw(3) << std::hex << std::showbase << static_cast<int>(ve) << " ";
  } else {
    for(auto ve : this->v)
      oss << std::left << std::setw(3) << std::hex << static_cast<int>(ve) << " ";
  }

  std::cout << oss.str() << std::endl;
}

void HxE::bDisplay(const HxE& other, bool show_base) {
  std::ostringstream oss;
  
  for (size_t i = 0; i < v.size(); ++i) {
    char ve = v[i];
    if(isDifferent(other, i))
      oss << RED;
    oss << std::left << std::setw(3) << std::hex << static_cast<int>(ve) << " ";
    oss << RESET;
  }

  std::cout << oss.str() << std::endl;
}

void HxE::undo() {
  if(undoStack.size() == 0) {
    std::cerr << "Nothing to undo" << std::endl;
    return;
  }
  auto [offset, oldByte] = undoStack.top();
  undoStack.pop();

  std::fstream file(this->file, std::ios::binary | std::ios::in | std::ios::out);
  file.seekp(offset);
  char newByte;
  file.read(&newByte, 1);

  redoStack.push({offset, newByte});

  file.seekp(offset);
  file.write(&oldByte, 1);
  
  file.close();
}

void HxE::redo() {
  if(redoStack.size() == 0) {
    std::cerr << "Nothing to redo" << std::endl;
    return;
  }
  auto [offset, redoByte] = redoStack.top();
  redoStack.pop();

  std::fstream file(this->file, std::ios::binary | std::ios::in | std::ios::out);
  file.seekp(offset);
  char oldByte;
  file.read(&oldByte, 1);
  
  undoStack.push({offset, oldByte});

  file.seekp(offset);
  file.write(&redoByte, 1);

  file.close();
}

bool HxE::jumpTo(unsigned int offset) {
  std::ifstream file(this->file, std::ios::binary);
  if(!file.is_open()) {
    std::cerr << "Couldn't open file!" << std::endl;
    return false;
  }
  file.seekg(offset, std::ios::beg);
  file.read(&this->buf, 1);
  return true;
}

void HxE::process() {
  unsigned int offset;
  char byte;
  char select;
  do {
    std::cin>>select;
    if(select == 'e') {
      std::cin>>std::hex>>offset>>byte;
      edit(offset, byte);
    }
    else if(select == 'z')
      undo();
    else if(select == 'q')
      break;
  } while(true);
    // if((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x5A) & 0x8000))
    //   undo();
    // else if((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x45) & 0x8000)) {
    //   std::cin>>std::hex>>offset>>byte;
    //   edit(offset, byte);
    // }
      
}

bool operator>(const HxE &lhs, const HxE &rhs) {
  return lhs.size > rhs.size;
}

bool operator==(const HxE &lhs, const HxE &rhs) {
  return lhs.size == rhs.size;
}

std::ostream &operator<<(std::ostream &os, const HxE &rhs) {
  os << rhs.file;
  return os;
}