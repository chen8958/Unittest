#include <vector>
#include <numeric>
#include <list>
using namespace std;

namespace myTest{
    
    void relax(vector<int> &parent, vector<int> &distance, int u, int v, int w){
        if(distance[u]!=INT_MAX){
            if(distance[v] > distance[u] + w){
                parent[v] = u;
                distance[v] = distance[u] + w;
            }
        }
    }
    //----------------------------------------------------------------
    vector<int> Bellman(vector<vector<int>> edges, int node_number, int src){
        // vector<list<pair<int,int>>> adj_map(node_number);//u->v and weight
        vector<int> parent(node_number);
        vector<int> distance(node_number, INT_MAX);
        // for(auto edge:edges){
        //     adj_map[edge[0]].push_back(make_pair(edge[1],edge[2]));
        // }
        distance[src] = 0;
        for(int i = 0; i < node_number; i++){
            for(auto edge:edges){
                relax(parent, distance, edge[0], edge[1], edge[2]);
            }
        }
        return distance;
        // traversal all edge

        
    }

    int extract_min(const vector<int> &distance, vector<bool> &is_extracted){
        int min = INT_MAX, min_idx;
        for(int idx = 0; idx < distance.size();idx++ ){
            if(distance[idx] < min && is_extracted[idx] == false){
                min = distance[idx];
                min_idx = idx;
            }
        }
        is_extracted[min_idx] = true;
        return min_idx;
    }

    vector<int> Dijkstra(vector<vector<int>> edges, int node_number, int src){
        vector<int> parent(node_number);
        vector<int> distance(node_number, INT_MAX);
        vector<bool> is_extracted(node_number,false);
        vector<list<pair<int,int>>> adj_map(node_number);//u->v and weight
        for(auto edge:edges){
            adj_map[edge[0]].push_back(make_pair(edge[1],edge[2]));
        }
        distance[src] = 0;
        for(int i = 0; i < node_number; i++){
            int idx = extract_min(distance,is_extracted);
            for(auto p:adj_map[idx]){
                relax(parent, distance, idx, p.first, p.second);
            }
        }
        return distance;

    }
    
}


