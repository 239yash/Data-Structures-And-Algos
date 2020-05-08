# include<bits/stdc++.h>
using namespace std;
bool DFS(std::vector<int> adj, int v);
bool DFS_rec(std::vector<int> adj[], int s, bool visited[], bool recst[]);

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

bool DFS_rec(std::vector<int> adj[], int s, bool visited[], bool recst[])
{
    visited[s] = true;
    recst[s] = true;

    for(auto x: adj[s])
    {
        if(visited[x] == false  &&  DFS_rec(adj, x, visited, recst) == true)
        {
            return true;
        }
        else if (recst[s] == true)
        {
            return true;
        }
    }

    recst[s] = false;
    return false;
}

bool DFS(std::vector<int> adj[], int v)
{
    bool visited[v] = {false};
    bool recst[v] = {false};

    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {
            if(DFS_rec(adj,i,visited,recst) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int v = 5;
    std::vector<int> adj[v];
    //add_edge(adj,0,1);
    add_edge(adj,1,0);
    add_edge(adj,0,2);
    add_edge(adj,2,3);
    add_edge(adj,3,1);
    add_edge(adj,2,4);
    add_edge(adj,3,4);
    cout<<DFS(adj,v)<<" ";
}
