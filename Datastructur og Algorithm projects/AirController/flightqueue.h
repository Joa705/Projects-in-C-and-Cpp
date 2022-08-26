#ifndef AIRCONTROLLER_FLIGHTQUEUE_H
#define AIRCONTROLLER_FLIGHTQUEUE_H

#define SIZE 100
using namespace std;


class Flightqueue {
private:
    int q[SIZE];
    int front = - 1;
    int rear = -1;

public:

    bool isempty() {
        return ((front == -1 && rear == -1));
    }


    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1)
                front = 0;
            rear++;
            q[rear] = value;
        }
    }

    void dequeue(){
        if(isempty())
            cout << "Queue is empty" << endl;
        else if(front == rear)
            front = rear = -1;
        else
            front++;

    }

    void showqueue(){
        if(isempty())
            cout << "Queue is empty" << endl;
        else{
            int count = 0;
            for (int i = front; i <= rear; ++i) {
                cout << "Queue Position " << count << ": " << q[i] << endl;
                count++;
            }
        }
    }



};

#endif //AIRCONTROLLER_FLIGHTQUEUE_H
