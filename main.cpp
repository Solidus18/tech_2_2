#include <iostream>
#include <cstring>
#include "fileProcessor.h"

void displayMenu() {
    std::cout << "\n=== Обработка текстовых файлов ===" << std::endl;
    std::cout << "1. Найти и вывести цитаты из файла" << std::endl;
    std::cout << "2. Выход" << std::endl;
    std::cout << "Выберите опцию: ";
}

int main() {
    int choice;
    
    std::cout << "Программа для поиска цитат в текстовых файлах" << std::endl;
    std::cout << "Цитаты - это предложения, заключенные в кавычки" << std::endl;
    
    do {
        displayMenu();
        std::cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    char filename[100];
                    std::cout << "Введите имя файла для обработки: ";
                    std::cin >> filename;
                    processFileForQuotes(filename);
                    break;
                }
                case 2: {
                    std::cout << "Выход из программы..." << std::endl;
                    break;
                }
                default: {
                    std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }
        
    } while (choice != 2);
    
    return 0;
}