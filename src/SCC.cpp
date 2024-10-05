#include <bits/stdc++.h>

#define in(x, y) ((y).find(x) != (y).end())

typedef long long ll;

using namespace std;

struct Graph {
    // For representing the graph
    vector<vector<size_t>> adj;

    // For Tarjan's Algorithm
    vector<size_t> scc;
    size_t nr_scc = 0;
    size_t id = 0;
    stack<size_t> s;
    vector<ll> low;
    vector<ll> index;
    unordered_set<size_t> onStack;    

    Graph(vector<vector<size_t>>& adj) : adj{adj} {
        low.assign(adj.size(), -1);
        index.assign(adj.size(), -1);
        scc.assign(adj.size(), 0);
    }

    void dfs(size_t v) {
        index[v] = id;
        low[v] = id++;
        s.push(v);
        onStack.emplace(v);

        for (auto w : adj[v]) {
            if (index[w] == -1) {
                dfs(w);
                low[v] = min(low[v], low[w]);
            }
            else if (in(w, onStack))
                low[v] = min(low[v], index[w]);
        }

        if (low[v] == index[v]) {
            size_t w;
            do {
                w = s.top();
                scc[w] = nr_scc;
                onStack.erase(w);
                s.pop();
            } while(w != v);
            ++nr_scc;
        }
    }

    void findSCC() {
        for (size_t v = 0; v < adj.size(); ++v)
            if (index[v] == -1)
                dfs(v);
    }
};
