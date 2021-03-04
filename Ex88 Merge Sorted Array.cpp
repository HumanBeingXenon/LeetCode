#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    print_vector(nums1);
    return 0;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i, j, k = m + n - 1;
    for (i = m - 1, j = n - 1; i >= 0 && j >= 0;)
    {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    if (i == -1)
        while (j >= 0)
            nums1[k--] = nums2[j--];
}