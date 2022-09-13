#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string s = "";

void change(int n, int k)
{
    if(n/k > 0)
    {
        change(n/k, k);
    }
    
    s+= to_string(n%k);
}

vector<string> split(string s)
{
    istringstream ss(s);
    string tempBuffer;
    vector<string> x;
    while(getline(ss, tempBuffer,'0'))
    {
        x.push_back(tempBuffer);
    }
    
    return x;
}

bool primeCheck(long long int& num)
{
    if(num < 2)
    {
        return false;
    }
    for(int i = 2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    
    return true; //prime
}



int solution(int n, int k) {
    int answer = 0;
    
    change(n, k);
    vector<string> x = split(s);
    for(auto &elem : x)
    {
        if(elem == ""){
            continue;
        }
        long long int temp = stoll(elem);
        if(primeCheck(temp))
        {
            answer++;
        }
    }

    return answer;
}