#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    int quotient = n;
    int remainder;
    int digitCount = 0;
    long checkNumber = 0;
    
    bool isPrime;
    
    while(quotient != 0)
    {
        remainder = quotient % k;
        quotient = quotient / k;
        
        if(remainder != 0)
        {
            checkNumber += pow(10, digitCount) * remainder;
            digitCount++;
        }
        else
        {
            isPrime = true;
            for(long i = 2;i<= sqrt(checkNumber);i++)
            {
                if(checkNumber % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            
            if(isPrime && checkNumber != 0 && checkNumber != 1)
            {
                answer++;
            }
            
            checkNumber = 0;
            digitCount = 0;
        }
        
    }
    
    isPrime = true;
    for(long i = 2;i<= sqrt(checkNumber);i++)
    {
        if(checkNumber % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    if(isPrime && checkNumber != 0 && checkNumber != 1)
    {
        answer++;
    }
    
    return answer;
}