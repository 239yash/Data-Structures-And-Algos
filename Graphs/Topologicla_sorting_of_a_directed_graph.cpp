# include<bits/stdc++.h>
using namespace std;


void add_edge(std::vector<int> adj[], int u, int v, int indegree[])
{
    adj[u].push_back(v);
    indegree[v] ++;
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

void topological_sort(std::vector<int> adj[], int v, int indegree[])
{
    std::queue<int> q;
    for(int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(q.empty() == false)
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(auto x: adj[u])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
}


int main()
{
    int v = 5;
    std::vector<int> adj[v];
    int indegree[v] = {0};
    add_edge(adj,0,2,indegree);
    add_edge(adj,0,3,indegree);
    add_edge(adj,2,3,indegree);
    add_edge(adj,1,3,indegree);
    add_edge(adj,1,4,indegree);
    //add_edge(adj,3,4,indegree);
    topological_sort(adj,v,indegree);
}
