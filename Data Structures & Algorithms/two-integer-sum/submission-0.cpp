class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            int first = nums[i];

            for(int j=i+1; j<n; j++){
                int second = nums[j];

                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
    }
};
