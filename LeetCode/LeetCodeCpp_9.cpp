/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/
class Solution
{
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string sr = s;
        std::reverse(sr.begin(),sr.end());
        if(s == sr)
            return true;
        else
            return false;
    }
};
