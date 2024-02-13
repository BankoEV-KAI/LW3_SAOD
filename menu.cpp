#include "menu.h"
#include <iostream>


void printMenu(int operation) {

    std::cout << std::endl << "  > - - - - - - - - <     " << std::endl;
    switch (operation)
    {
    case 0:
        std::cout << std::endl
            << "1. Работа со стандартным меню;" << std::endl
            << "2. Автоматическое добавление/удаление элементов некоторой очереди;" << std::endl
            << "0. Завершение работы." << std::endl;
        break;
    case 1:
        std::cout << std::endl
            << "1. Проверка пустоты очереди; " << std::endl
            << "2. Добавление элемента в очередь;" << std::endl
            << "3. Удаление элемента из очереди; " << std::endl
            << "4. Вывод текущего состояния очереди; " << std::endl
            << "0. Вернуться в начало." << std::endl
            << std::endl;
        break;
    case 3:
        std::cout << std::endl
            << "1. Добавить единственный элемент;" << std::endl
            << "2. Добавить множество случайных элементов;" << std::endl
            << "0. Вернуться в начало. " << std::endl
            << std::endl;
        break;
    default:
        break;
    }
}

void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от " << rangeStart << " до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}