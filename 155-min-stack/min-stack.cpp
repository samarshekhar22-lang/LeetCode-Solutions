class Node{
    public:
       int data;
       int current_min;
       Node* next;

       Node(int val, int cur_min){
        data=val;
        current_min=cur_min;
        next=nullptr;
       }
};



class MinStack {
public:
     Node*top1;
    MinStack() {
        top1=nullptr;
    }
    
    void push(int value) {
        int new_min;
        if(top1==nullptr){
            new_min=value;
        }else{
            new_min=min(value,top1->current_min);
        }
        Node*temp=new Node(value,new_min);
        temp->next=top1;
        top1=temp;
    }
    
    void pop() {
        if(top1==nullptr) return;
        Node*temp=top1->next;
        delete top1;
        top1=temp;
    }
    
    int top() {
        return top1==nullptr?-1:top1->data;
    }
    
    int getMin() {
        return top1==nullptr?-1:top1->current_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */