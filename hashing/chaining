# include<bits/stdc++.h>

using namespace std;

class Hash
{
    int Bucket;
    list<int> *table;
    public:
    void insert(int);
    void delete_key(int);
    void display();
    int hash_func(int x)
    {
        return (x%Bucket);
    }

    Hash(int b)
    {
        Bucket = b;
        table = new list<int> [Bucket];
    }

};


void Hash::insert(int key)
{
    int index = hash_func(key);
    table[index].push_back(key);
}

void Hash::delete_key(int key)
{
    int index = hash_func(key);
    list<int> ::iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)
    {
        if(*i == key)
        break;
    }

    if(i!=table[index].end())
    table[index].erase(i);

}


void Hash::display()
{
    for(int i = 0;i<Bucket;i++)
    {
        cout <<i;
        for(auto x:table[i])
        cout <<"-->" <<x;
        cout<<endl;
    }
}

int main() 
{ 
  // array that contains keys to be mapped 
  int a[] = {15, 11, 27, 8, 12}; 
  int n = sizeof(a)/sizeof(a[0]); 

  Hash h(7);   
  for (int i = 0; i < n; i++)  
    h.insert(a[i]);   
  
  h.delete_key(12); 
  
  h.display(); 
  
  return 0; 
} 

