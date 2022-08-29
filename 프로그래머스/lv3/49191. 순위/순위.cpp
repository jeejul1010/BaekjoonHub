#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int solution(int n, vector<vector<int>> results) {
    
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    
    int answer = 0;
    
    for(const auto& match:results)
    {
        graph[match[0]][match[1]] = 1;
    }
    
    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<n+1;j++)
        {
            if(i==j)
            {
                graph[i][j] = 0;
            }
        }
    }
    
    for(int k = 1;k<n+1;k++)
    {
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<n+1;j++)
            {
                if(graph[i][j] == INF)
                {
                    graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
                }
                
            }
        }
    }
    
    for(int i = 1;i<n+1;i++)
    {
        int count = 0;
        
        for(int j = 1;j<n+1;j++)
        {
            if(graph[i][j] != INF || graph[j][i] != INF)
            {
                count++;
            }
        }
        
        if(count==n)
        {
            answer++;
        }
    }
    
    return answer;
}