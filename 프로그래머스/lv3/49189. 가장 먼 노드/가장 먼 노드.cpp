#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    
    vector<vector<int>> graph(n+1);
    vector<int> distance(n+1, -1);
    
    for(const auto& e:edge)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    distance[1] = 0;
    queue<int> q;
    q.push(1);
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        
        for(const auto& neighbor: graph[front])
        {
            if(distance[neighbor] == -1)
            {
                distance[neighbor] = distance[front] + 1;
                q.push(neighbor);
            }
        }
    }
    
    sort(distance.begin(), distance.end(), greater<int>());
    
    int answer = 0;
    
    for(const auto& dist: distance)
    {
        if(dist!=distance[0])
        {
            break;
        }
        answer++;
    }
    
    return answer;
}