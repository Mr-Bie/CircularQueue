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

    bool isFull(){
        int rearTmp = rear;
        rearTmp = (rearTmp + 1) % sizeof(arr);
        if(rearTmp == front) return true;
        else return false;
    }
    bool isEmpty(){
        if (rear == front) return true;
        else return false;
    }
    void enQueue(int num){
        if (isFull()) {
            cout<<"Queue is full!"<<endl;
            return;
        }
        else {
            rear = (rear + 1) % sizeof(arr);
            arr[rear] = num;
        }
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
