/* 
* @brief: You are given n activities with their start and finish times. 
*       Select the maximum number of activities that can be performed by a single processor, 
*       assuming that a processor can only work on a single activity at a time. 
* @author: atharvakadlag
* @date: 10/04/2021
*/

#include <bits/stdc++.h>
using namespace std;

void display(vector<pair <int, int>> times) {
    for (auto i: times) {
        cout << i.first << " -> " << i.second << endl;
    }
}

bool sort_key(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

vector<pair <int, int>> get_jobs(vector<pair <int, int>> times) {
    sort(times.begin(), times.end(), sort_key);
    
    vector<pair <int, int>> possible_times;
    possible_times.push_back(times[0]);

    int i = 0;
    for (int j = 1; j < times.size(); ++j) {
        if (times[j].first >= times[i].second) {
            possible_times.push_back(times[j]);
            i = j;
        }
    }

    return possible_times;
}

int main() {
    vector<pair <int,int>> times = {
        {1,2}, {8,9}, {5,9}, {3,4}, {0,6}, {5,7}
    };
    auto possible_times = get_jobs(times);
    cout << "Following jobs have been selected: " << endl;
    display(possible_times);
}