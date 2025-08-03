/* Online C++ Compiler and Editor */
#include <iostream>
#include <string>
#include <array>
using namespace std;

int power( int x, int n){
    if(n==0){
        return 1;
    }
    
    return x*power(x,n-1);
}

int factorial( int x){
    if(x==0){
        return 1;
    }
    
    return x*factorial(x-1);
}

int fibonacci(int prev1,int prev2, int x){
  if(x==0){
      return prev1;
  }
  if(x==1){
      return prev2;
  }
  
  int third=prev1+prev2;
  prev1=prev2;
  prev2=third;
  
  return fibonacci(prev1,prev2,x-1);
}

void reverse(int i,int j,string &s){
    
    if(i>j){
        return;
    }
    swap(s[i],s[j]);
    return reverse(i+1,j-1,s);
}

bool checkPalindrome(int i, int j, string s){
    if(i==j){
        return true;
        
    }
    
    if(s[i]!=s[j]){
        return false;
    }
    else{
        return checkPalindrome(i+1,j-1,s);
    }
    
}

int binarySearch(int arr[],int size, int n){
    if(size==0){
        return -1;
    }
    int mid=size/2;
    if(arr[mid]==n){
        return mid;
    }
    else if(arr[mid]>n){
        return binarySearch(arr,size-mid-1,n);
    }
    else if(arr[mid]<n){
        return binarySearch(arr+mid+1,size-mid,n);
    }
    else{
        return -1;
    }
}

bool linearSearch(int arr[],int size,int n){
    if(size==0){
        return false;
    }
    
    if(arr[0]==n){
        return true;
    }
    
    return linearSearch(arr+1,size-1,n);
}

void sayDigits(int num, string arr[]){
    if(num/10==0){
        cout<<arr[num]<<" ";
        return;
    }
    
    
    sayDigits(num/10,arr);
    cout<<arr[num%10]<<" ";
    return;
}

int sumOfArray(int arr[], int &sum,int size){
    if(size==0){
        return sum;
    }
    if(size==1){
        return (sum+arr[0]);
    }
    sum=arr[0]+sum;
    return sumOfArray(arr+1,sum,size-1);
    
}

void bubbleSort(int *arr,int size){
    if(size==0||size==1){
        return;
    }
    
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    
    return bubbleSort(arr,size-1);
    
    
}


int main()
{
   cout << "Hello World" << endl; 
//   int x,n;
//   string s;
//   cin>>x>>n;
//   cout<<"power is:"<<power(x,n)<<endl;
//   cout<<"factorial is:"<<factorial(x)<<endl;
//   cout<<"fibonacci sum is:"<<fibonacci(0,1,x);
//   cin>>s;
//   reverse(0,s.length()-1,s);
//   cout<<"Reverse of string is:"<<s;
//   string s;
//   cin>>s;
//  cout<<checkPalindrome(0,s.length()-1,s);
//  int arr[6]={121,22,13,60,191,0};
//  cout<<binarySearch(arr,6,90)<<endl;
//  cout<<linearSearch(arr,6,9)<<endl;
//  string arr[10]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
//  sayDigits(123456780,arr);
//  int sum=0;
//  cout<<"Sum of Array: "<<sumOfArray(arr,sum,6);
//  bubbleSort(arr,6);
//  for(int i=0;i<6;i++){
//     cout<<arr[i]<<" ";
//  }
//  cout<<endl;
   return 0;
}