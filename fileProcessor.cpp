#include "fileProcessor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class FileOpenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Ошибка открытия файла!";
    }
};

void processFileForQuotes(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileOpenException();
    }
    
    std::string line;
    std::string sentence;
    bool inQuotes = false;
    char ch;
    
    std::cout << "\n=== Цитаты из файла ===" << std::endl;
    
    while (file.get(ch)) {
        if (ch == '"') {
            if (inQuotes) {
                // Конец цитаты
                std::cout << "Цитата: \"" << sentence << "\"" << std::endl;
                sentence.clear();
                inQuotes = false;
            } else {
                // Начало цитаты
                inQuotes = true;
                sentence.clear();
            }
        } else if (inQuotes) {
            sentence += ch;
        }
    }
    
    file.close();
    
    if (sentence.empty() && !inQuotes) {
        std::cout << "Цитаты в файле не найдены." << std::endl;
    }
}