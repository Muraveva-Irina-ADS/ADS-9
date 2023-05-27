// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::string word;
    BST<std::string> peace;
    std::ifstream file(filename);
    if (file) {
        while (!file.eof()) {
            char symbol = tolower(file.get());
            if (isalpha(symbol))
                word += symbol;
            else {
                if (!word.empty())
                    peace.add(word);
                word.clear();
            }
        }
    }
    else 
        std::cout << "File error!" << std::endl;
    file.close();
    return peace;
}
