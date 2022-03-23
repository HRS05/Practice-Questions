class FreqStack {
private:
    map<int,int> freq;
    map<int,stack<int> > group;
    int maxfreq;
public:
    FreqStack() 
    {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxfreq=max(maxfreq,freq[val]);
        group[freq[val]].push(val);
    }
    
    int pop() {
        int val = group[maxfreq].top();
        group[maxfreq].pop();
        if (!group[freq[val]--].size()) maxfreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */