#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int factorial(int x)
    {
        int n = x;
        int prod = 1;
        while (n != 0)
        {
            prod *= (n--);
        }
        return prod;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int numsLength = nums.size();
        int length = factorial(numsLength);

        vector<vector<int>> results;

        do
        {
            results.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return results;
    }
};

int main()
{
    vector<int> nums;
    Solution soln;
    int length;

    cout << "Enter the length of the array: ";
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    vector<vector<int>> permutations = soln.permute(nums);

    cout << "Permutations: " << endl;

    cout << "[";
    for (const auto &perm : permutations)
    {
        cout << "[";
        for (int num : perm)
        {
            cout << num << ",";
        }
        cout << "],";
    }
    cout << "]";

    return 0;
}
