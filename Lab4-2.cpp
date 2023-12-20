#include <iostream>
#include <stdlib.h>  

using namespace std;

int Partition(int list[], int min, int max){
  int low = list[max];
  int i  = min-1;
  int temp;
  for(int j = min; j < max; j++){
    if(list[j] <= low){
      i = i + 1;
      temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }
  }
  temp = list[i+1];
  list[i+1] = list[max];
  list[max] = temp;
  return i+1;
}

int RandomizedPartition(int list[], int min, int max){
  int i =  (rand() % (max-min)) + min;
  int temp;
  temp = list[max];
  list[max] = list[i];
  list[i] = temp;
  return Partition(list,min,max);
}

void RandomizedQuickSort(int list[], int min, int max){
  if(min<max){
    int q = RandomizedPartition(list, min, max);
    RandomizedQuickSort(list, min, q-1);
    RandomizedQuickSort(list, q+1, max);
  }
}

void printArray(int list[], int min, int max)
{
  for(int l = min; l< max; l++){
        cout << list[l] << ";";
    }
    cout << endl;
}

int main()
{
  int k;
  std::cin >> k;
  int list[k];

  for(int i = 0; i< k; i++){
    std::cin >> list[i]; 
  }
  RandomizedQuickSort(list, 0, k-1);
  printArray(list, 0, k);
}