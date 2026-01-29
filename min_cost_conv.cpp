#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long shortestPath(vector<vector<long long>>& mat, int src, int dest) {
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        vector<long long> dist(26, LLONG_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (wt > dist[node]) continue;

            for (int i = 0; i < 26; i++) {
                if (mat[node][i] == -1) continue;

                long long newDist = wt + mat[node][i];
                if (newDist < dist[i]) {
                    dist[i] = newDist;
                    pq.push({newDist, i});
                }
            }
        }

        return (dist[dest] == LLONG_MAX ? -1 : dist[dest]);
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        int n = original.size();

        vector<vector<long long>> mat(26, vector<long long>(26, -1));
        vector<vector<long long>> sd(26, vector<long long>(26, -1));

        // Build graph (keep minimum cost edge)
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            if (mat[u][v] == -1 || mat[u][v] > cost[i]) {
                mat[u][v] = cost[i];
            }
        }

        // Precompute shortest paths between all pairs
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                sd[i][j] = shortestPath(mat, i, j);
            }
        }

        long long sum = 0;
        for (int i = 0; i < source.length(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (sd[u][v] == -1) return -1;
            sum += sd[u][v];
        }

        return sum;
    }
};