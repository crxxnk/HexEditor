#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdint>
#include <filesystem>
#include <stack>
#include <sstream>
#include <Windows.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

class HxE {

  friend bool operator>(const HxE& lhs, const HxE& rhs);
  friend bool operator==(const HxE& lhs, const HxE& rhs);
  friend std::ostream &operator<<(std::ostream &os, const HxE &rhs);
  char buf;
  const char* file;
  std::vector<uint8_t> v;
  unsigned int size;

  std::stack<std::pair<unsigned int, char>> undoStack;
  std::stack<std::pair<unsigned int, char>> redoStack;
public:
  bool read(const char* input); // reads a file
  bool read(const char* input, unsigned int offset); // reads file from a specific offset
  void edit(unsigned int offset, char byte);
  bool isDifferent(const HxE& other, size_t index) const;
  void display();
  void bDisplay(bool show_base);
  void bDisplay(const HxE& other, bool show_base);
  void undo();
  void redo();
  bool jumpTo(unsigned int offset);
  uintmax_t getSize() const { return std::filesystem::file_size(this->file); }
  const char* getFile() const { return this->file; }
  char getCurrentByte() const { return this->buf; }

  void process();
};