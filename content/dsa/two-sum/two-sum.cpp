#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                ans.push_back({nums[i], nums[j]});
            }
        }
    }
    return ans;
}

vector<vector<int>> twoSumHash(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    unordered_map<int, int> count;
    for (int num: nums) {
        int complement = target - num;
        if (count[num] > 0) {
            for (int c = 0; c < count[num]; ++c) {
                ans.push_back({num, complement});
            }
        }
        ++count[complement];
    }
    return ans;
}

// returns first position >= x
int getFirstPosition(vector<int> &nums, int x, int low) {
    int n = nums.size();
    int ans = n;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;

}

vector<vector<int>> twoSumBinarySearch(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        int cur = nums[i];
        int complement = target - cur;
        if (complement < cur) break;
        int firstPosition = getFirstPosition(nums, complement, i + 1);
        int lastPosition = getFirstPosition(nums, complement + 1, i + 1) - 1;
        if (firstPosition <= lastPosition) {
            int count = lastPosition - firstPosition + 1;
            while (count--) {
                ans.push_back({cur, complement});
            }
        }
    }
    return ans;
}


vector<vector<int>> twoSumTwoPointer(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int low = 0, high = n - 1;
    while (low < high) {
        if (nums[low] + nums[high] == target) {
            ans.push_back({nums[low], nums[high]});
        }
        if (nums[low] + nums[high] > target) {
            --high;
        } else {
            ++low;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 6, 5};
    int target = 7;
    vector<vector<int>> ans = twoSum(nums, target);
    for (vector<int> sumPair: ans) {
        cout << sumPair[0] << " " << sumPair[1] << ";";
    }
    cout << "\n";
    ans = twoSumBinarySearch(nums, target);
    for (vector<int> sumPair: ans) {
        cout << sumPair[0] << " " << sumPair[1] << ";";
    }
    cout << "\n";
    ans = twoSumHash(nums, target);
    for (vector<int> sumPair: ans) {
        cout << sumPair[0] << " " << sumPair[1] << ";";
    }
    cout << "\n";
    ans = twoSumTwoPointer(nums, target);
    for (vector<int> sumPair: ans) {
        cout << sumPair[0] << " " << sumPair[1] << ";";
    }
    cout << "\n";
}
