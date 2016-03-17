#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
 
using namespace std;
 
int N;
vector<vector<pair<int, int> > > graph; //[f] <t, v>
bool visited[12345];
 
pair<int, int> get_furthest(int start){
    memset(visited, false, 12345);
 
    int res_node = -1, res_val = -1;
    queue<pair<int, int> > q; //node, value sum;
    q.push(make_pair(start, 0));
    visited[start] = true;
    int n, v;
 
    while(!q.empty()){
        n = q.front().first;
        v = q.front().second;
        q.pop();
 
        int len = graph[n].size();
        bool is_leaf = true;
        for(int i=0; i<len; i++){
 
            if(!visited[graph[n][i].first]){
                q.push(make_pair(graph[n][i].first, v+graph[n][i].second));
                visited[graph[n][i].first] = true;
            }
        }
        if(res_val <= v){
            res_val = v;
            res_node = n;
        }
    }
 
    return make_pair(res_node, res_val);
}
 
int main(void){
    scanf("%d", &N);
 
    graph.resize(10000+1);
    int f, t, v;
    for(int i=0; i<N-1; i++){
        scanf("%d %d %d", &f, &t, &v);
        graph[f].push_back(make_pair(t, v));
        graph[t].push_back(make_pair(f, v));
    }
 
    pair<int, int> fur = get_furthest(1);
    //printf("%d %d\n", fur.first, fur.second);
 
    pair<int, int> res = get_furthest(fur.first);
    //printf("%d %d\n", res.first, res.second);
 
    printf("%d\n", res.second);
 
    return 0;
}
