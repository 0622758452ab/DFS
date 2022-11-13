#include <bits/stdc++.h>
using namespace std;

void dfs1(int S,vector<int> &visited,vector<int> &vec,vector<int> g[])
{
    visited[S]=1;
    vec.push_back(S);
    
    for(int i=0;i<g[S].size();i++)
    {
        if(!visited[g[S][i]])
         {
             dfs1(g[S][i],visited,vec,g);
         }
        
    }
}

vector <int> dfs(vector<int> g[], int N)
{

    vector<int> visited(N,0);
    vector<int> vec;
    dfs1(0,visited,vec,g);
    return vec;
}

int main()
{
    cout << "Enter node and edge :";
    int N, E;
    cin>>N>>E;
    vector<int> g[N];
    bool vis[N];
    cout << "Enter node to node : " << endl;
    for(int i=0;i<E;i++){
        cout << "Edge " << i+1 << " :";
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> result = dfs(g, N);
    for (int i = 0; i < result.size (); i++)
        cout << result[i] << " ";
    cout<<endl;
}
