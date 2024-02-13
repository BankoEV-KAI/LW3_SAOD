#include <iostream>
#include <ctime>
#include <conio.h>

#include "queue.h"
#include "operation.h"


int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}


void Randomize() {
    srand(static_cast<unsigned int>(time(0)));
    std::cout << "Датчик псевдослучайных чисел инициализированн." << std::endl;
}

void processQueue(queue* queueEx, int countItems, bool isAddition) {
    if (isAddition) {
        for (int i = 0; i < countItems; ++i) {
            char value = static_cast<char>(getRandomNumber(65, 90));
            queueEx->enqueue(value);
        }
        std::cout << "Добавлено " << countItems << " элемент(а/ов) в очередь." << std::endl;
    }
    else {
        if (!queueEx->isEmpty()) {
            int deleted{ 0 };
            for (int i = 0; i < countItems && !queueEx->isEmpty(); ++i) {
                queueEx->dequeue();
                deleted++;
            }
            std::cout << "Удалено " << deleted << " элемент(а/ов) из очереди." << std::endl;
        }
        else {
            std::cerr << "Очередь пуста. Невозможно удалить элемент(ы)." << std::endl;
        }
    }
    queueEx->returnStateQueue();
    std::cout << std::endl;
}

void automaticOperation(queue* queueEx) {
    int userInput = 0; 
    clock_t lastChangeTime = clock();
    const double changeInterval = 5.0;

    do {
        clock_t currentTime = clock();
        double elapsedSeconds = static_cast<double>(currentTime - lastChangeTime) / CLOCKS_PER_SEC;

        if (elapsedSeconds >= changeInterval) {
            lastChangeTime = currentTime;

            int randomNumber = getRandomNumber(1, 100);
            bool isAddition = (randomNumber % 2 == 0);

            int numElements = getRandomNumber(1, 3);

            processQueue(queueEx, numElements, isAddition);

        }
        if (_kbhit()) {
            userInput = _getch();
        }

    } while (userInput != 32); //пробел 
}