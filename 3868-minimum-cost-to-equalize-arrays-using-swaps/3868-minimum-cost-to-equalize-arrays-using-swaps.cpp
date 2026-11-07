class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> fq1,fq2,fq3;

        for(auto x:nums1){
            fq1[x]++; 
            fq3[x]++;
        }

        for(auto x:nums2){
            fq2[x]++; 
            fq3[x]++;
        }

        for(auto it : fq3){
            if(it.second % 2 == 1)
                return -1;
        }

        int swaps = 0;

        for(auto it : fq3){
            if(fq1[it.first] == fq2[it.first]){
                continue;
            }
            
            swaps += abs(fq1[it.first] - (fq3[it.first]/2) );
        }
        
        return swaps/2;
    }
};