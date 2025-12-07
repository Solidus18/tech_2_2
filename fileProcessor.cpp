#include "fileProcessor.h" 
#include <iostream>       
#include <fstream>         
#include <string>          
#include <cstring>        

// Исключение при ошибке открытия файла
class FileOpenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error opening file!";
    }
};

// Функция обработки файла для поиска цитат
void processFileForQuotes(const char* filename) {
    std::ifstream file(filename); // Создание объекта файлового потока для чтения
    if (!file.is_open()) {        // Проверка успешности открытия
        throw FileOpenException(); // Генерация исключения при ошибке
    }
    
    std::string sentence;         // Строка для накопления текста цитаты
    bool inQuotes = false;        // Флаг: находимся ли внутри кавычек
    bool foundAnyQuotes = false;  // Флаг: найдена ли хотя бы одна цитата
    char ch;                      // Переменная для чтения символов
    
    std::cout << "\nQuotes from file" << std::endl; // Заголовок вывода
    
    while (file.get(ch)) {        // Чтение файла посимвольно до конца
        if (ch == '"') {          // Если найден символ кавычки
            if (inQuotes) {       // Если уже внутри кавычек
                std::cout << "Quote: \"" << sentence << "\"" << std::endl; // Вывод цитаты
                sentence.clear(); // Очистка строки
                inQuotes = false; // Сброс флага
                foundAnyQuotes = true; // Установка флага найденной цитаты
            } else {              // Если начало новой цитаты
                inQuotes = true;  // Установка флага
                sentence.clear(); // Очистка строки
            }
        } else if (inQuotes) {    // Если внутри кавычек и не символ кавычки
            sentence += ch;       // Добавление символа к цитате
        }
    }
    
    file.close();                
    
    if (inQuotes && !sentence.empty()) { // Проверка незакрытой кавычки
        std::cout << "Warning: Unclosed quote found: \"" << sentence << "\"" << std::endl;
        foundAnyQuotes = true;    // Установка флага
    }
    
    if (!foundAnyQuotes) {        // Если цитаты не найдены
        std::cout << "No quotes found in the file." << std::endl; 
    }
}