/*
    algo:
    idea:

*/
#include <iostream>

#define LIM 100100
using namespace std;


class Queue{
private:
    int l, r, ara[LIM];

public:

    Queue(int l, int r) {
        this->l = l;
        this->r = r;
    }

    void push(int n) {
        if(r == LIM)
            cout<<"n "<<n<<" overflowed"<<endl;
        if(l == -1) {
            l++;
        }
        ara[++r] = n;
        cout<<"pushed "<<n<<endl;
    }

    int front() {
        if(l!= -1)
        {
            cout<<"front "<<ara[l]<<endl;
            return ara[l];
        }
            cout<<"ara is empty"<<endl;
    }

    int pop() {
        if(l!=-1 && l<=r)
        {
            cout<<"popped "<<ara[l]<<endl;
            int ret = ara[l++];
            if(l>r)
                l=-1,r=-1;
            return ret;
        } else {
            cout<<"pop ara is empty"<<endl;
            return -1;
        }
    }
};

int main()
{
//    FAST_READ

    Queue *q = new Queue(-1,-1);


    q->push(1);
    q->push(2);
    q->push(3);

    q->front();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    return 0;
}
