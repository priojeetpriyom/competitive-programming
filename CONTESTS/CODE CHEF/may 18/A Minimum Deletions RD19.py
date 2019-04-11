import math

def main():
    
    t = int(input())
    
    for tc in range(t):
        n = int(input())
        ans =0
        x = input().split(" ")
        
        ans = int(x[0])
        for i in range(n):
            ans = math.gcd(ans, int(x[i]) )
            
        if ans==1:
            print(0)
        else:
            print(-1)
    return 0
            
main()