/* 
* @brief: Find the minimum sum of Products of two arrays of the same size, 
*        given that k modifications are allowed on the first array. 
*        In each modification, one array element of the first array 
*        can either be increased or decreased by 2.
* @logic: We maximize the difference we can make by decreasing or increasing an element by 2*k
* @author: atharvakadlag
* @date: 10/04/2021
*/

#include <bits/stdc++.h>
using namespace std;

int min_sop(vector<int> a, vector<int> b, int k) {
    int sop = 0, diff = 0;
    int size = a.size();
    for (int i = 0; i < size; i++) {
        int local_min = 0;

        int current_prd = a[i] * b[i];
        sop += current_prd;

        if (current_prd < 0 && a[i] > 0) {
            local_min = (a[i] + 2 * k) * b[i];
        } 
        else if (current_prd < 0 && a[i] < 0) {
            local_min = (a[i] - 2 * k) * b[i];
        } 
        
        else if (current_prd > 0 && a[i] < 0) {
            local_min = (a[i] + 2 * k) * b[i];
        } 
        else if (current_prd > 0 && a[i] > 0) {
            local_min = (a[i] - 2 * k) * b[i];
        }

        int current_diff = abs(current_prd - local_min);
        if (current_diff > diff) {
            diff = current_diff;
        }
    }
    return sop - diff;
}

int main() {
    vector<int> a {2, 3, 4, 5, 4};
    vector<int> b {3, 4, 2, 3, 2};
    int k = 3;
    cout << min_sop(a, b, k) << endl;
    return 0;
}