class MyCircularDeque {
    private: 
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularDeque(int k) {
        arr=new int[k];
        size=k;
        front=rear=-1;
    }
    
    bool insertFront(int value) {
        //check first element
        if(front==-1){
            front=rear=0;
            arr[front]=value;
            return true;
        }

        //check full
        if(front==0 && rear==size-1 || rear==front-1){
            return false;
        }
        //maintain circular nature
        if(front==0){
            front=size-1;
        }
        else{
            //normal flow
            front--;
        }
        arr[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        //check first element
        if(rear==-1){
            front=rear=0;
            arr[rear]=value;
            return true;
        }
        //check full
        if(front==0 && rear==size-1 || rear==(front-1)){
            return false;
        }
        //maintain circlar nature
        if(rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }
    
    bool deleteFront() {
        //empty
        if(front==-1){
            return false;
        }
        //single element
        if(front==rear){
            front=rear=-1;
            return true;
        }
        if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
        //empty
        if(front==-1){
            return false;
        }
        //single element
        if(front==rear){
            front=rear=-1;
            return true;
        }
        if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(front==-1){
            //empty
            return -1;
        }
        return arr[front];
    }
    
    int getRear() {
        if(rear==-1){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(front==0 && rear==size-1 || rear==(front-1)%(size-1)){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */