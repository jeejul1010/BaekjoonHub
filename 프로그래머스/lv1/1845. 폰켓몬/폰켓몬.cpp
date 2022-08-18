#include <vector>
#include <set>

using namespace std;


int solution(vector<int> nums)
{
    int answer = 0;
    int numsLength = nums.size();
    set<int> s;
    
    for(int i = 0;i<numsLength;i++)
    {
        s.insert(nums[i]);
    }
    
    if(s.size()>=(numsLength/2))
    {
        answer = numsLength/2;
    }
    else
    {
        answer = s.size();
    }
    
    return answer;
}