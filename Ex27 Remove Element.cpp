#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

int removeElement(vector<int> &nums, int val);

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int size = removeElement(nums, 2);
    cout << size << endl;
    print_vector(nums, size);
    return 0;
}

int removeElement(vector<int> &nums, int val)
{
    int size = nums.size();
    for (int i = 0; i < size;)
    {
        if (nums[i] != val)
        {
            i++;
        }
        else
        {
            swap(nums[i], nums[size-1]);
            size--;
        }
    }
    return size;
}
