class MyCalendar {
public:
    vector<vector<int> > data;
    
    MyCalendar() { 
        //this->data=new vector<vector<int>() >();
    }
    
    bool book(int start, int end) {
        for(int i=0;i<this->data.size();i++)
        {
            if(this->data[i][0] < end && this->data[i][1] > start) return false;
        }
        data.push_back(vector<int>({start,end}));
        return true;
    }
    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */