#include<iostream>
#include<string>
using namespace std;

string reverse(string s, int i,int j){
    if(i>j){
        return s;
    }
    swap(s[i],s[j]);
    i++;j--;
    return reverse(s,i,j);

}

int main(){
    string s= "Nikhil";
    cout<<"Reversed string is: " << reverse(s,0,s.length()-1);
}