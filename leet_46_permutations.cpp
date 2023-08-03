#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int factorial(int x)
    {
        if (x <= 1)
            return 1;
        return x * factorial(x - 1);
    }

    // Custom comparator for next_permutation
    struct Compare
    {
        bool operator()(const int &a, const int &b) const
        {
            if (a >= 0 && b < 0)
                return true;
            if (a < 0 && b >= 0)
                return false;
            return a < b;
        }
    };

    vector<vector<int>> permute(vector<int> &nums)
    {
        int numsLength = nums.size();
        int length = factorial(numsLength);

        vector<vector<int>> results;

        sort(nums.begin(), nums.end(), Compare());

        do
        {
            results.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end(), Compare()));

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
