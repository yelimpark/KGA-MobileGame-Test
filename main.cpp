#include <iostream>

int fibo(int num) {
	if (num == 0) return 0;
	if (num == 1) return 1;
	return fibo(num - 2) + fibo(num - 1);
}

void hanoi(int n, int start =1, int mid = 2, int dest = 3)
{
    if (n == 0) return;
    hanoi(n - 1, start, dest, mid);
	std::cout << start << " > " << dest << std::endl;
    hanoi(n - 1, mid, start, dest);
}

struct MyNode {
	int value;
	MyNode* ptr;
};

class MyLinkedList {
private:
	MyNode head;

public:
	MyLinkedList() {
		head.value = NULL;
		head.ptr = nullptr;
	};

	void Insert(MyNode * node, int value) {
		node->ptr = new MyNode();
		node->ptr->ptr = nullptr;
		node->ptr->value = value;
	};

	void Delete(MyNode* prev) {
		MyNode* cur = prev->ptr;
		if (cur == nullptr) {
			std::cout << "node dosen't exist" << std::endl;
			return;
		}
		if (cur->ptr == nullptr) {
			prev->ptr = nullptr;
		}
		else {
			prev->ptr = cur->ptr;
		}
		delete cur;
	}

	void Show(MyNode* prev) {
		MyNode* cur = prev->ptr;
		if (cur == nullptr) {
			std::cout << "node dosen't exist" << std::endl;
			return;
		}
		std::cout << cur->value << std::endl;
	}

	MyNode* GetHead() {
		return &head;
	};

	~MyLinkedList() {
		MyNode* prev = &head;
		MyNode* next = head.ptr;

		while (next != nullptr) {
			prev = next;
			next = prev->ptr;
			delete prev;
		}
	};
};

class MyStack {
private:
	int * arr;
	int last;
	int max;

public:
	MyStack(int max) : last(0), max(max)
	{
		arr = new int[max];
	};

	void push(int value) {
		arr[last++] = value;
	}; 
	
	int pop() {
		return arr[--last];
	};
	
	void print() {
		for (int i = 0; i < last; ++i) {
			std::cout << arr[i] << std::endl;
		}
	};

	bool isFull() {
		return last == max;
	};
	
	bool isEmpty() {
		return last == 0;
	};

	~MyStack() {
		delete arr;
	}
};

int main() {
	std::cout << "fibo 7" << std::endl;
	std::cout << fibo(7) << std::endl;

	std::cout << std::endl << "hanoi 3" << std::endl;
	hanoi(3);

	std::cout << std::endl << "MyLinkedList" << std::endl;
	MyLinkedList mll;
	MyNode* head = mll.GetHead();
	mll.Insert(head, 1);
	mll.Show(head);

	mll.Insert(head->ptr, 2);
	mll.Show(head);

	mll.Delete(head);
	mll.Show(head);

	std::cout << std::endl << "MyStack" << std::endl;
	int max = 5;
	MyStack ms(max);
	ms.push(0);
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.print();

	if (ms.isFull()) {
		std::cout << "Full" << std::endl;
	}

	for (int i = 0; i < max; ++i) {
		std::cout << ms.pop() << " ";
	}
	std::cout << std::endl;

	if (ms.isEmpty()) {
		std::cout << "Empty" << std::endl;
	}

}