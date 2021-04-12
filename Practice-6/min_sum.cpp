/* 
* @brief: Given an array of size n and a number k. We must modify array K number of times. 
*       Here modify array means in each operation we can replace any array element arr[i] by -arr[i]. 
*       We need to perform this operation in such a way that after K operations, sum of array must be maximum
* @author: atharvakadlag
* @date: 10/04/2021
*/

#include <bits/stdc++.h>
using namespace std;

int min_sum(vector<int> arr, int k) {
    for (int i = 1; i <= k; i++) {
        int min = INT_MAX;
        int index = -1;

        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
 
        arr[index] *= -1;
    }

    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return sum;
}

int main() {
    vector<int> arr {-2, 0, 5, -1, 2};
    int k = 4;
    cout << min_sum(arr, k) << endl;
    return 0;
}