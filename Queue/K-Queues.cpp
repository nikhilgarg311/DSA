// A C++ program to demonstrate implementation 
// of k queues in a single
// array in time and space efficient way
#include<iostream>
#include<climits>
using namespace std;

// A C++ class to represent k queues 
// in a single array of size n
class kQueues
{ 
	// Array of size n to store actual 
	// content to be stored in queue
	int *arr;

	// Array of size k to store indexes 
	// of front elements of the queue 
	int *front; 

	// Array of size k to store indexes 
	// of rear elements of queue
	int *rear; 

	// Array of size n to store next 
	// entry in all queues		 
	int *next; 
	int n, k;

	int free; // To store the beginning index of the free list

public:
	//constructor to create k queue 
	// in an array of size n
	kQueues(int k, int n);

	// A utility function to check if 
	// there is space available
	bool isFull() { return (free == -1); }

	// To enqueue an item in queue number 
	// 'qn' where qn is from 0 to k-1
	void enqueue(int item, int qn);

	// To dequeue an from queue number 
	// 'qn' where qn is from 0 to k-1
	int dequeue(int qn);

	// To check whether queue number
	// 'qn' is empty or not
	bool isEmpty(int qn) { return (front[qn] == -1); }
};

// Constructor to create k queues 
// in an array of size n
kQueues::kQueues(int k1, int n1)
{
	// Initialize n and k, and allocate
	// memory for all arrays
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];

	// Initialize all queues as empty
	for (int i = 0; i < k; i++)
		front[i] = -1;

	// Initialize all spaces as free
	free = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1; // -1 is used to indicate end of free list
}

// To enqueue an item in queue number 
// 'qn' where qn is from 0 to k-1
void kQueues::enqueue(int item, int qn)
{
	//check overflow
	if(free==-1){
	return;    
	}
	//find index
	int index=free;
	//update free
	free=next[free];
	//put in arr
	arr[index]=item;
	//update next
	next[rear[qn-1]]=index;
	next[index]=-1;
	//update rear
	rear[qn-1]=index;
	//update front only if first insert
  	if(front[qn-1]==-1)
    {
		front[qn-1]=index;
	}
	return;
}

// To dequeue an from queue number 'qn' where qn is from 0 to k-1
int kQueues::dequeue(int qn)
{
	//check underflow
	if(front[qn-1]==-1){
		return -1;
	}
	int index= front[qn-1];
	//check single element
	if(front[qn-1]==rear[qn-1]){
		front[qn-1]=rear[qn-1]=-1;
	}
	else{
		front[qn-1]=next[index];
	}
	next[index]=free;
	free=index;
	return arr[index];
}

/* Driver program to test kStacks class */
int main()
{
	// Let us create 3 queue in an array of size 10
	int k = 3, n = 10;
	kQueues ks(k, n);

	// Let us put some items in queue number 2
	ks.enqueue(15, 3);
	ks.enqueue(45, 3);

	// Let us put some items in queue number 1
	ks.enqueue(17, 2);
	ks.enqueue(49, 2);
	ks.enqueue(39, 2);

	// Let us put some items in queue number 0
	ks.enqueue(11, 1);
	ks.enqueue(9, 1);
	ks.enqueue(7, 1);

	cout << "Dequeued element from queue 2 is " << ks.dequeue(3) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(1) << endl;

	return 0;
}
