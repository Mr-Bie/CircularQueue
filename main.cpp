#include <iostream>
#include <vector>

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

    bool isFull() {
        int rearTmp = rear;
        rearTmp = (rearTmp + 1) % arrSize;
        if (rearTmp == front) return true;
        else return false;
    }

    bool isEmpty() {
        if (rear == front) return true;
        else return false;
    }

    void enQueue(string job) {
        if (isFull()) {
            return;
        } else {
            rear = (rear + 1) % arrSize;
            arr[rear] = job;
        }
    }

    string deQueue() {
        if (isEmpty()) {
            return "";
        } else {
            front = (front + 1) % arrSize;
            string res = arr[front];
            arr[front] = "0";
            return res;
        }
    }
};

void rotationalScheduler(string arg) {
    arg = arg + ",";
    vector<CircularQueue> queueVector;
    int maxAmount = 0;
    while ((arg.find(",")) != string::npos) {
        string job = arg.substr(0, arg.find(','));
        string jobTitle = job.substr(0, arg.find(' '));
        int jobAmount;
        try {
            jobAmount = stoi(job.erase(0, arg.find(' ') + 1));
        } catch (...) {
            cout<<"Invalid job amount for job : "<<jobTitle<<endl;
            arg.erase(0, arg.find(',') + 1);
            continue;
        }
        if (maxAmount < jobAmount) maxAmount = jobAmount;
        CircularQueue queue(jobAmount + 1);
        for (int i = 0; i <= jobAmount; ++i) {
            queue.enQueue(jobTitle);
        }
        queueVector.push_back(queue);
        arg.erase(0, arg.find(',') + 1);
    }
    for (int i = 0; i < maxAmount; i++) {
        for (int j = 0; j < queueVector.size(); j++) {
            if (!queueVector[j].isEmpty()) cout << queueVector[j].deQueue() << "\t";
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    rotationalScheduler("B 1,A 5,C 5,TH 1,W a,QRC 4,h 2");
    return 0;
}
