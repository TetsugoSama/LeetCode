/*****************************************
 * 问题：
 * 给定一个整数数组 nums 和一个目标值 target，
 * 请你在该数组中找出和为目标值的那两个整数，并
 * 返回他们的数组下标。
 * 
 * 解决思路：
 * 将数组遍历一遍，把{target-nums[i],i}存入map
 * 若有nums[j] == target-nums[i],则输出{i，j}
******************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> n;
        for(int i=0;i<nums.size();i++)
        {
            if(n.find(nums[i])!=n.end())
            {
                return {n[nums[i]],i};
            }
            else
            {
                n.insert({target-nums[i],i});
            }
        }
        return {};
    }
};