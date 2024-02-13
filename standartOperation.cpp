#include "operation.h"
#include "menu.h"

#include <iostream>
#include "operation.h"



void standartOperation(queue* queueEx) {
    int operation;
    char value;
    while (true) {
        printMenu(1);
        enteringNumber(0, 4, operation);
        switch (operation)
        {
        case 1:
            queueEx->isEmpty() ? std::cout << "Очередь пуста. " << std::endl : std::cout << "Очередь не пуста." << std::endl;
            break;
        case 2:
            printMenu(3);
            enteringNumber(0, 2, operation);
            if (operation == 1) {
                value = static_cast<char>(getRandomNumber(65, 90));
                queueEx->enqueue(value);
            }
            else {
                int count;
                std::cout << "Сколько эллементов необходимо добавить? " << std::endl;
                enteringNumber(1, 100, count);
                for (int i = 1; i <= count; i++) {
                    value = static_cast<char>(getRandomNumber(65, 90));
                    queueEx->enqueue(value);
                }
            }
            queueEx->returnStateQueue();
            break;
        case 3:
            queueEx->dequeue();
            queueEx->returnStateQueue();
            break;
        case 4:
            queueEx->returnStateQueue();
            break;
        case 0:
            return;
        default:
            std::cout << "Был прозведен некорректный ввод. Повторите." << std::endl;
            break;
        }
    }
}