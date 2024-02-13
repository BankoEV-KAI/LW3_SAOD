#ifndef QUEUE_H
#define QUEUE_H

struct queueItem
{
	char data;
	queueItem* next, * prew;

	queueItem(char value);
	~queueItem();
};

struct queue
{
	queueItem* front, *rear;
	int count;

	queue();
	~queue();

	bool isEmpty();
	void enqueue(char value);
	void dequeue();
	void returnStateQueue();
};

#endif