class Solution {
private:
    int area(int i, int j, vector<int>& height) {
        int len = j - i;
        int breadth = min(height[i] , height[j]);
        return len * breadth;
    }

public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea1 = 0;

        while (i < j) {
            maxArea1 = max(maxArea1 , area(i , j , height));
            if(height[i] < height[j]){
                i++;
            }
            else if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }

        return maxArea1;
    }
};