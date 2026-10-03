class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            
            int a1 = triplets[i][0];
            int a2 = triplets[i][1];
            int a3 = triplets[i][2];

            if(a1 <= target[0] && a2 <= target[1] && a3 <= target[2]){
                res.push_back(i);
            } 
        }

        bool gotX = false , gotY = false , gotZ = false;

        if(res.empty()){
            return false;
        }

        int m = res.size();
        for(int j = 0; j < m; j++){
            int ind = res[j];

            if(triplets[ind][0] == target[0]){ 
                gotX = true;
            }
            if(triplets[ind][1] == target[1]){ 
                gotY = true;
            }
            if(triplets[ind][2] == target[2]){ 
                gotZ = true;
            }
        }

        return gotX && gotY && gotZ;
    }
};