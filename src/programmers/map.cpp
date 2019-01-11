#if 0
#include <string>
#include <vector>
#include <unordered_map>



using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> completion_map;

    for( int i=0; i< completion.size(); ++i ){
        completion_map[completion[i]] = completion_map[completion[i]] ? completion_map[completion[i]]+ 1: 1;
    }

    for( int i=0; i< participant.size(); ++i ){
        if(!completion_map[participant[i]] || completion_map[participant[i]] == 0){
            return participant[i];
        }
        completion_map[participant[i]]--;
    }
    return answer;
}


int main(){
    return 0;
}


#endif