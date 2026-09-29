class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        int ans = 1;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            /*part of this sequence -- basically means that the number below it (num - 1) was found in the 
                set , and we can start our sequence from here */
            if(st.find(it - 1) == st.end()){
                //the above if condition simply means that the value of it - 1 is not present in the set
                int cnt = 1;
                int x = it;

                while(st.find(x + 1) != st.end()){
                    /* the above while condition means does x + 1 exist in the set , if the condition is true,
                        the while loop is executed */
                    x = x + 1;
                    cnt = cnt + 1;
                }

                ans = max(ans , cnt);
            }
        }

        return ans;
    }
};