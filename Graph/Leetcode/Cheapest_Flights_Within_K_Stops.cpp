class Solution {
public:

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    k++;

    if(src == dst) return 0;
    if(k == 0) return 0;
    // adjacency list
    unordered_map<int,vector<pair<int,int>>> adj;
    for(auto it : flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }


    queue<pair<int,int>> q;
    q.push({src,0});

    vector<int> dist(n+1,INT_MAX);
    dist[src] = 0;

    while(!q.empty()) {

        k--;
        if(k < 0) break;
        int sizeofqueue = q.size();
        for(int i = 0; i < sizeofqueue; i++) {
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjWt = it.second;

                if(wt + adjWt < dist[adjNode]) {
                    dist[adjNode] = wt + adjWt;
                    q.push({adjNode,dist[adjNode]});
                }
            }
        }
    }

    if(dist[dst] == INT_MAX) return -1;
    return dist[dst];
}
};