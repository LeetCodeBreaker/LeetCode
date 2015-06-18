#include <stdio.h>
#include <vector>
#include <algorithm> 

using namespace std;
class Solution {

    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> ans;
            vector<vector<int> > table;
            for(int i = 0; i < target; i++) {
                table.push_back(vector<int>());
            }
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] < target) {
                    table[nums[i] % target].push_back(i);
                }
            }

            for(int i = 1; i < target; i++) {
                for(int j = 0; j < table[i].size(); j++) {
                    for(int k = 0; k < table[target-i].size(); k++) {
                        if (nums[table[i][j]] + nums[table[target-1-i][k]] == target) {
                            ans.push_back(table[i][j]);
                            ans.push_back(table[target-i][k]);
                            sort(ans.begin(), ans.end());
                            return ans;
                        }
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
    test.push_back(2);
    test.push_back(4);
    test.push_back(3);
    ans = sol.twoSum(test, 6);
    printf("%d %d\n",ans[0], ans[1]);

    return 0;
}
