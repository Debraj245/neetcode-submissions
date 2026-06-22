class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxwater = 0;
        int lp = 0, rp = heights.size()-1;

        while(lp < rp){
            int w = rp - lp;
            int ht = min(heights[lp], heights[rp]);
            int currentwater = w * ht;

            maxwater = max(maxwater, currentwater);

            if(heights[lp] < heights[rp]){
                lp++;
            }else{
                rp--;
            }
        }
        return maxwater;
    }
};
