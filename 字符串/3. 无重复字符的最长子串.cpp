/****************************************************************
 * 问题：
 * 给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
 * 
 * 解决思路：
 * 左右两个指针，一个哈希桶。当右指针所指字符不在桶内时，右指针移动，
 * 并把字符放进桶内。当右指针所指字符在桶内时，右指针不动，左指针移动，
 * 并把所指字符从桶内取出。
 *****************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool* c = new bool[128]();
        int res = 0;
        int lp = 0,rp = 0;
        while(lp<s.size())
        {
            while(rp<s.size()&&c[s[rp]]==0)
            {
                c[s[rp]] = 1;
                ++rp;
            }
            res = max(res,rp-lp);
            c[s[lp]] = 0;
            ++lp;
        }
        res = max(res,rp-lp);
        delete []c;
        return res;
    }
};


int main()
{
    string s = "pwwkew";
    cout<<Solution().lengthOfLongestSubstring(s)<<endl;
}