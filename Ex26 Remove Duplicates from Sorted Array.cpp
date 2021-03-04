#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

int removeDuplicates(vector<int> &nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {};
    int len = removeDuplicates(nums);
    cout << len << endl;
    return 0;
}

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int cnt = 1, prev = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != prev)
        {
            nums[cnt++] = nums[i];
            prev = nums[i];
        }
    }
    return cnt;
}
