#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MAX_BinaryHeap
{// Min Heap
private:
    int *array;
    int capacity;
    int heap_size;

public:
    MAX_BinaryHeap(int capacity);
    void Heapify(int); //To heapify a subtree with root at a given index
    int parent(int i) {return (i - 1) / 2;} //Parent of node @ i
    int left(int i) { return 2 * i + 1; }   //Left Child of node @ i
    int right(int i) { return 2*(i + 1); }  //Right Child of node @ i
    int extractMin(); // To remove minimum element or Root here
    int getMax() { return array[0]; }
    void deleteKey(int i);  // Delete value of node @ i
    void insertKey(int k);  // Insert Key 'k' in the heap
    void decreaseKey(int i, int newVal);    //Changes value at node @ i to newVal
};

MAX_BinaryHeap::MAX_BinaryHeap(int capacity)
{
    this->array = new int[capacity];
    this->capacity = capacity;
    this->heap_size = 0;
}

// void BinaryHeap::insertKey(int k){
//     if(this->heap_size == this->capacity){
//         cout<<"\nOverFlow Error: Heap Capacity Exceeded\n";
//         return;
//     }
//     this->array[heap_size] = k;
//     heap_size++;

//     for (int i = 0; i < heap_size; i++)
//     {
//         if
//     }
    
// }

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
