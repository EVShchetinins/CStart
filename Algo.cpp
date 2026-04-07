#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
//Two Pointers 

//расширение индексов O(n^2) O(1)
struct biggestPolindrom
{
    std::string longestPalindrome(std::string s)
    {
        int start = 0;
        int max_length = 1;

        auto extention = [&](int left, int right)
            {
                while (left >= 0 && right <= s.length() && (s[left] == s[right]))
                {
                    auto cur_length = right - left + 1;
                    if (cur_length > max_length)
                    {
                        max_length = cur_length;
                        start = left;
                    }
                    right++;
                    left--;
                }
            };
        for (auto i = 0; i < s.length(); i++)
        {
            extention(i, i);
            extention(i, i + 1);
        }
        return s.substr(start, max_length);
    }

    void func()
    {
        std::cout << longestPalindrome("babad") << std::endl;
        std::cout << longestPalindrome("babab") << std::endl;
        std::cout << longestPalindrome("babbad") << std::endl;
    }
};

//standard two point O(N) O(1)
struct water
{
    int maxArea(std::vector<int>& height)
    {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        int minH = 0;
        while (left < right)
        {
            int current_height = std::min(height[left], height[right]);
            int current_water = current_height * (right - left);

            max_water = std::max(max_water, current_water);
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return max_water;
    }

    void func()
    {
        std::vector<int> a{ 1,8,6,2,5,4,8,3,7 };
        std::vector<int> b{ 0,0,0,1 };
        std::vector<int> c{ 1,1 };
        std::cout << maxArea(a) << std::endl;
        std::cout << maxArea(b) << std::endl;
        std::cout << maxArea(c) << std::endl;
    }
};

//O(n^2) O(1)/O(logN) на сортировку + O(k) на результат (количество триплетов)
struct treeSum
{
    std::vector<std::vector<int>> threeSumWitoutAnyDublicate(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> sums;
        std::sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums.size() < 3)
            return sums;

        for (auto i = 0; i < nums.size()-2; i++)
        {
            if (nums[i] > 0) break;
            if ((i > 0) && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                auto sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    sums.push_back({ nums[i],nums[left],nums[right] });
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (sum > 0)
                    right--;
                else
                    left++;
            }
        }
        return sums;
    }

    void func_full()
    {
        std::vector<std::vector<int>> tests = {
     { -1,0,1,2,-1, -4 },
     {-2, 0, 0, 2, 2},
     {-5, -4, -3, 1, 2},
     {0, 0, 0, 0}
        };
        for (auto& test : tests)
        {
            auto result = threeSumWitoutAnyDublicate(test);
            for (const auto& triplet : result)
            {
                for (auto num : triplet)
                    std::cout << num << " ";
                std::cout << " | ";
            }
            std::cout << std::endl;
        }
    }

    //O(n^2) & O(1)+O(logN)  на сортировку
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        std::ranges::sort(nums);
        if (nums.size() < 3)
            return 0;

        int close_sum = nums[0] + nums[1] + nums[2];
        for (auto i = 0; i < nums.size() - 2; i++)
        {
            if ((i > 0) && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (right > left)
            {
                auto cur_sum = nums[i] + nums[left] + nums[right];
                if (cur_sum == target)
                    return cur_sum;
                if (std::abs(target - cur_sum) < std::abs(target - close_sum))
                    close_sum = cur_sum;
                if (cur_sum > target)
                {
                    while ((left < right) && nums[right] == nums[right - 1]) right--;
                    right--;
                }
                else
                {
                    while ((left < right) && nums[left] == nums[left + 1]) left++;
                    left++;
                }
            }
        }
        return close_sum;
    }

    void func_tar()
    {
        std::vector<std::pair<std::vector<int>, int>> tests = {
        {{ -1,0,1,2,-1}, 2},
        {{ -2, 0, 0, 2, 2 }, 0 },
        {{-5, -4, -3, 1, 2},-2},
        {{0, 0, 0, 0}, 0},
        {{-1,2,1,-4}, 1}
        };
        for (auto& test : tests)
        {
            auto result = threeSumClosest(test.first, test.second);
            std::cout << result << std::endl;
        }
    }
    //O(n^3) O(k) + O(1) наши перемнные /O(logN) сортировка
    std::vector<std::vector<int>> forSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4)
            return result;
        std::ranges::sort(nums);

        for (int i = 0; i < n - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i + 1]) continue;
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;

            for (int j = i + 1; j < n - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right)
                {
                    long long cur_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (cur_sum == target)
                    {
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                    else if (cur_sum < target)
                    {
                        left++;
                    }
                    else
                        right--;
                }
            }
        }
        return result;
    }

};