class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int sz = nums.size();
        if(sz == 0){
            return ans;
        }
        int tmp = nums[0];

        for(int i=0; i<sz; i++){
            if(i == sz-1 || nums[i]+1 != nums[i+1]){
                if(nums[i] != tmp){
                    ans.push_back(to_string(tmp) + "->" + to_string(nums[i]));
                }
                else{
                    ans.push_back(to_string(tmp));
                }
                if(i != sz-1){
                    tmp = nums[i+1];
                }
            }
        }
        return ans;
    }
};
