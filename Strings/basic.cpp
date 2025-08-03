#include<iostream>
using namespace std;

char toLowerCase(char ch){
    if(ch>='a'&& ch<='z'){
        return ch;
    }
    else{
        return(ch - 'A' + 'a');
    }
}

bool checkPalindrome(char arr[],int n){ // not case sensitive
int start=0;
int end=n-1;
while(start<=end){
    if(toLowerCase(arr[start])!=toLowerCase(arr[end])){
        return 0;
    }
    else{
        start++;
        end--;
    }
}
return 1;
}

bool palindrome(char arr[],int n){ //case sensitive
int start=0;
int end=n-1;
while(start<=end){
    if(arr[start]!=arr[end]){
        return 0;
    }
    else{
        start++;
        end--;
    }
}
return 1;
}

void reverse(char arr[],int n){
int start=0;
int end=n-1;
while(start<end){
    swap(arr[start],arr[end]);
    start++;end--;
}
cout<<"Reverse is: "<<arr<<endl;
}

int getLength(char arr[]){
    int count =0;
    for(int i=0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){
    char arr[20]="Noon";
    int n= getLength(arr);
    cout<<"Length of string: "<<n<<endl;
    reverse(arr,n);
    cout<<"Is it palindrome: "<<palindrome(arr,n)<<endl;
    cout<<"Is it not case sensitive palindrome: "<<checkPalindrome(arr,n)<<endl;
}