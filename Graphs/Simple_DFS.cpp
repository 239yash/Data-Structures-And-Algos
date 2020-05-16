 
# include<bits/stdc++.h>
using namespace std;

void DFS(std::vector<int> adj[], int, bool visited[]);

void add_edge(std::vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void print_edge(std::vector<int> adj[], int v)
{
    for(int i = 0; i < v; i++)
    {
        for( auto x : adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


void DFS_search(std::vector<int> adj[], int v, int s)
{
    bool visited[v];
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    DFS(adj,s,visited);
}


void DFS(std::vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    for(auto x : adj[s])
    {
        if(visited[x] == false)
        {
        DFS(adj,x,visited);

        }
    }
    cout<<s<<" ";
}

int main()
{
    int v = 5;
    std::vector<int> adj[v];
    add_edge(adj,0,1);
    add_edge(adj,1,2);
    add_edge(adj,2,3);
    add_edge(adj,3,4);
    DFS_search(adj,v,0);
}
