/*
    algo:
    idea:

*/
#include <iostream>

using namespace std;


class Stack {
private:
    int ara[2020];
    int pos = -1;
public:


    void push(int n) {
        ara[++pos] = n;
        cout<<"pushed "<<n<<endl;
    }

    int pop() {
        if(pos!= -1)
        {
            cout<<"popped "<<ara[pos]<<endl;
            pos--;
        }
    }

    int top() {
        if(~pos)
        {
            cout<<"current top "<<ara[pos]<<endl;
            return ara[pos];
        }
    }
};
int main()
{
//    FAST_READ

    Stack *s = new Stack();


    s->push(1);
    s->push(2);
    s->push(3);

    s->top();
    s->pop();
    s->pop();
    s->pop();
    s->pop();
    return 0;
}
