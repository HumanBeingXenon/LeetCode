#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

int removeDuplicates(vector<int> &nums);

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 5, 6, 7};
    int size = removeDuplicates(v);
    cout << size << endl;
    print_vector(v, size);
    return 0;
}

int removeDuplicates(vector<int> &nums)
{
    int size = nums.size();
    if (size <= 2)
        return size;

    int slow = 2;
    for (int fast = 2; fast < size; fast++)
    {
        if (!(nums[fast] == nums[slow - 1] && nums[fast] == nums[slow - 2]))
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}
