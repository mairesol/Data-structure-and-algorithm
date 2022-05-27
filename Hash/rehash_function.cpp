#include <iostream>

using namespace std;

#define M 100
#define NULLKEY INT_MIN

struct Node
{
    int key;
};

Node HashTable[M];
int N;

int hf(int);
void init();
bool empty();
bool full();
int search();
int insert();

int hf1(int);
int hf2(int);

int main()
{
    return 0;
}

int hf(int key)
{
    return (key % M);
}
void init()
{
    for (int i = 0; i < M; i++)
        HashTable[i].key = NULLKEY;
    N = 0;
}
bool empty()
{
    return (N == 0);
}
bool full()
{
    return (N == M - 1);
}
//-----------------------------Linear Probing Method------------------------------//
int search(int key)
{
    int i = hf(key);
    while (HashTable[i].key != key && HashTable[i].key != NULLKEY)
    {
        i = (i + 1) % M;
    }
    if (HashTable[i].key == key)
        return i;
    return -1;
}
void insert(int key)
{
    if (search(key) != -1 || full()) // Trùng khóa hoặc đầy
        return;
    int i = hf(key);
    while (HashTable[i].key != NULLKEY)
    {
        i = (i + 1) % M;
    }
    HashTable[i].key = key;
    N++;
}

//-----------------------------Quadratic Probing method------------------------------//
int search(int key)
{
    int i = hf(key);
    int d = 1;
    while (HashTable[i].key != key && HashTable[i].key != NULLKEY)
    {
        i = (i + d) % M;
        d += 2;
    }
    if (HashTable[i].key == key)
        return i;
    return -1;
}
void insert(int key)
{
    if (search(key) != -1 || full())
        return;
    int i = hf(key);
    int d = 1;
    while (HashTable[i].key != NULLKEY)
    {
        i = (i + d) % M;
        d += 2;
    }
    HashTable[i].key = key;
    N++;
}

//-----------------------------Double Hashing Method------------------------------//
int hf1(int key)
{
    return (key % M);
}
int hf2(int key)
{
    return (M - 2 - key % (M - 2));
}

int search(int key)
{
    int i = hf1(key), j = hf2(key);
    while (HashTable[i].key != key && HashTable[i].key != NULLKEY)
    {
        i = (i + j) % M;
    }
    if (HashTable[i].key == key)
        return i;
    return -1;
}
void insert(int key)
{
    if (search(key) != -1 || full())
        return;
    int i = hf1(key), j = hf2(key);
    while (HashTable[i].key != NULLKEY)
    {
        i = (i + j) % M;
    }
    HashTable[i].key = key;
    N++;
}
