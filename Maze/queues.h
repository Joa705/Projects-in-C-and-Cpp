#ifndef MAZE_QUEUES_H
#define MAZE_QUEUES_H
using namespace std;

#define SIZE 1000

class myqueue
{
public:
    int q[SIZE];
    int front = -1;
    int rear = -1;

};




bool isempty(myqueue temp){
    if(temp.front == -1 && temp.rear == -1)
        return true;
    else
        return false;
}



myqueue enqueue(myqueue temp, int value){
    if(temp.rear == SIZE-1){
        cout << "Queue is full" << endl;
    }
    else{
        if(temp.front == -1)
            temp.front = 0;
        temp.rear ++;
        temp.q[temp.rear] = value;
    }

    return temp;

}

myqueue dequeue(myqueue temp){
    if(isempty(temp))
        cout << "Queue is empty" << endl;
    else if(temp.front == temp.rear)
        temp.front = temp.rear = -1;
    else
        temp.front++;

    return temp;
}

void showqueue(myqueue temp){
    if(isempty(temp))
        cout << "Queue is empty" << endl;
    else{
        int count = 0;
        for (int i = temp.front; i <= temp.rear; ++i) {
            cout << "Queue Position " << count << ": " << temp.q[i] << endl;
            count++;
        }
    }

}


#endif //MAZE_QUEUES_H
