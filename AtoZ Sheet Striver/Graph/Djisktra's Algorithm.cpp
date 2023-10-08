# Dijakstra's Algorithm

**Using Priority Queue:**
Time Complexity: O(E Log V): E is no of edges and V is no of vertices

   
   
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        // Code here
        
        //Make a min heap / Min priority queueu:
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        
        //Now save the {dist, source} and min priority queue:
        q.push({0, src});
        
        //Now make a distance vector with infinity:
        vector<int> dist(v, INT_MAX);
        
        
        //Make src dist 0:
        dist[src] = 0;
        
        
        while(!q.empty()){
            int val = q.top().second, currDist = q.top().first;
            q.pop();
            
            for(auto i: adj[val]){
                int edge = i[0];
                int edgeDist = i[1];
                int edgeiNewDist = currDist + edgeDist;
                if(dist[edge] > edgeiNewDist){
                    //than add that in queue and update dist:
                    q.push({edgeiNewDist, edge});
                    dist[edge] = edgeiNewDist;
                }
            }
        }
        
        return dist;
    }

**Using Set:**
