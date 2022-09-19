class MyCircularQueue {
    
    public:
     vector<int> q;
    int front, rear, len=0;
    MyCircularQueue(int k) {
        q=vector<int>(k,-1);
        front=0;
        //init rear to be -1, so after enQueue first item, it becones 0
        rear =-1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        //take care of out of boundary
        int idx = (rear+1)%q.size(); 
        rear=idx;
        len++;
        q[rear]=value;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        len--;
        front= (front+1)%q.size();
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len==q.size();
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