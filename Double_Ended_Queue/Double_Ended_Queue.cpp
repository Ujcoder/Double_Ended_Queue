using namespace std;
#include<iostream>
#define MAX 10
int cqueue[MAX];
int front = -1, rear = -1;

void enqueueFront(int item) 
{
    if ((front == -1 && rear == MAX - 1) || (front == rear + 1)) 
    {
        cout << "Dequeue is Full!" << endl;
        return;
    }
    if (front == -1) 
    {
        front = 0;
        rear = 0;
    }
    else 
    {
        if (front == 0)
            front = MAX - 1;
        else
            front--;
    }
    cqueue[front] = item;
    cout << "Enqueued at the front: " << item << endl;
}

void enqueueRear(int item) 
{
    if ((front == -1 && rear == MAX - 1) || (front == rear + 1)) 
    {
        cout << "Dequeue is Full!" << endl;
        return;
    }
    if (front == -1) 
    {
        front = 0;
        rear = 0;
    }
    else 
    {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear++;
    }
    cqueue[rear] = item;
    cout << "Enqueued at the rear: " << item << endl;
}

int dequeueFront() 
{
    if (front == -1) 
    {
        cout << "Dequeue is empty!" << endl;
        return -1;
    }
    int item = cqueue[front];
    if (front == rear)
        front = rear = -1;
    else 
    {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
    cout << "Dequeued from the front: " << item << endl;
    return item;
}

int dequeueRear() 
{
    if (front == -1)
    {
        cout << "Dequeue is empty!" << endl;
        return -1;
    }
    int item = cqueue[rear];
    if (front == rear)
        front = rear = -1;
    else 
    {
        if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
    cout << "Dequeued from the rear: " << item << endl;
    return item;
}

void display() 
{
    int i;
    if (front == -1) 
    {
        cout << "Dequeue is empty!" << endl;
        return;
    }
    cout << "All elements in Dequeue are: " << endl;
    if (front <= rear)
        for (i = front; i <= rear; i++)
            cout << cqueue[i] << endl;
    else 
    {
        for (i = front; i < MAX; i++)
            cout << cqueue[i] << endl;
        for (i = 0; i <= rear; i++)
            cout << cqueue[i] << endl;
    }
    return;
}

int main() 
{
    int ch, v;
    do 
    {
        cout << "1. Enqueue Front 2. Enqueue Rear \n3. Dequeue Front 4. Dequeue Rear \n5. Display 6. Exit : " << endl;
        cout << "Enter the Choice :  ";     cin >> ch;
        switch (ch) 
        {
        case 1:  cout << "Enter enqueue element at the front: ";
            cin >> v;     enqueueFront(v);   break;
        case 2:  cout << "Enter enqueue element at the rear: ";
            cin >> v;    enqueueRear(v);      break;
        case 3:  v = dequeueFront();
            if (v != -1)
                cout << "The element is dequeued from the front: " << v << endl;
            break;
        case 4:  v = dequeueRear();
            if (v != -1)
                cout << "The element is dequeued from the rear: " << v << endl;
            break;
        case 5: display();   break;
        default:    cout << "Exiting............!" << endl;
        ch = 6;
        }
    } while (ch != 6);
}
