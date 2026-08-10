class MyQueue {
     stack<int> s1,s2;
public:
    MyQueue() {
        this->s1 = {};
        this->s2 = {};
    }
    
    void push(int x) {
         if(s1.empty()){
            s1.push(x);
         }else{
         while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
         }
         s2.push(x);
          while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
          }}
          return;
        
    }
    
    int pop() {
        if(s1.empty()) return -1;
        int ans = s1.top();
        s1.pop();
        return ans;
        
    }
    
    int peek() {
        if(s1.empty()) return -1;
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */