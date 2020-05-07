# include<bits/stdc++.h>
using namespace std;
bool DFS(std::vector<int> asj[], int s, bool visited[], int parent);

void add_edge(std::vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
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

bool DFS(std::vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for(auto x : adj[s])
    {
        if(visited[x] == false)
        {
            if(DFS(adj,x,visited,s) == true)
            return true;
        }
        else if (x != parent)
        {
            return true;
        }  
    }
    return false;
}

bool DFS_main(std::vector<int> adj[], int v)
{
    bool visited[v] = {false};
    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {
            if(DFS(adj,i,visited,-1) == true)
            return true;
        }
    }
    return false;
}

int main()
{
    int v = 5;
    std::vector<int> adj[v];
    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,2,3);
    add_edge(adj,3,1);
    add_edge(adj,2,4);
    add_edge(adj,3,4);
    cout<<DFS_main(adj,v)<<" ";
}
