#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs);
string longestCommonPrefix2(vector<string> &strs);
string longestCommonPrefix3(vector<string> &strs);
string longestCommonPrefix4(vector<string> &strs);

int main(int argc, char const *argv[])
{
    vector<string> strs = {"leets", "leetcode", "leetc", "leeds"};
    //cout << longestCommonPrefix(strs) << endl;
    //cout << longestCommonPrefix2(strs) << endl;
    //cout << longestCommonPrefix3(strs) << endl;
    cout << longestCommonPrefix4(strs) << endl;
    return 0;
}

///A function that finds out the longest common prefix of two strings
///
string lcp(string s1, string s2)
{
    int length = min(s1.size(), s2.size());
    for (int idx = 0; idx < length; idx++)
        if (s1[idx] != s2[idx])
            return s1.substr(0, idx);
    return s1.substr(0, length);
}

///Compute the lcp of strings in vector one by one, LCP = lcp(lcp(lcp(lcp(s0,s1),s2),s3),...)
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";

    int size = strs.size();
    string prefix = strs[0];
    for (int i = 1; i < size; i++)
    {
        prefix = lcp(prefix, strs[i]);
    }
    return prefix;
}

///Compute lcp by comparing whether the letters of different strings are the same at the same index.
///e.g.
///s0: flower
///s1: flow
///s2: flight
///____√√×
string longestCommonPrefix2(vector<string> &strs)
{
    if (strs.empty())
        return "";

    int length = strs[0].size(), size = strs.size();
    for (int i = 0; i < length; i++)
    {
        char c = strs[0][i];
        for (int j = 0; j < size; j++)
        {
            if (i == strs[j].size() || strs[j][i] != c)
                return strs[0].substr(0, i);
        }
    }
    return strs[0];
}

///A helper function used in longestCommonPrefix3, which divides the interval and recurse.
string longest_common_prefix_helper(vector<string> &strs, int begin, int end)
{
    if (begin == end)
    {
        return strs[begin];
    }
    else
    {
        int mid = (begin + end) / 2;
        string left_lcp = longest_common_prefix_helper(strs, begin, mid);
        string right_lcp = longest_common_prefix_helper(strs, mid + 1, end);
        return lcp(left_lcp, right_lcp);
    }
}

///A improved algorithm of longestCommonPrefix, compute by partition
///[begin                   mid] [mid+1                   end]
///[begin    mid] [mid+1    end] [begin    mid] [mid+1    end]
string longestCommonPrefix3(vector<string> &strs)
{
    if (strs.empty())
        return "";
    else
        return longest_common_prefix_helper(strs, 0, strs.size() - 1);
}

bool is_common_prefix(vector<string> &strs, int length)
{
    string s0 = strs[0].substr(0, length);
    for (int i = 1; i < strs.size(); i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (s0[j] != strs[i][j])
                return false;
        }
    }
    return true;
}

///
string longestCommonPrefix4(vector<string> &strs)
{
    if (strs.empty())
        return "";

    int min_length = INT_MAX;
    for (string s : strs)
    {
        int len = s.size();
        min_length = min(min_length, len);
    }

    int low = 0, high = min_length;
    while (low < high)
    {
        int mid = (high - low + 1) / 2 + low;
        if (is_common_prefix(strs, mid))
            low = mid;
        else
            high = mid - 1;
    }
    return strs[0].substr(0, low);
}