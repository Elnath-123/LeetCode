class MyCircularDeque {
private:
    struct Node{
        int value;
        Node* prev;
        Node* next;
        Node(int value, Node* prev = NULL, Node* next = NULL) : value(value), prev(prev), next(next){}
        Node(){}
    };
    Node *front;
    Node *rear;
    int size;
    int k;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        this->k = k;
        front = rear = NULL;
        size = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        
        if(isFull()) return false;
        if(isEmpty()){
            Node* node = new Node(value);
            front = node;
            rear = node;
        }else{
            Node* node = new Node(value, front);
            front->next = node;
            front = node;
        }
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            Node* node = new Node(value);
            rear = node;
            front = node;
        }else{
            Node* node = new Node(value, NULL, rear);
            rear->prev = node;
            rear = node;
        }
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
         if(isEmpty()) return false;
         Node* temp = front;
         front = front->prev;
         delete temp;
         size--;
         return true;
         
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        Node* temp = rear;
        rear = rear->next;
        delete temp;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return front->value;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return rear->value;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == k;
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