#include <iostream>

using namespace std;

struct element{
    element* prev = nullptr;
    int value;
};

struct desStack{
    element* last;
    int count;
};

void construc(desStack& sStack){
    sStack.last= nullptr;
    sStack.count= 0;
}

void destruc(desStack& sStack){
    while (sStack.last != nullptr)
    {
        element* tmp;
        tmp=sStack.last;
        sStack.last=sStack.last -> prev;
        delete tmp;
        --sStack.count;
    }
}

unsigned int size(desStack& myStack){
    return myStack.count;
}

void push(desStack& sStack, element& myelement){
    element* tmp = new element;
        tmp -> value = myelement.value;
            if (sStack.last == nullptr){
                sStack.last = tmp;
            }
            else{
                tmp -> prev = sStack.last;
                sStack.last = tmp;
            }
        sStack.count ++;
    }

void pop_last(desStack& sStack){
    cout << "Perviy element: " << sStack.last -> value << endl;
        element  *temp = sStack.last;
        sStack.last = sStack.last -> prev;
        delete temp;
        --sStack.count;
}

void Print(desStack& myStack){
    element * d0w = myStack.last;
        while (d0w != nullptr){
            int element = d0w -> value;
            cout << element << endl;
            d0w = d0w -> prev;
        }
    }

int main()
{
    desStack sStack;
        construc(sStack);
            element myelement;
    int a,b;
        cout << "Vvedite kolichestvo elementov: ";
            cin >> b;
    for (int i = 1; i <= b; ++i){
        cout << "Vvedite " <<i<<" element"<< " =";
            cin >> a;
            myelement.value = a;
            push(sStack, myelement);
        }
    Print(sStack);
    cout<<endl;
    cout<<"Razmer:"<<size(sStack)<<endl;
    pop_last(sStack);
    cout<<"Razmer:"<<size(sStack)<<endl;
    Print(sStack);
    destruc(sStack);
    return 0;
}
