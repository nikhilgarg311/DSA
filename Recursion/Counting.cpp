#include<iostream>
using namespace std;

void reverseCounting(int n){
    //base condition
    if(n==0){
        return;
    }
    else{
        cout<<n<<" ";
        reverseCounting(n-1); //tail recursion
    }

}

void counting(int n){
    //base condition
    if(n==0){
        return;
    }
    else{
        counting(n-1); //head recursion
        cout<<n<<" ";
    }

}
int main(){
    int n=5;
    reverseCounting(n);
    cout<<endl;
    counting(n);
}