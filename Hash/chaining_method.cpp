#include <iostream>

using namespace std;

#define M 100

struct Node
{
    int key;
    Node *next;
};

Node *HashTable[M];

Node *createNode(int);
void insert(Node *&, int);
void remove_head(Node *&);
void remove_after(Node *&, Node *);

int hf(int);
void init();
bool empty(int);
bool empty();
void insert(int);
void remove(int);
Node *search(int);
void traverse(int);
void traverse();

int main()
{
    return 0;
}
//-----------------------------Node------------------------------//
Node *createNode(int key)
{
    Node *p = new Node;
    p->key = key;
    p->next = NULL;
    return p;
}

//-----------------------------List------------------------------//
void insert(Node *&head, int key) // Thêm phần tử vào list
{
    Node *p = createNode(key);
    p->next = head;
    head = p;
}
void remove_head(Node *&head)
{
    if (head != NULL)
    {
        Node *p = head;
        head = head->next;
        delete p;
    }
}
void remove_after(Node *&head, Node *q)
{
    if (q != NULL)
    {
        Node *p = q->next;
        if (p != NULL)
        {
            q->next = p->next;
            delete p;
        }
    }
}

//-----------------------------HashTable------------------------------//
int hf(int key) // Hàm băm
{
    return (key % M);
}
void init() // Khởi tạo bảng băm
{
    for (int i = 0; i < M; i++)
        HashTable[i] = NULL;
}
bool empty(int i)
{
    return (HashTable[i] == NULL);
}
bool empty()
{
    for (int i = 0; i < M; i++)
        if (HashTable[i] != NULL)
            return false;
    return true;
}
void insert(int key)
{
    int i = hf(key);
    insert(HashTable[i], key);
}
void remove(int key)
{
    int i = hf(key);
    Node *p, *q;
    p = HashTable[i];
    q = NULL;
    while (p != NULL && p->key != key)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return;
    if (q == NULL)
        remove_head(HashTable[i]);
    else
        remove_after(HashTable[i], q);
}
Node *search(int key)
{
    int i = hf(key);
    Node *p = HashTable[i];
    while (p != NULL && p->key != key)
        p = p->next;
    if (p == NULL || p->key != key)
        return NULL;
    return p;
}
void traverse(int i)
{
    Node *p = HashTable[i];
    while (p != NULL)
    {
        cout << p->key << " ";
        p = p->next;
    }
}
void traverse()
{
    for (int i = 0; i < M; i++)
    {
        traverse(i);
        cout << endl;
    }
}