#include <iostream>

using namespace std;

class CircularQueue {
public:
    CircularQueue(int size) {
        arr = new int[size];
        front = 0;
        rear = 0;
        arrSize = size;
    }

    CircularQueue() {
        arr = new int[100];
        front = 0;
        rear = 0;
        arrSize = 100;
    }

    int rear, front;
    int *arr;
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
    void enQueue(int num){
        if (isFull()) {
            cout<<"Queue is full!"<<endl;
            return;
        }
        else {
            rear = (rear + 1) % arrSize;
            arr[rear] = num;
        }
    }
    string deQueue(){
        if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
            return "No item to deQueue";
        }
        else {
            front = (front + 1) % arrSize;
            int res = arr[front];
            arr[front] = 0;
            return to_string(res);
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
    CircularQueue queue(5);
    for (int i = 0; i < 5; i++) {
        queue.enQueue(i);
        cout<<"Queue arr index "<< i <<" : "<< queue.arr[i] <<endl;
        cout<<"queue have : "<< queue.getNum()<<" numbers now"<<endl;
    }
    cout<<"arr "<<"4"<<" : "<<queue.arr[4]<<endl;
    cout<<queue.deQueue()<<endl;
    cout<<queue.deQueue()<<endl;
    cout<<queue.deQueue()<<endl;
    cout<<"queue have : "<< queue.getNum()<<" numbers now"<<endl;
    cout<<queue.deQueue()<<endl;
    cout<<queue.deQueue()<<endl;
    cout<<"queue have : "<< queue.getNum()<<" numbers now"<<endl;
    cout<<queue.deQueue()<<endl;
    return 0;
}
