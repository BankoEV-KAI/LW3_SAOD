#include "menu.h"
#include "operation.h"
#include <iostream>

void main() {
	setlocale(LC_ALL, "ru");
	Randomize();
	queue* mainQueue = new queue;
	int operation {-1};
	//вызов менюшки для выбора: работать стандартно, автоматическое удаление/добвление, завершение работы
	while (true) {
		printMenu(0);
		enteringNumber(0, 2, operation);
		switch (operation)
		{
		case 0:
			mainQueue->~queue();
			return;
		case 1: //стандартная работа
			standartOperation(mainQueue);
			break;
		case 2: //автоматическая работа
			automaticOperation(mainQueue);
			break;
		default:
			break;
		}

	}

}