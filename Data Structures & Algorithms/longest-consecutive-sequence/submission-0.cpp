class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());

        int longest = 0;
        for(int nums : st){
            if(st.find(nums-1) == st.end()){
                 int currentnums = nums;
                 int lenght = 1;

                 while(st.find(currentnums+1) != st.end()){
                    currentnums++;
                    lenght++;
                 }
                  longest = max(longest, lenght);
            }
        } 
        return longest;
    }
};