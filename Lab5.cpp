#include <iostream>
using namespace std;

const int MaxKeySize = 10;

class Record {
public:
  int key[MaxKeySize];

  Record() {
    for (int i = 0; i < MaxKeySize; i++)
      key[i] = 0;
  }
};

class Bucket {
public:
  int size;
  Record* elements;
};

Record* inputRecords;
Record** sortedRecords;
int* bucketSizes;
int totalBuckets = 4;
int numRecords;
int maxKey = 10;

void printRecordArray(Record* records[], int numRecords, int maxKey) {
  for (int i = numRecords - 1; i >= 0; i--) {
    for (int j = 0; j < maxKey; j++)
      cout << records[i]->key[j] << ";";
    cout << endl;
  }
}

int main(int argc, char** argv) {
  cin >> numRecords;

  inputRecords = new Record[numRecords + 1];
  Record* pointerToRecords[numRecords + 1];

  for (int i = 0; i < numRecords; i++) {
    for (int j = 0; j < MaxKeySize; j++) {
      cin >> inputRecords[i].key[j];
    }
    pointerToRecords[i] = &inputRecords[i];
  }

  Record* buckets[MaxKeySize][numRecords];
  int bucketSizeCounts[MaxKeySize] = {0};

  for (int keyIndex = MaxKeySize - 1; keyIndex >= 0; keyIndex--) {
    for (int recordIndex = numRecords - 1; recordIndex >= 0; recordIndex--) {
      int bucketNumber = pointerToRecords[recordIndex]->key[keyIndex];
      int bucketSize = bucketSizeCounts[bucketNumber];
      buckets[bucketNumber][bucketSize] = pointerToRecords[recordIndex];
      bucketSizeCounts[bucketNumber]++;
    }
    int destinationIndex = 0;
    for (int bucketIndex = MaxKeySize - 1; bucketIndex >= 0; bucketIndex--) {
      for (int recordIndex = bucketSizeCounts[bucketIndex] - 1; recordIndex >= 0; recordIndex--) {
        pointerToRecords[destinationIndex] = buckets[bucketIndex][recordIndex];
        destinationIndex++;
      }
      bucketSizeCounts[bucketIndex] = 0;
    }
  }

  printRecordArray(pointerToRecords, numRecords, MaxKeySize);

  delete[] inputRecords;
  return 0;
}
