#include "queue.h"
#include <iostream>

//������������
queueItem::queueItem(char value) : data(value), next(nullptr), prew(nullptr) {}

queue::queue() : front(nullptr), rear(nullptr) { count = 0; }

//�����������
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

    std::cout << "������� " << value << " �������� � �������.\n";
}

void queue::dequeue()
{
    if (isEmpty()) {
        std::cout << "������� �����, ���������� ������� �������.\n";
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
    std::cout << "������� " << value << " ������ �� �������.\n";
}

void queue::returnStateQueue()
{
    std::cout << std::endl << "������� ��������� �������: ";
    if (isEmpty()) {
        std::cout << "������� �����" << std::endl;
    }
    else {
        std::cout <<" ������� �� �����"<< std::endl
            << "������ �������: " << front->data << std::endl
            << "��������� �������: " << rear->data << std::endl
            << "���������� ��������� � �������: " << count << std::endl;
    }
}


