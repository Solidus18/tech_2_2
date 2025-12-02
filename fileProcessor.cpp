#include "fileProcessor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class FileOpenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error opening file!";
    }
};

void processFileForQuotes(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileOpenException();
    }
    
    std::string sentence;
    bool inQuotes = false;
    bool foundAnyQuotes = false;
    char ch;
    
    std::cout << "\nQuotes from file" << std::endl;
    
    while (file.get(ch)) {
        if (ch == '"') {
            if (inQuotes) {
                std::cout << "Quote: \"" << sentence << "\"" << std::endl;
                sentence.clear();
                inQuotes = false;
                foundAnyQuotes = true;
            } else {
                inQuotes = true;
                sentence.clear();
            }
        } else if (inQuotes) {
            sentence += ch;
        }
    }
    
    file.close();
    
    if (inQuotes && !sentence.empty()) {
        std::cout << "Warning: Unclosed quote found: \"" << sentence << "\"" << std::endl;
        foundAnyQuotes = true;
    }
    
    if (!foundAnyQuotes) {
        std::cout << "No quotes found in the file." << std::endl;
    }
}