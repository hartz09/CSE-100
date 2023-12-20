#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void swapHeapNode(struct HeapNode** first, struct HeapNode** second);
void Heapify(struct Heap* Heap, int i);
void insertHeap(struct Heap* Heap, struct HeapNode* HeapNode);
void sortCodes(char letter[], struct HeapNode* root, string key, string keys[], int parent);
void Huffman(char letter[], int frequency[], int size);
struct HeapNode* newNode(char letter, unsigned frequency);
struct Heap* createHeap(unsigned max);
struct HeapNode* getMinimum(struct Heap* Heap);
struct Heap* buildHeap(char letter[], int frequency[], int size);
struct HeapNode* buildTree(char letter[], int frequency[], int size);
struct HeapNode;
struct Heap;

struct Heap {
  unsigned size;
  unsigned max;
  struct HeapNode** list;
};

struct HeapNode {
  char letter;
  unsigned frequency;
  struct HeapNode *left, *right;
};

struct HeapNode* newNode(char letter, unsigned frequency){
  struct HeapNode* temp = (struct HeapNode*)malloc(sizeof(struct HeapNode));

  temp->left = temp->right = NULL;
  temp->letter = letter;
  temp->frequency = frequency;
  return temp;
}

struct Heap* createHeap(unsigned max){
  struct Heap* Heap = (struct Heap*)malloc(sizeof(struct Heap));
  Heap->size = 0;
  Heap->max = max;
  Heap->list = (struct HeapNode**)malloc(Heap->max * sizeof(struct HeapNode*));
  return Heap;
}

struct HeapNode* getMinimum(struct Heap* Heap){
  struct HeapNode* temp = Heap->list[0];
  Heap->list[0] = Heap->list[Heap->size-1];
  --Heap->size;
  Heapify(Heap,0);
  return temp;
}

struct Heap* buildHeap(char letter[], int frequency[], int size){
  struct Heap* Heap = createHeap(size);

  for(int i = 0; i<size; ++i){
    Heap->list[i] = newNode(letter[i],frequency[i]);
  }
  Heap->size = size;
  int n = Heap->size-1;
  int i;

  for(i = (n-1)/2;i>=0;--i){
    Heapify(Heap,i);
  }
  return Heap;
}

struct HeapNode* buildTree(char letter[], int frequency[], int size){
  struct HeapNode *left, *right, *parent;
  struct Heap* Heap = buildHeap(letter, frequency, size);
  while(!(Heap->size == 1)){
    left = getMinimum(Heap);
    right = getMinimum(Heap);
    parent = newNode('$',left->frequency + right->frequency);
    parent->left = left;
    parent->right = right;

    insertHeap(Heap,parent);
  }
  return getMinimum(Heap);
}

void swapHeapNode(struct HeapNode** first, struct HeapNode** second){
  struct HeapNode* tempe = *first;
  *first = *second;
  *second = tempe;
}

void Heapify(struct Heap* Heap, int i){
  int min = i;
  int left = 2*i+1;
  int right = 2*i+2;
  if(left < Heap->size && Heap->list[left]->frequency < Heap->list[min]->frequency){
    min = left;
  }
  if(right< Heap->size && Heap->list[right]->frequency < Heap->list[min]->frequency){
    min = right;
  }
  if(min != i){
    swapHeapNode(&Heap->list[min], &Heap->list[i]);
    Heapify(Heap, min);
  }
}

void insertHeap(struct Heap* Heap, struct HeapNode* HeapNode){
  ++Heap->size;
  int indx = Heap->size-1;

  while(indx && HeapNode->frequency < Heap->list[(indx-1)/2]->frequency){
    Heap->list[indx] = Heap->list[(indx-1)/2];
    indx = (indx-1)/2;
  }

  Heap->list[indx] = HeapNode;
}

void sortCodes(char letter[], struct HeapNode* root, string key, string keys[], int parent){
  if(root->left){
    key.insert(parent,"0");
    sortCodes(letter,root->left,key,keys,parent+1);
  }
  if(root->right){
    key.insert(parent,"1");
    sortCodes(letter,root->right,key,keys,parent+1);
  }
  if(!(root->left) && !(root->right)){
    for(int i = 0; i < 6; i++){
      if(root->letter == letter[i]){
        keys[i] = key.substr(0,parent);
      }
    }
  }
}

void Huffman(char letter[], int frequency[], int size){
  struct HeapNode* root = buildTree(letter, frequency, size);

  string key;
  int parent = 0;
  string keys[6];

  sortCodes(letter,root,key,keys,parent);

  for(int i = 0;i<6;i++){
    cout << letter[i] << ":" << keys[i] << endl;
  }
}

int main() {
  int* frequency;

  char letter[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  frequency = new int[6];

  for(int i = 0; i < 6; i++){
    cin >> frequency[i];
  }
  int size = sizeof(letter)/sizeof(letter[0]);
  Huffman(letter,frequency,size);
  return 0;
}