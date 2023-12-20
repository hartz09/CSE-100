#include<iostream>
using namespace std;

int main(){

    int key;
    int k;// k = the number of elements
    cin >> k;
    int list[k];

    for(int i=0; i < k; i++){   //insert elements into list of length k
        cin >> list[i];
    }

    for(int i = 1; i < k; i++){ //for loop for insertion sort
      key = list[i]; // "pointer" to spot in the list
      int j = i - 1;
       
        while((j>=0) & (list[j] > key)){
            list[j+1]=list[j];
            j = j-1;
       }
        list[j+1] = key; //next element

        for (int s = 0; s <= i; s++) {  //put elements into a "different" list
            cout << list[s];            //prints the sorted elements seperated
            if (s < i) {                //by semi colons
                cout << ";";
            }
        }
        cout << ";" << endl;
    }
    return 0;
}