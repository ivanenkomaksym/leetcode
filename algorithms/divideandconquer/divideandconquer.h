#include <iostream>

using namespace std;

namespace Algorithms::DivideAndConquer
{
    void merge(vector<int> &input, int leftStart, int leftEnd, int rightStart, int rightEnd)
    {
        auto origStart = leftStart;
        auto output = std::vector<int>(rightEnd - leftStart + 1);

        auto i = 0;
        auto leftEmpty = false;
        auto rightEmpty = false;
        while (!leftEmpty || !rightEmpty)
        {
            if (!leftEmpty && !rightEmpty)
            {
                if (input[leftStart] > input[rightStart])
                    output[i++] = input[rightStart++];
                else
                    output[i++] = input[leftStart++];
            }
            else if (leftEmpty)
                output[i++] = input[rightStart++];
            else
                output[i++] = input[leftStart++];

            leftEmpty = leftStart > leftEnd;
            rightEmpty = rightStart > rightEnd;
        }
       
        for (auto j = 0, i = origStart; j < output.size(); i++, j++)
            input[i] = output[j];
    }

    void mergeSort(vector<int> &input, int start, int end)
    {
        if (start == end)
            return;
        else if (start == end - 1)
        {
            if (input[start] > input[end])
                swap(input[start], input[end]);

            return;
        }

        auto mid = (start + end) / 2;
        mergeSort(input, start, mid);
        mergeSort(input, mid + 1, end);

        merge(input, start, mid, mid + 1, end);
    }

    vector<int> mergeSort(vector<int> input)
    {
        mergeSort(input, 0, input.size() - 1);
        return input;
    }

    vector<int> quickSort(vector<int> &input)
    {
        if (input.size() < 2)
            return input;

        auto pivot = input[0];
        auto less = std::vector<int>{};
        auto greater = std::vector<int>{};
        auto output = std::vector<int>();
        std::copy_if(input.begin() + 1, input.end(), std::back_inserter(less), [pivot](auto &el) { return el <= pivot; });
        less = quickSort(less);
        std::copy_if(input.begin() + 1, input.end(), std::back_inserter(greater), [pivot](auto &el) { return el > pivot; });
        greater = quickSort(greater);
        std::copy(less.begin(), less.end(), std::back_inserter(output));
        output.push_back(pivot);
        std::copy(greater.begin(), greater.end(), std::back_inserter(output));

        return output;
    }

    /*
    973. K Closest Points to Origin
    Medium

    Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

    The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

    You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
    */
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k >= points.size())
            return points;
        
        auto m = std::map<int, vector<vector<int>>>{};
        
        for (auto point: points)
        {
            auto d = point[0] * point[0] + point[1] * point[1];
            m[d].push_back(point);
        }

        auto output = vector<vector<int>>{};
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second.size() > k)
            {
                std::copy(it->second.begin(), it->second.begin() + k, std::back_inserter(output));
                return output;
            }
            
            std::copy(it->second.begin(), it->second.end(), std::back_inserter(output));
            k -= it->second.size();
        }
        
        return output;
    }

    void run()
    {
        
        std::cout << "[Algorithms][DivideAndConquer]  Start" << std::endl;

        {
            auto v = std::vector<int>{32,27,43,3,9,82,10,41,7,1};
            auto expected = std::vector<int>{1,3,7,9,10,27,32,41,43,82};

            auto result = mergeSort(v);

            assert(result == expected);

            std::cout << "  [PASSED] Merge sort" << std::endl;
        }
        
        {
            auto v = std::vector<int>{32,27,43,3,9,82,10,41,7,1};
            auto expected = std::vector<int>{1,3,7,9,10,27,32,41,43,82};

            auto result = quickSort(v);

            assert(result == expected);

            std::cout << "  [PASSED] Quick sort" << std::endl;
        }
        
        {
            auto v = std::vector<std::vector<int>>{{3,3},{5,-1},{-2,4}};
            auto expected = std::vector<std::vector<int>>{{3,3},{-2,4}};

            auto result = kClosest(v, 2);

            assert(result == expected);

            std::cout << "  [PASSED] 973. K Closest Points to Origin" << std::endl;
        }

        std::cout << "[Algorithms][DivideAndConquer]  End" << std::endl;
    }
}