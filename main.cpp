#include <iostream>
#include <cstring>
#include <conio.h>
#include "fileProcessor.h"

void displayMenu() {
    std::cout << "\nProcessing of text files" << std::endl;
    std::cout << "1. Find and output quotes from a file" << std::endl;
    std::cout << "2. Exit\n" << std::endl;
}

int main() {
    char choice;
    
    std::cout << "A program for searching quotes in text files" << std::endl;
    
    do {
        displayMenu();
        choice = _getch();
        
        try {
            switch (choice) {
                case '1': {
                    char filename[100];
                    std::cout << "Enter the name of the file to process: ";
                    std::cin >> filename;
                    processFileForQuotes(filename);
                    break;
                }
                case '2': {
                    std::cout << "Exiting the program..." << std::endl;
                    break;
                }
                default: {
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
    } while (choice != '2');
    
    return 0;
}