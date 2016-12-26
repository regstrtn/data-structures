#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class edge {
public:
int from;
int to;
int wt;
edge(int from, int to, int wt) {
this->from = from;
this->to = to;
this->wt = wt;
}
int operator<(edge& b) {
return (this->wt<b.wt);
}
};
int exists(vector<int> v, int val) {
vector<int>::iterator it = find(v.begin(), v.end(), val);
int i;
return(find(v.begin(), v.end(), val)!=v.end());
}
void printsum(vector<edge> tr) {
int i, j, k;
int sum = 0;
for(i=0;i<tr.size();i++) {
sum = sum+tr[i].wt;
}
cout<<sum<<endl;
}
void prims(vector<edge> e, int start, int n) {
sort(e.begin(), e.end());
vector<edge>::iterator it = e.begin();
vector<edge> tr;
vector<int> v;
v.push_back(start);
int i, j, k, l;
for(i=1;i<n;i++) {
it = e.begin();
while((exists(v, it->from) && exists(v, it->to)) || (!exists(v, it->from) && !exists(v, it->to))) {
it++;
}
tr.push_back(*it);
if(!exists(v, it->from)) { v.push_back(it->from); }
else if(!exists(v, it->to)) { v.push_back(it->to); }
}
printsum(tr);
}
int main() {
vector<edge> e;
int n, m, i, j, k, l, from, to, wt, start;
cin>>n; cin>>m;
for(i=0;i<m;i++) {
cin>>from; cin>>to; cin>>wt;
e.push_back(*(new edge(from, to, wt)));
e.push_back(*(new edge(to, from, wt))); //Comment this line for directed graph
}
cin>>start;
prims(e, start, n);
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
return 0;
}
