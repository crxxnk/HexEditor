#include "hex_editor.cpp"
#include "utils.cpp"

int main() {
  // HxE hexEditor;
  // hexEditor.read("sample_text.txt");
  // // hexEditor.bDisplay();
  // hexEditor.bDisplay(false);
  // hexEditor.display();
  // hexEditor.undoEdit();
  // hexEditor.bDisplay(false);
  // hexEditor.display();

  std::cout << std::hex << utils::o_compare("sample_text.txt", "sample_text2.txt").first << " " << utils::p_compare("sample_text.txt", "sample_text2.txt").second;
  HxE hexEditor;
  hexEditor.read("sample_text.txt");
  hexEditor.bDisplay(false);

  return 0;
}