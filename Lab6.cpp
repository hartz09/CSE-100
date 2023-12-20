#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[]) {

  int number =  0;
  int HashM;
  bool repeat = true;
  int key;
  string input = "";
  cin >> HashM;
  
  list<int>** hashTable = new list<int>*[HashM];
  for(int k = 0; k < HashM; k++){
    list<int>* chain = new list<int>;
    hashTable[k] = chain;
  }
  
  do
  {
      number = 0;
      cin >> input;
      if (input[0] != 'o' || input[0] != 'e'){
        for (int i = 1; i < input.size(); i++){
          int numChar = input[i] - '0';
          number = 10 * number + numChar;
        }
      }
      key = number % HashM; 

      if(input[0] == 'i'){

        hashTable[key]->push_front(number);
        
      }else if(input[0] == 'd'){
        
        list<int>* chain = hashTable[key];
        int counter = 0;
        for(auto loco = chain->begin(); loco != chain->end(); loco++)
        {
          if(*loco == number){
            loco = chain->erase(loco);
            cout << number << ":DELETED;" << endl;
            counter = -1;
            break;
          }
          counter++;
        }
        if(counter != -1){
          cout<< number << ":DELETE_FAILED;" << endl;
        }
        
      }else if(input[0] == 's'){
    
        list<int>* chain = hashTable[key];
        int counter = 0;
        for(auto loco = chain->begin(); loco != chain->end(); loco++){
          if(*loco == number){
            cout << number << ":FOUND_AT" << key << "," << counter << ";" << endl;
            counter = -1;
            break;
          }
          counter++;
        } 
        if(counter != -1){
          cout<< number << ":NOT_FOUND;" << endl;
        }
      }
      else if(input[0] == 'o'){
        for(int i = 0; i < HashM; i++){
          cout << i << ":";
          list<int>* chain = hashTable[i];
          for(auto loco = chain->begin(); loco != chain->end(); loco++)
          {
            cout << *loco << "->";
          }
          cout << ";" << endl;
        }
       
      }
      else if(input[0] == 'e'){
        repeat = false;
      }
      else{
        cout << "Wrong input" << endl;
      }
  }
  while(repeat);

  return 0;
}