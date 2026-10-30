class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            int wt = edges[i][2];

            adj[src].push_back({dest, wt});
        }

        // {distance, node, consecutive count}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // dist[node][consecutive count]
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()){
            auto [distance, node, count] = pq.top();
            pq.pop();

            if(distance > dist[node][count]){
                continue;
            }

            if(node == n - 1){
                return distance;
            }

            for(auto edge : adj[node]){
                int next = edge.first;
                int wt = edge.second;

                int newCount;

                if(labels[node] == labels[next]){
                    newCount = count + 1;
                }
                else{
                    newCount = 1;
                }

                if(newCount > k){
                    continue;
                }

                int newDist = distance + wt;

                if(newDist < dist[next][newCount]){
                    dist[next][newCount] = newDist;
                    pq.push({newDist, next, newCount});
                }
            }
        }

        return -1;
    }
};
