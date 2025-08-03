#include <bits/stdc++.h> 
class NStack
{
private:
    int *arr;
    int *top;
    int *next;

    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.

        arr=new int[S];
        top=new int[N];
        next=new int[S];

        for(int i=0;i<N;i++){
            top[i]=-1;
        }

        for(int i=0;i<S;i++){
            next[i]=i+1;
        }
        next[S-1]=-1;

        freespot=0;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.

        //check overflow
        if(freespot==-1){
            return false;
        }

        // step1: find index;
        int index=freespot;

        //update freespot
        freespot=next[index];

        //insert element
        arr[index]=x;

        //update next
        next[index]=top[m-1];

        //update top
        top[m-1]=index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        //check underflow
        if(top[m-1]==-1){
            return -1;
        }

        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};