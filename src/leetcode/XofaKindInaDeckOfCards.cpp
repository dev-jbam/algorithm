#if 0
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int gcd(int a, int b){
        if(b == 0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> integerCount;
        
        for(int i = 0; i < deck.size(); ++i){
            integerCount[deck[i]] ? integerCount[deck[i]]++: integerCount[deck[i]]=1;
        }
        
        int min = 0x7FFFFFF;
        for(auto iter = integerCount.begin(); iter != integerCount.end(); iter++){
            if (min > iter->second){
                min = iter->second;
            }
        }
        int minGcd = 0x7FFFFFF;
        for(auto iter = integerCount.begin(); iter != integerCount.end(); iter++){
            int currentGcd = gcd(iter->second, min);
            if(minGcd == 1){
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> deck;
    deck.push_back(1);
    deck.push_back(1);
    deck.push_back(1);
    deck.push_back(2);
    deck.push_back(2);
    deck.push_back(2);
    deck.push_back(3);
    deck.push_back(3);
    
    
    
    Solution s;
    return s.hasGroupsSizeX(deck);
}

#endif