//============================================================================
// Name        : Queue_Array.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

typedef int Data;
static const int QUE_LEN = 5;

class Queue
{
private:
	struct Container
	{
		int front;
		int rear;
		Data queArr[QUE_LEN];
	};

	Container container;

public:
	Queue(){ init(); };
	~Queue(){};

	void init();
	int isEmpty();

	void enqueue(Data data);
	Data dequeue();
	Data peek();

	int nextIndex(int pos);
};

void Queue::init()
{
	container.front = 0;
	container.rear = 0;
	container.queArr[0] = 0;
}

int Queue::isEmpty()
{
	return (container.front == container.rear) ? true : false;
}


void Queue::enqueue(Data data)
{
	if( nextIndex(container.front) == container.rear )
	{
		cout << "Queue is FULL\n";
		exit(-1);
	}

	//move front index
	container.front = nextIndex(container.front);
	container.queArr[container.front] = data;
}

Data Queue::dequeue()
{
	if(isEmpty())
	{
		cout << "queue is empty!!!\n";
		exit(-1);
	}

	int nextIdx = nextIndex(container.rear);

	Data temp = container.queArr[nextIdx];

	//move rear queue
	container.rear = nextIdx;

	return temp;
}


int Queue::nextIndex(int pos)
{
	if(pos == (QUE_LEN - 1))
	{
		return 0;
	}
	else
	{
		return pos + 1;
	}
}

Data Queue::peek()
{
	if(isEmpty())
	{
		cout << "queue is empty!!!\n";
		exit(-1);
	}

	return container.queArr[container.front];
}


int main()
{
	Queue arrQueue;

	arrQueue.enqueue(1);
	arrQueue.enqueue(2);
	arrQueue.enqueue(3);
	arrQueue.enqueue(4);
//	arrQueue.enqueue(5);

	cout << arrQueue.dequeue() << endl; //1
	cout << arrQueue.dequeue() << endl; //2
	cout << arrQueue.dequeue() << endl; //3
	cout << arrQueue.dequeue() << endl; //4

	arrQueue.enqueue(8);
	cout << arrQueue.dequeue() << endl; //8

	arrQueue.enqueue(8);
	cout << arrQueue.peek() << endl; //8


	return 0;
}
