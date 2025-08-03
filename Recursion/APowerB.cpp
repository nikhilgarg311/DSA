#include<iostream>
using namespace std;

int calcPower(int a,int b){
    //base case
    if(b==0){
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b&1){
        return a*calcPower(a,(b-1)/2)*calcPower(a,(b-1)/2);
    }
    else{
        return calcPower(a,b/2)*calcPower(a,b/2);
    }
}

int main(){
    int a=2,b=10;
   cout<< calcPower(a,b);
}