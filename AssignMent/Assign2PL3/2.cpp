// Given an array A[0…n-1] , where each element of the array represents a vote in the election. Assume that each vote is given as an integer representing the ID of the chosen candidate. Given an algorithm for determining who wins the election
#include <bits/stdc++.h>
using namespace std;

int findElectionWinner(vector<int> votes)
{
    unordered_map<int, int> voteCounts;

    for (int i = 0; i < votes.size(); i++)
    {
        int candidate = votes[i];
        if (voteCounts.find(candidate) != voteCounts.end())
        {
            voteCounts[candidate]++;
        }
        else
        {
            voteCounts[candidate] = 1;
        }
    }

    int winner = -1;
    int maxi = -1;

    // Iterate through the voteCounts map to find the candidate with the most votes.
    for (auto it = voteCounts.begin(); it != voteCounts.end(); ++it)
    {
        if (it->second > maxi)
        {
            maxi = it->second;
            winner = it->first;
        }
    }

    return winner;
}

int main()
{
    vector<int> votes = {1, 2, 3, 2, 1, 3, 1, 3, 3};
    int winner = findElectionWinner(votes);

    if (winner != -1)
    {
        cout << "The winner is Candidate #" << winner << endl;
    }
    else
    {
        cout << "No winner found." << endl;
    }

    return 0;
}
