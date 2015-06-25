class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> origin = nums;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j]>target)
                {
                    j = nums.size();
                }
                else if(nums[i]+nums[j]==target)
                {
                    vector<int> result;
                    for(int k=0; k<origin.size(); k++)
                    {
                        if(origin[k]==nums[i])
                        {
                            result.push_back(k+1);
                            break;
                        }
                    }
                    for(int k=0; k<origin.size(); k++)
                    {
                        if(origin[k]==nums[j]&&k+1!=result[0])
                        {
                            result.push_back(k+1);
                            break;
                        }
                    }
                    if(result[0]>result[1])
                    {
                        int k =result[0];
                        result[0] = result[1];
                        result[1] = k;
                    }
                        
                    return result;
                }
                
            }
        }
    }
};