class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int sgas = 0 , scost = 0;
        for(int i = 0; i < gas.size(); i++){
            sgas += gas[i];
            scost += cost[i];
        }

        if(sgas - scost < 0){
            return -1;
        }

        int res = 0;
        int total = 0;

        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];

            if(total < 0){
                res = i + 1;
                total = 0;
            }
        }

        return res;  
    }
};