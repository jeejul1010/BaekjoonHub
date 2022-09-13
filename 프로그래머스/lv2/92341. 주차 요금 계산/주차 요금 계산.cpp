#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct carRecord{
    string time;
    string carNum;
    string info;
};

bool cmp(const carRecord& a, const carRecord& b)
{
    if(a.carNum < b.carNum)
    {
        return true;
        
    }
    
    if(a.carNum == b.carNum)
    {
        if(a.time <= b.time)
        {
            return true;
        }
    }
    
    return false;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    vector<carRecord> recordList;
    
    for(const auto& record:records)
    {
        vector<string> x;
        istringstream ss(record);
        string temp;
        char seperator = ' ';
        
        while(getline(ss, temp, seperator))
        {
            x.push_back(temp);
        }
        
        recordList.push_back({x[0], x[1], x[2]});
    }
    
    sort(recordList.begin(), recordList.end(), cmp);
    
    for(const auto& el:recordList)
    {
        cout<<el.carNum<<endl;
        cout<<el.time<<endl;
    }
    
    string curCar = "";
    int prevTime = 0;
    int totalTime = 0;
    string lastInfo = "";
    
    vector<int> answer;
    
    for(const auto& record:recordList)
    {
        if(curCar != record.carNum && curCar != "")
        {
            if(lastInfo == "IN")
            {
                totalTime += 23 * 60 + 59 - prevTime;
            }
            
            cout<<totalTime<<endl;
            int totalFee;
            if(totalTime <= fees[0])
            {
                totalFee= fees[1];
            }
            else
            {
                totalFee = fees[1] + ceil((totalTime - fees[0])/double(fees[2])) * fees[3];
            }
            answer.push_back(totalFee);
            totalTime = 0;
        }
        
        curCar = record.carNum;
        
        int minutes;
        string str = record.time;
        string hour = str.substr(0, 2);
        string minute = str.substr(3, 2);

        minutes = stoi(hour) * 60 + stoi(minute);
        
        if(record.info == "IN")
        {
            prevTime = minutes;
            lastInfo = "IN";
        }
        else
        {
            totalTime += minutes - prevTime;
            prevTime = 0;
            lastInfo = "OUT";
            
        }
        
    }
    
    if(lastInfo == "IN")
    {
        totalTime += 23 * 60 + 59 - prevTime;
    }

    int totalFee;
    if(totalTime <= fees[0])
    {
        totalFee= fees[1];
    }
    else
    {
        totalFee = fees[1] + ceil((totalTime - fees[0])/double(fees[2])) * fees[3];
    }
    answer.push_back(totalFee);
    
    return answer;
}