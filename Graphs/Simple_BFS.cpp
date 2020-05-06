# include<bits/stdc++.h>
using namespace std;


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

void BFS( std::vector<int> adj[], int v, int s)
{
    bool visited[v+1];
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    std::queue<int> q;
    visited[s] = true;
    q.push(s);

    while(q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(auto x : adj[u])
        {
            if(visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main()
{
    int v = 4;
    std::vector<int> adj[v];
    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,2,1);
    add_edge(adj,3,1);
    BFS(adj,4,0);
}
