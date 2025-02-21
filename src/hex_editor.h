#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdint>
#include <filesystem>
#include <stack>

class HxE {
  char buf;
  const char* file;
  std::vector<uint8_t> v;

  std::stack<std::pair<unsigned int, char>> undoStack;
  std::stack<std::pair<unsigned int, char>> redoStack;
public:
  bool read(const char* input);
  bool read(const char* input, unsigned int offset); // reads file from a specific offset
  void edit(unsigned int offset, char byte);
  void display();
  void bDisplay(bool show_base);
  void undo();
  void redo();
  uintmax_t getSize() { return std::filesystem::file_size(this->file); }
  const char* getFile() const { return this->file; }
};