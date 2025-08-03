#include<iostream>
using namespace std;

void fibonacci(int first, int second, int n){

    //base case
    if(n==0){
        return;
    }
    else{
        int third=first+second;
        cout<<third<<" ";
        first=second;
        second=third;
        fibonacci(first,second,n-1);
    }

}

int main(){
    int n=10;
    int first=0,second=1;
    cout<<first<<" "<<second<<" ";
    fibonacci(first,second,n-2);
}