class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        
        // we didnt find any entry in our map
        if (mp.find(key) == mp.end()) {
            return "";
        }

        string ans = "";
        vector<pair<int , string>> &v = mp[key];
        int l = 0 , r = v.size() - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(v[mid].first <= timestamp){
                //ans exists but maybe a later timestamp also exists
                
                ans = v[mid].second;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */