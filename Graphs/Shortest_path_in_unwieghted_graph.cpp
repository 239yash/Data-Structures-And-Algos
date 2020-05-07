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

void shortest_dist(std::vector<int> adj[], int s, int v)
{
    int dist[v] = {INT_MAX};
    dist[s] = 0;

    std::queue<int> q;
    bool visited[v] = {false};

    q.push(s);
    visited[s] = true;

    while(q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for( auto x : adj[u])
        {
            if(visited[x] == false)
            {
                dist[x] = dist[u] + 1;
                visited[x] = true;
                q.push(x);
            }
        }
    }

    for(int i = 0; i < v; i++)
    cout<<dist[i]<<" ";
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
    shortest_dist(adj,0,v);
}
