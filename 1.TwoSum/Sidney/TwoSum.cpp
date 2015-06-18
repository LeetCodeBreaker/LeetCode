#include <stdio.h>
#include <vector>
#include <algorithm> 

using namespace std;
class Solution {

    public:
        int find(vector<int>& nums, int target)
        {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == target) {
                    return i+1;
                }
            }
        }
        int find_reverse(vector<int>& nums, int target)
        {
            for(int i = nums.size()-1 ; i>=0; i--) {
                if(nums[i] == target) {
                    return i+1;
                }
            }
        }

        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> ans;
            vector<int> nums_sorted = nums;

            sort(nums_sorted.begin(), nums_sorted.end());

            for(int i = 0; i < nums_sorted.size(); i++) {
                for(int j = i+1; j < nums_sorted.size(); j++) {
                    if(nums_sorted[i] + nums_sorted[j] == target) {
                        ans.push_back(find(nums, nums_sorted[i]));
                        ans.push_back(find_reverse(nums, nums_sorted[j]));
                        sort(ans.begin(), ans.end());
                        return ans;
                    }
                }
            }

        }

};

int main()
{
    vector<int> test;
    vector<int> ans;
    Solution sol;
    test.push_back(3);
    test.push_back(2);
    test.push_back(4);
    ans = sol.twoSum(test, 6);
    printf("%d %d\n",ans[0], ans[1]);

    return 0;
}


