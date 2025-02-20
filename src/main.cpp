#include "hex_editor.cpp"

int main() {
  HxE hexEditor;
  hexEditor.read("sample_text.txt");
  // hexEditor.bDisplay();
  hexEditor.bDisplay(false);
  hexEditor.display();
  hexEditor.undoEdit();
  hexEditor.bDisplay(false);
  hexEditor.display();

  return 0;
}