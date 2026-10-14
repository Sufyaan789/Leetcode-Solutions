class FreqStack {
public:
    unordered_map<int, int> cnt;
    vector<int> arr;
    FreqStack() {
        
    }
    
    void push(int val) {
        arr.push_back(val);
        cnt[val]++;
    }
    
    int pop() {
        int maxCnt = 0;
        for(auto it : cnt){
            maxCnt = max(maxCnt , it.second);
        }

        int i = arr.size() - 1;
        while(cnt[arr[i]] != maxCnt){
            i--;
        }

        int val = arr[i];
        arr.erase(arr.begin() + i);
        cnt[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */