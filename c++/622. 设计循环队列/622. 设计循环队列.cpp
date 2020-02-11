class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int *que;
    int front;
    int rear;
    int k;
    MyCircularQueue(int k) {
        this->k = k + 1;
        que = new int[k + 1];
        front = 0;
        rear = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        que[front] = value;
        front = ( front + 1 ) % k;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        rear = (rear + 1) % k;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return que[(front + k - 1) % k];
    }
    
    /** Get the last item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return que[(rear + 1) % k];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (rear + 1) % k == front;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return front == rear;
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