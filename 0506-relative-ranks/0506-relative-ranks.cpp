#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
class Solution {
public:

    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        vector<string> answer(n);

        for (int rank = 1; rank <= n; rank++) {

            int originalIndex = pq.top().second;

            pq.pop();

            if (rank == 1) {
                answer[originalIndex] = "Gold Medal";
            }
            else if (rank == 2) {
                answer[originalIndex] = "Silver Medal";
            }
            else if (rank == 3) {
                answer[originalIndex] = "Bronze Medal";
            }
            else {
                answer[originalIndex] = to_string(rank);
            }
        }
        return answer;
    }
};