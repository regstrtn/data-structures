#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
class graph {
public:
vector< vector<int> > v;
int numv;
int directed;
graph(int n, int directed);
void addedge(int from, int to);
void bfs(int start);
};
graph::graph(int n, int directed) {
v.resize(n);
numv = n;
this->directed = directed;
}
void graph::addedge(int from, int to) {
v[from-1].push_back(to-1);
if(!directed) v[to-1].push_back(from-1);
}
void graph::bfs(int start) {
int visited[numv];
int pathlen[numv];
int i, j, k, s;
for(i = 0;i<numv; i++) { visited[i] = 0; pathlen[i] = -1; }
deque<int> dq;
dq.push_back(start-1);
pathlen[start-1] = 0;
while(!dq.empty()) {
s = dq.front();
//cout<<" s: "<<s;
visited[s] = 1;
dq.pop_front();
for(i = 0;i<v[s].size();i++) {
if(!visited[v[s][i]]) {
dq.push_back(v[s][i]);
visited[v[s][i]] = 1;
pathlen[v[s][i]] = pathlen[s]+6;
}
}
}
for(i=0;i<numv;i++) {
if(i!=(start-1))
cout<<pathlen[i]<<" ";
}
cout<<endl;
}
int main() {
int n, t, i, j, k, l, V, E, from, to, start;
cin>>t;
int directed = 0;
for(i=0;i<t;i++) {
cin>>V; cin>>E;
graph g(V, directed);
for(j=0;j<E;j++) {
cin>>from; cin>>to;
g.addedge(from, to);
}
cin>>start;
g.bfs(start);
}
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
return 0;
}
