/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> numMap;
        vector<int> result = {0, 0};
        for (int i = 0; i < nums.size(); i++)
        {
            int ind = target - nums[i];
            if (numMap.count(ind) > 0)
            {
                result[0] = numMap[ind];
                result[1] = i;
                break;
            }
            numMap[nums[i]] = i;
        }
        return result;
    }
};
// @lc code=end
