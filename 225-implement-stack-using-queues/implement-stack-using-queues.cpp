class MyStack {
private:
    queue<int>q1;
public:
    MyStack() {        
    }
    
    void push(int x) {
        q1.push(x);
        int n=q1.size();
        for(int i=0;i<n-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    int pop() {
        int top1=q1.front();
        q1.pop();
        return top1;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */