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

  // std::cout << utils::c_p_compare("sample_text.txt", "sample_text2.txt").first << " " << utils::c_p_compare("sample_text.txt", "sample_text2.txt").second;
  // std::cout << utils::b_compare("sample_text.txt", "sample_text2.txt");
  HxE hexEditor;
  HxE hexEditor2;
  // hexEditor.read("sample_text.txt");
  hexEditor.read("sample_text.txt");
  hexEditor2.read("sample_text2.txt");

  // HxE hexEditor2;
  // hexEditor2.read("sample_text2.txt");

  // hexEditor.jumpTo(0x63);
  // std::cout << hexEditor.getCurrentByte() << std::endl;

  // hexEditor.process();
  
  // std::vector<unsigned int> idk;
  // auto c = utils::a_compare(hexEditor, hexEditor2, idk);
  // for(auto v : c) {
  //   std::cout << std::hex << v.first << " " << v.second << std::endl;
  // }

  // for(auto v : idk) {
  //   std::cout << v << " ";
  // }

  // hexEditor.edit(0x1, 0x71);
  // hexEditor2.edit(0x63, 0x65);
  // hexEditor.read("sample_text.txt");
  // hexEditor2.read("sample_text2.txt");

  // int i = 0;
  // while(i < 10000)
  //   i++;

  // hexEditor.bDisplay(hexEditor2, false);


  // std::vector<unsigned int> idk;
  // auto c = utils::c_a_compare(hexEditor, hexEditor2, idk);
  // for(auto v : c) {
  //   std::cout << v.first << " " << v.second << std::endl;
  // }
  
  // for(auto v : idk) {
  //   std::cout << v << " ";
  // }

  // hexEditor.edit(0x1, 0x65);
  // hexEditor.edit(0x63, 0x75);

  std::cout << utils::s_compare(hexEditor, hexEditor2);

  // std::cout << utils::c_p_compare(hexEditor, hexEditor2).first << " " << utils::c_p_compare(hexEditor, hexEditor2).second;

  // std::vector<std::pair<int, int>> comp = utils::a_compare(hexEditor, hexEditor2);
  // for(auto v : comp)
  //   std::cout << std::hex << v.first << " " << v.second << std::endl;

  // std::vector<std::pair<char, char>> comp2 = utils::ca_compare(hexEditor, hexEditor2);
  // for(auto v : comp2)
  //   std::cout << std::hex << v.first << " " << v.second << std::endl;

  // hexEditor.edit(0x20, 65);
  // char select;
  // while(true) {
  //   std::cin >> select;
  //   if(select == 'r')
  //     hexEditor.redo();
  //   else if (select == 'u')
  //     hexEditor.undo();
  //   else
  //     break;
  // }

  return 0;
}