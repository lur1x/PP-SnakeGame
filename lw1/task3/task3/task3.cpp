/*Напишите программу, которая:
Запрашивает у пользователя две строки.
Использует метод compare для сравнения этих строк.
Выводит на экран результат сравнения (какая строка лексикографически больше, или если они равны).
*/

#include <iostream>
#include <string>
#include <windows.h>

int main() {

	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string str1, str2;
	int result;

	std::cout << "Введите первую строку" << std::endl;
	getline(std::cin, str1);
	std::cout << "Введите вторую строку" << std::endl;
	getline(std::cin, str2);

	result = str1.compare(str2);
	std::cout << "str1.compare(str2) = " << result << std::endl;
}
