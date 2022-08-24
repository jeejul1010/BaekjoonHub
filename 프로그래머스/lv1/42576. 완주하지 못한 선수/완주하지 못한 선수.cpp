#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> um;
    
    for(const auto& p: participant)
    {
        if(um.find(p) != um.end())
        {
            um[p]++;
        }
        else
        {
            um.insert(make_pair(p, 1));
        }
    }
    
    for(const auto& c: completion)
    {
        um[c]--;
    }
    
    for(const auto& p: participant)
    {
        if(um[p] != 0)
        {
            answer = p;
            break;
        }
    }
    
    return answer;
}