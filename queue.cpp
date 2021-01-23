#include <iostream>

using namespace std;

struct element{
    element* q_next = nullptr;
    int value ;
};

struct disQueue {
    element* first;
    element* last;
    int count;
};

void construc(disQueue& Queue){
    Queue.first = nullptr;
    Queue.last = nullptr;
    Queue.count = 0;
}

void push(disQueue& Queue, element& myelement){
    element* q = new element;
    q -> value = myelement.value;
    if (Queue.first == nullptr){
        Queue.first = q;
        Queue.last = q;
    } else{
        Queue.last -> q_next = q;
        Queue.last = q;
    }
    ++Queue.count;
    
}

unsigned int size(disQueue& Queue){
    return Queue.count;
}

void Print(disQueue& Queue){
    element* temp = Queue.first;
    while (temp != nullptr){
        int element = temp -> value;
            cout << element << " ";
            temp = temp -> q_next;
        }
    }

void pop(disQueue &Queue){
    cout << "Perviy element: " << Queue.first -> value<< endl;
    element  *temp = Queue.first;
    Queue.first = Queue.first -> q_next;
    delete temp;
    --Queue.count;
    
}

void destruc(disQueue& Queue){
    while (Queue.first != nullptr){
        element* temp = temp = Queue.first;
            Queue.first = Queue.first -> q_next;
            delete temp;
            --Queue.count;
    }
}

int main()
{
    disQueue Queue;
    construc(Queue);
    element element;
    int a, b;
    cout << "Vvedite kolichestvo elementov: ";
    cin >> a;
    for (int i = 1; i <= a; ++i)
    {
        cout << "Vvedite " << i << " element: ";
        cin >> b;
        element.value = b;
        push(Queue, element);
    }
    Print(Queue);
    cout << endl;
    cout << "Razmer: " << size(Queue) << endl;
    pop(Queue);
    cout << "Razmer posle udaleniya pervogo elementa: " << size(Queue) << endl;
    Print(Queue);
    cout<<endl;
    destruc(Queue);
    cout << "V queue "<<size(Queue)<<endl;
    return 0;
}
