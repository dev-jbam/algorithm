//https://leetcode.com/problems/reverse-vowels-of-a-string/

#if 0
#include <string>
#include <queue>
#include <stack>

using namespace std;
class Solution {
public:
    string reverseVowels(string &s) {
        int l =0; int r = s.length()-1;
        while(l<r){
            while(!is_vowel(s[l])) l++;
            while(!is_vowel(s[r])) r--;
            if(l<r){
                swap(s[l],s[r]);
                l++; r--;
            }
        }
        return s;
    }

private:
    inline bool is_vowel(char c){
        return c == 'e' || c == 'E' || c == 'i' || c =='I' 
        || c == 'a' || c =='A' || c == 'o' 
        || c =='O' || c == 'u' || c =='U';
    }
};

#endif

#if 0

#include <string>
#include <queue>
#include <stack>

using namespace std;
class Solution {
public:
    string reverseVowels(string &s) {
        int len = s.length();
        queue<char> vowel_queue;
        stack<int> index_stack;
        #pragma unroll
        for(int i = 0 ; i <len; ++i){
            if(is_vowel(s[i])){
                vowel_queue.push(s[i]);
                index_stack.push(i);
            }
        }
        int size = index_stack.size();
        for(int i = 0 ; i <size; ++i){
            s[index_stack.top()] = vowel_queue.front();
            vowel_queue.pop();
            index_stack.pop();            
        }
        
        return s;
    }

private:
    bool is_vowel(char c){
        return c == 'e' || c == 'E' || c == 'i' || c =='I' 
        || c == 'a' || c =='A' || c == 'o' 
        || c =='O' || c == 'u' || c =='U';
    }
};

#endif