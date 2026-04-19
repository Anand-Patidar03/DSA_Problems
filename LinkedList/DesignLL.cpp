class MyLinkedList {
public:
        struct Node
        {
            int data;
            Node *next;
        };
        Node *start = nullptr;
    MyLinkedList() {
    }
    
    int get(int index) {
        Node *s = start,*q=start;
        int count=0;
        while(q!=nullptr)
        {
            count++;
            q = q->next;
        }
        if(index>=count)
        {
            return -1;
        }
        while(s!=nullptr && (index)--)
        {
            s = s->next;
        }
        return s->data;
    }
    
    void addAtHead(int val) {
        Node *rear;
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if(start == nullptr)
        {
            start = newNode;
        }
        else
        {
            newNode->next = start;
            start = newNode;
        }
    }
    
    void addAtTail(int val) {
        Node *rear = start;
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if(start == nullptr)
        {
            start = newNode;
        }
        else
        {
            while(rear->next != nullptr)
            {
                rear = rear->next;
            }

            rear->next = newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        Node *p,*q = start;
        Node *s = start;
        int count=0;
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        while(q!=nullptr)
        {
            count++;
            q = q->next;
        }
        if(index>count)
        {
            return;
        }
        if(index == 0)
        {
            newNode->next = start;
            start = newNode;
            return;
        }
        int n = index-1;
        while(s!=nullptr && (n)--)
        {
            s = s->next;
        }
        p = s->next;
        

        s->next = newNode;
        newNode->next = p;
    }
    
    void deleteAtIndex(int index) {
        Node *p,*q = start;
        Node *s = start;
        int count=0;
        while(q!=nullptr)
        {
            count++;
            q = q->next;
        }
        if(index>=count)
        {
            return;
        }
        if(index == 0)
        {
            start = start->next;
            return;
        }
        int n = index-1;
        while(s!=nullptr && n--)
        {
            s = s->next;
        }
        p = s->next;
        if(p!=nullptr)
        s->next = p->next;
        else
        s->next = nullptr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */