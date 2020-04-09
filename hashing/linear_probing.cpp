# include<bits/stdc++.h>

using namespace std;

class Hash
{
    int *arr;
    int cap,size;
    public:
    bool search(int);
    void delete_key(int);
    void insert(int);
    void display();

    int hash_func(int key)
    {
        return (key%cap);
    }

    Hash(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
        for(int i = 0;i<cap;i++)
        {
            arr[i] = -1;
        }


    }
};

bool Hash::search(int key)
{
    if(size == 0)
    {
        cout<<"false";
        return false;  
    }


    int i = hash_func(key);
    int j = i;
    while (arr[i] != -1 || i!=j)
    {
        if(arr[i] == key)
        {
            cout<<"true";
            return true;
        }

        i = (i+1)%cap;
    }
    cout<<"false";
    return false;
    
}

void Hash::insert(int key)
{
    int index = hash_func(key);
    int j = index;
    int i = index;
    if(size>=cap)
    return;

    if(arr[i] == -1)
    {
        arr[i] = key;
        return;
    }

    if(arr[i] == key)
    {
        return;
    }

    for(i = index;arr[i]!=-1 || i==j;i=(i+1)%cap){}
    arr[i] = key;
    return;
}

void Hash::delete_key(int key)
{
    int index = hash_func(key);
    int i;
    int j = i;

    for(i=index;arr[i]!=-1 && i!=j; i=(i+1)%cap)
    {
        if(arr[i] == key)
        {
            arr[i] = -2;
            size --;
            break;
        }
    }


}

void Hash::display()
{
    for(int i = 0;i<cap;i++)
    {
        cout<<arr[i]<<" ";
    }

}


int main()
{
    Hash h(7);
    h.insert(49);
    h.insert(50);
    h.insert(51);
    h.display();
    cout<<"\n";
    h.insert(56);
    h.display();
    h.delete_key(49);
    cout<<"\n";
    h.display();
}
