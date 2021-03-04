#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

void sortColors(vector<int> &nums);
void sortColors2(vector<int> &nums);

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0, 2, 1, 1, 0, 0, 1, 1, 1, 2, 2, 2};
    sortColors2(nums);
    print_vector(nums);
    return 0;
}

void sortColors(vector<int> &nums)
{
    int cnt[3] = {0}, size = nums.size();
    for (int i = 0; i < size; i++)
        cnt[nums[i]]++;
    for (int i = 0, idx = 0; i < 3; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
            nums[idx++] = i;
    }
}

void sortColors2(vector<int> &nums)
{
    int size = nums.size();
    if (size < 2)
        return;

    int ptr_left = 0, ptr_right = size - 1;
    for (int i = 0; i <= ptr_right;)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[ptr_left]);
            ptr_left++;
            i++;
        }
        else if (nums[i] == 1)
        {
            i++;
        }
        else
        {
            swap(nums[i], nums[ptr_right]);
            ptr_right--;
        }
    }
}