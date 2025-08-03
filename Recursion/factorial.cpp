#include<iostream>
using namespace std;

int factorial(int n){
    //base case
    if(n<1){
        return 1;
    }
    else{
        //recursive relation
        return n*factorial(n-1);
    }
}
int main(){
    int n=5;
    cout<<"factorial is: "<<factorial(n)<<endl;
}