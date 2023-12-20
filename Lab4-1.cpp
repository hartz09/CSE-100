#include <iostream>

void heapify(int list[], int i, int k)
{
  int max;
  int l = 2*i;
  int r = 2*i +1;
  if (l <= k && list[l]>list[i]){
    max = l;
  }
  else{
    max = i;
  }
  if(r<= k && list[r] > list[max]){
    max = r;
  }
  if (max != i){
    int temp;
    temp = list[i];
    list[i] = list[max];
    list[max] = temp;
    heapify(list, max, k);
  }
}

void buildMaxHeap(int list[], int k, int length)
{
  for(int i = (k/2); i>=0; i--){
    heapify(list, i, k);
  }
}

void heapSort(int list[], int k, int length)
{
  buildMaxHeap(list,k,length);
  for(int i = length; i >= 1; i--){
    int temp;
    temp = list[0];
    list[0] = list[i];
    list[i] = temp;
    k = k-1;
    heapify(list,0,k);
  }
}

void printArray(int list[], int low, int high)
{
  for(int l = low; l< high; l++){
    std::cout << list[l] << ";";
  }
}

int main() 
{ 
  int k;
  std::cin >> k;
  int list[k];

  for(int i = 0; i< k; i++){
    std::cin >> list[i]; 
  }
  heapSort(list,k-1, k-1);
  printArray(list, 0, k);
  return 0;
}