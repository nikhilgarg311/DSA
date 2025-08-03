class MyCircularQueue {
    private:
        int *arr;
        int size;
        int front;
        int rear;
public:
    MyCircularQueue(int k) {
        arr=new int[k];
        size=k;
        front=-1;rear=-1;
    }
    
    bool enQueue(int value) {
        if(front==-1){
            //first push op
            front=rear=0;
            arr[front]=value;
            return true;
        }
        if(front==0 && rear==(size-1) || rear==(front-1)%(size)){
            //queue is full;
            return false;
        }
        else{
            rear=(rear+1)%(size);
            arr[rear]=value;
            return true;
        }
    }
    
    bool deQueue() {
        if(front==-1){
            //queue is empty
            return false;
        }
        if(front==rear){
            //single element in queue
            front=rear=-1;
        }
        else{
            front= (front+1)%(size);
        }
        return true;

    }
    
    int Front() {
        if(front==-1){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(rear==-1){
            //queue is empty
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(front==0 && rear==(size-1) || rear==(front-1)%(size-1)){
            //queue is full;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */