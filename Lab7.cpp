#include <iostream>
#include <vector>
#define MIN_INT -2147483648

using namespace std;
int ExtendedBottomUpCutRod(int prices[], int LenRod, vector<int> &Fract);

int main() { 
  int LenRod = 1;
  int* prices;
  cin>> LenRod;
  vector<int> Fract;
  prices = new int[LenRod];
  prices[0] = 0;
  for(int k = 1; k< LenRod+1; k++)
  {
    cin >> prices[k];
  }
  int profit = ExtendedBottomUpCutRod(prices,LenRod, Fract);
  cout << profit << endl;
  for(int i = 0; i < Fract.size(); i++){
    cout << Fract[i] << " ";
  }
  cout << "-1" << endl;
  return 0;
}

int ExtendedBottomUpCutRod(int prices[], int LenRod, vector<int> &Fract){
  int RodR[LenRod+1];
  int RodS[LenRod+1];
  RodR[0] = 0;
  for(int j = 1; j <= LenRod; j++){
    int MinInt = MIN_INT;
    for(int i = 1; i <= j; i++){
      if(MinInt < (prices[i] + RodR[j-i])){
        RodS[j] = i;
        MinInt = max(MinInt,prices[i]+RodR[j-i]);
      }
    }
    
    RodR[j] = MinInt;
  }
  int year = LenRod;
  while(year>0){
    Fract.push_back(RodS[year]);
    year -= RodS[year];
  }
  return RodR[LenRod];
}