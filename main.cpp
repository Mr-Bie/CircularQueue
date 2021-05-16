#include <iostream>

using namespace std;

class CircularQueue {
public:
    CircularQueue(int size) {
        arr = new string[size];
        front = 0;
        rear = 0;
        arrSize = size;
    }

    int rear, front;
    string *arr;
    int arrSize;

    bool isFull(){
        int rearTmp = rear;
        rearTmp = (rearTmp + 1) % arrSize;
        if(rearTmp == front) return true;
        else return false;
    }
    bool isEmpty(){
        if (rear == front) return true;
        else return false;
    }
    void enQueue(int job){
        if (isFull()) {
            cout<<"Queue is full!"<<endl;
            return;
        }
        else {
            rear = (rear + 1) % arrSize;
            arr[rear] = job;
        }
    }
    string deQueue(){
        if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
            return "No item to deQueue";
        }
        else {
            front = (front + 1) % arrSize;
            string res = arr[front];
            arr[front] = 0;
            return res;
        }
    }
    int getNum(){
        if(isEmpty()) return 0;
        if(isFull()) return arrSize - 1;
        if(rear > front) return rear - front;
        if(front > rear) return (arrSize - front) + rear;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
