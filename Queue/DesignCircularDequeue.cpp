class MyCircularDeque {
public:
    vector<int> d;
    int front,rear,k;
    MyCircularDeque(int k) {
        d = vector<int>(k);
        front = -1;
        rear = -1;
        this->k = k;
    }
    
    bool insertFront(int value) {
        if(front == -1)
        {
            front++;
            rear++;
            d[front] = value;
        }
        else
        {
            if((rear + 1) % k == front)
            {
                return false;
            }

            front = (front -1 + k)%k;
            d[front] = value;

        }
        return true;
    }
    
    bool insertLast(int value) {
        if(rear == -1)
        {
            front ++;
            rear++;
            d[front] = value;
        }
        else
        {
            if((rear + 1) % k == front)
            {
                return false;
            }
            else
            {
                rear = (rear + 1) % k;
                d[rear] = value;
            }
        }
        
        return true;
    }
    
    bool deleteFront() {
        if(front == -1)
        {
            return false;
        }
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % k;
        }
        return true;
    }
    
    bool deleteLast() {
        if(rear == -1)
        {
            return false;
        }
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1 + k)%k;
        }
        return true;
    }
    
    int getFront() {
        if(front == -1) return -1;
        return d[front];
    }
    
    int getRear() {
        if(front == -1) return -1;
        return d[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % k == front;
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