#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int timeDiff(const string& a, const string& b)
{
    int hour= stoi(b.substr(0,2)) - stoi(a.substr(0,2));
    int min = stoi(b.substr(3,2)) - stoi(a.substr(3,2));
    int totalTimeDiff = hour * 60 + min;
    return totalTimeDiff;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, vector<string>> m;
    
    stringstream ss;
    string time, carNum, status;
    for(const auto& record:records)
    {
        ss.str(record);
        ss>>time>>carNum>>status;
        
        m[carNum].push_back(time);
        ss.clear();
    }
    
    for(auto & elem:m)
    {
        if(elem.second.size() & 1)
        {
            elem.second.push_back("23:59");
        }
        
        vector<string> info = elem.second;
        int total = 0;
        for(int i = 0;i<info.size()-1;i+=2)
        {
            total += timeDiff(info[i], info[i+1]);
        }
        
        int price = fees[1];
        if(total > fees[0])
        {
            price += ceil((total-fees[0])/(double)fees[2]) * fees[3];
        }
        
        answer.push_back(price);
    }
    return answer;
}