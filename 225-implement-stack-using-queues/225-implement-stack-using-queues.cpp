class MyStack {
public:
    vector<int> arr;
    MyStack() {
        
    }
    
    void push(int x) {
        arr.push_back(x);
    }
    
    int pop() {
        int x = arr[arr.size()-1];
        arr.pop_back();
        return x;        
    }
    
    int top() {
        return arr[arr.size()-1];
    }
    
    bool empty() {
        return arr.size()==0;
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