#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class EventManager
{
private:
    vector<pair<int, int>> events = {};

    static bool lambda(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second != b.second)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    };

public:
    EventManager(vector<vector<int>> &events)
    {
        for (int i = 0; i < events.size(); i++)
        {
            this->events.push_back({events[i][0], events[i][1]});
        }
        sort((this->events.begin()), (this->events.end()), lambda);
    }

    void updatePriority(int eventId, int newPriority)
    {
        int pos = -1;
        for (int i = 0; i < events.size(); i++)
        {
            if (events[i].first == eventId)
            {
                events[i].second = newPriority;
                pos = i;
                break;
            }
        }

        if (pos == -1)
            return;

        pair<int, int> target = events[pos];

        while (pos < (int)events.size() - 1 && lambda(events[pos + 1], target))
        {
            events[pos] = events[pos + 1];
            pos++;
        }

        while (pos > 0 && lambda(target, events[pos - 1]))
        {
            events[pos] = events[pos - 1];
            pos--;
        }

        events[pos] = target;
    }

    int pollHighest()
    {
        if (events.empty())
            return -1;
        int ans = events.back().first;
        events.pop_back();
        return ans;
    }
};

// int firstMatchingIndex(string s) {
//     int left = 0;
//     int right = s.size()-1;

//     while(left<=right){
//         if(s[left] == s[right]) return left;
//         left++;
//         right--;
//     }
//     return -1;
// }
//[[[5, 7], [2, 7], [9, 4]]]
// [[[18,1],[9,1],[5,6],[14,4],[10,5],[6,3]]]©leetcode
int main()
{
    vector<vector<int>> events = {{18, 1}, {9, 1}, {5, 6}, {14, 4}, {10, 5}, {6, 3}};
    EventManager e(events);
    e.updatePriority(18, 9);
    cout << e.pollHighest();
    cout << e.pollHighest();
}