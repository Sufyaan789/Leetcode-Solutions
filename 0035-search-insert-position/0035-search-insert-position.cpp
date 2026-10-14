class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int start = 0;
        int end = size - 1;

        while (start <= end) {
            int mid =
                start + (end - start) / 2; // Recalculate mid each iteration

            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        // Return the insertion position if target is not found
        return start;
    }
};