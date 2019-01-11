/*
981. Time Based Key-Value Store
User Accepted: 975
User Tried: 1286
Total Accepted: 984
Total Submissions: 2036
Difficulty: Medium
Create a timebased key-value store class TimeMap, that supports two operations.

1. set(string key, string value, int timestamp)

Stores the key and value, along with the given timestamp.
2. get(string key, int timestamp)

Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
If there are multiple such values, it returns the one with the largest timestamp_prev.
If there are no values, it returns the empty string ("").
 

Example 1:

Input: inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
Output: [null,null,"bar","bar",null,"bar2","bar2"]
Explanation:   
TimeMap kv;   
kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1   
kv.get("foo", 1);  // output "bar"   
kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"   
kv.set("foo", "bar2", 4);   
kv.get("foo", 4); // output "bar2"   
kv.get("foo", 5); //output "bar2"   

Example 2:

Input: inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
Output: [null,null,null,"","high","high","low","low"]
 

Note:

All key/value strings are lowercase.
All key/value strings have length in the range [1, 100]
The timestamps for all TimeMap.set operations are strictly increasing.
1 <= timestamp <= 10^7
TimeMap.set and TimeMap.get functions will be called a total of 120000 times (combined) per test case.
*/
#if 0

#include <string>
#include <map>
#include <queue>

using namespace std;
typedef pair<int, string> pis;
typedef priority_queue<pis , vector< pis >, less< pis > > time_map_pq;
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(string_pq_map.find(key) == string_pq_map.end() ) {
            time_map_pq pq;
            pq.push(make_pair(timestamp, value));
            string_pq_map.insert(make_pair(key,pq));
        }
        else{
            string_pq_map[key].push(make_pair(timestamp,value));
        }
    }
    
    string get(string key, int timestamp) {
        string target = "";
        if(string_pq_map.find(key) == string_pq_map.end() ) {
            return target;
        }
        time_map_pq &pq = string_pq_map[key];
        vector< pis > temp_vector;
        while(!pq.empty() && pq.top().first > timestamp){
            temp_vector.push_back(pq.top()); pq.pop();
        }
        
        if(!pq.empty()){
            target = pq.top().second;
        }
        for(int i = 0; i< temp_vector.size(); ++i){
            pq.push(temp_vector[i]);
        }
        return target;
    }
private:
    time_map_pq  pq_map;
    map< string, time_map_pq > string_pq_map; 
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(){
    return 0;
}

#endif