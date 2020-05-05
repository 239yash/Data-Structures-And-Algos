# include<bits/stdc++.h>
using namespace std;


void swap(int *x, int *y);

class MinHeap
{
    int heap_size;
    int capacity;
    int *harr;

    public:

        MinHeap(int cap)
        {
            heap_size = 0;
            capacity = cap;
            harr = new int[cap];
        }
        void MinHeapify(int );
        void insert_key( int );
        int extractMin();
        void DecreaseKey( int, int);
        void deletekey(int);

        int parent(int i )
        {
            return (i-1)/2;
        }

        int left(int i)
        {
            return 2*i+1;
        }

        int right(int i )
        {
            return 2*i +2;
        }

};



void MinHeap::insert_key( int key)
{
    if( heap_size == capacity)
    {
        cout<<"HEAP IS FULL"<<" ";
        return;
    }

    heap_size ++;
    int i = heap_size - 1;
    harr[i] = key;

    while( i != 0 && harr[parent(i)] > harr[i])
    {
        swap( &harr[i], &harr[parent(i)]);
        i = parent(i);
    }

}

void MinHeap::MinHeapify( int i)
{
    int l = left(i);
    int r = right(i);

    int smallest = i
    if( l < heap_size && harr[l] < harr[i])
        smallest = l;
    if( r < heap_size && harr[r] < harr[i])
        smallest = r;

    if( smallest != i)
    {
        swap(&harr[i], &harr[smallest]); 
        MinHeapify(smallest); 
    }
}

int MinHeap::extractMin()
{
    if(heap_size <= 0)
    {
        return INT_MAX;
    }

    if(heap_size == 1)
    {
        heap_size --;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size --;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i) 
{ 
    decreaseKey(i, INT_MIN); 
    extractMin(); 
} 
  

void MinHeap::DecreaseKey( int i, int key)
{
    if( i > heap_size)
    {
        cout<<"THE INDEX IS OUT BOUNDS OF HEAP"<<endl;
        return;
    }

    harr[i] = key;
    while( i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void  swap(int *i, int *y)
{
    int temp = *i;
    *i = *y;
    *y = temp;
}

int main()
{
    MinHeap h(10);
    h.insert_key(3); 
    h.insert_key(2); 
    h.insert_key(15); 
    h.insert_key(5); 
    h.insert_key(4); 
    h.insert_key(45); 
}
