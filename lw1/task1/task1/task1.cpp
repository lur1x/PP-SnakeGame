/*Напишите программу, которая:
Запрашивает у пользователя строку.
Используя методы front и back, выводит на экран первый и последний символы этой строки.
*/

#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;

    std::cout << "Напишите любую строку" << std::endl;
    getline(std::cin, str);

    if (str.empty()) {
        std::cout << "Вы ввели пустую строку" << std:: endl;
    }
    else {
        std::string firstCh, lastCh;
        firstCh = str.front();
        lastCh = str.back();
        std::cout << "Первый симовол строки: " << firstCh << std::endl;
        std::cout << "Последний символ строки: " << lastCh << std::endl;
    }
}
