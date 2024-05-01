#include <vector>
#include <list>
#include <queue>
using namespace std;

namespace myTest{
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<list<pair<int,int>>> adj(n+1);
        vector<bool> isVisited(n+1,false);
        vector<int> w(n+1, 0);
        int max = 0;
        queue<int> q;

        // establish adjacency list
        for(auto e: times){
            adj[e[0]].push_back(make_pair(e[1],e[2]));
        }
        // push root
        q.push(k);
        isVisited[k] = true;
        n--;
        while(q.size() != 0){
            int cur = q.front();
            q.pop();
            
            for(auto p : adj[cur]){
                if(!isVisited[p.first]){
                    n--;
                    q.push(p.first);
                    isVisited[p.first] = true;
                    w[p.first] = w[cur] + p.second;
                }else{
                    if (w[p.first] > w[cur] + p.second){
                        w[p.first] = w[cur] + p.second;
                    }
                }
            }

        }
        if(n!=0){
            return -1;
        }else{
            for(auto _w : w){
                if(_w > max){
                    max = _w;
                }
            }
        }

        return max;

    }
}

