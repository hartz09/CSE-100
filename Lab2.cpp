#include <iostream>
using namespace std;

void Merge(int list[], int low, int mid, int high);

void MergeSort(int list[], int low, int high) { //Implimented from Psuedo Code
    if (low < high) { //only if low is less than high
        int mid = (low + high) / 2;
        MergeSort(list, low, mid);
        MergeSort(list, mid + 1, high);
        Merge(list, low, mid, high);
    }
}

void Merge(int list[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int i = 0;
    int j = 0;
    int k = low;

    int L[n1]; 
    int R[n2];

    for (int i = 0; i < n1; i++){
        L[i] = list[low + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = list[mid + 1 + j];
    }
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]){
            list[k++] = L[i++];
        }
        else{
            list[k++] = R[j++];
        }
    }

    while (j < n2){
        list[k++] = R[j++];
    }

    while (i < n1){
        list[k++] = L[i++];
    }
    
}

int main(){ //following the same logic from my first lab, wanted to impliment it similarly.
    int k;
    cin >> k;
    int list[k];

    for (int i = 0; i < k; i++){
        cin >> list[i];
    }
    
    MergeSort(list, 0, k - 1);

    for (int i = 0; i < k; i++) {//same output technique as last week's
        cout << list[i];
        if (i < k - 1) {
            cout << ";";
        }
    }   
    cout<< ";"<< endl;
    return 0;
}