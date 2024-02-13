#include "queue.h"
#include <iostream>

//конструкторы
queueItem::queueItem(char value) : data(value), next(nullptr), prew(nullptr) {}

queue::queue() : front(nullptr), rear(nullptr) { count = 0; }

//деструкторы
queueItem::~queueItem(){}

queue::~queue() {
	while (!isEmpty()) {
		dequeue();
	}
	delete front;
	delete rear;
}

bool queue::isEmpty()
{
	return (front == nullptr);
}

void queue::enqueue(char value)
{
    queueItem* newItem = new queueItem(value);

    if (isEmpty()) {
        front = rear = newItem;
    }
    else {
        rear->next = newItem;
        newItem->prew = rear;
        rear = newItem;
    }

    rear->next = front;
    front->prew = rear;
    count++;

    std::cout << "Ёлемент " << value << " добавлен в очередь.\n";
}

void queue::dequeue()
{
    if (isEmpty()) {
        std::cout << "ќчередь пуста, невозможно удалить элемент.\n";
        return;
    }

    char value = front->data;
    queueItem* temp = front;

    if (front == rear) {
        front = rear = nullptr;
    }
    else {
        front = front->next;
        rear->next = front;
        front->prew = rear;
    }
    count--;
    delete temp;
    std::cout << "Ёлемент " << value << " удален из очереди.\n";
}

void queue::returnStateQueue()
{
    std::cout << std::endl << "“екущее состо€ние очереди: ";
    if (isEmpty()) {
        std::cout << "очередь пуста" << std::endl;
    }
    else {
        std::cout <<" очередь не пуста"<< std::endl
            << "первый элемент: " << front->data << std::endl
            << "последний элемент: " << rear->data << std::endl
            << "количество элементов в очереди: " << count << std::endl;
    }
}


