#include <iostream>

using namespace std;

class CircularQueue {
public:
    CircularQueue(int size) {
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    CircularQueue() {
        arr = new int[100];
        front = 0;
        rear = 0;
    }

    int rear, front;
    int *arr;


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
