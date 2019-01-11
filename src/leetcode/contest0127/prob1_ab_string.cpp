/*
984. String Without AAA or BBB
Given two integers A and B, return any string S such that:

S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.
 

Example 1:

Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: A = 4, B = 1
Output: "aabaa"
 

Note:

0 <= A <= 100
0 <= B <= 100
It is guaranteed such an S exists for the given A and B.

*/

#if 0

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string first, second, answer = "";
        int bigger = A < B ? B : A;
        int smaller =  A < B ? A : B;
        first = A < B ? "b" : "a";
        second = A < B ? "a" : "b";
        
        while( smaller < bigger && bigger > 1 && smaller > 0){
            answer = answer + first + first + second;
            bigger-=2;
            smaller--;
        }
        
        for(int i = 0; i < smaller; ++i ){
            answer += (first + second);
            bigger--;
        }
        
        for(int i = 0; i < bigger; ++i){
            answer += first;
        }
        
        return answer;
        

    }
};


#endif

