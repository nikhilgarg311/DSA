#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.pop(); // this will pop and remove
    cout<<s.empty()<<endl;
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
}