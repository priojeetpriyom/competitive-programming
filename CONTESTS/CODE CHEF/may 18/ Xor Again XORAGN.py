
t= int(input().split()[0])

for tc in range(t):
    n = int(input().split()[0])
    ans =0
    inp = [int(x) for x in input().split(" ")]
    for x in inp:
        ans = ans^ (x+x)
    
    print(ans)
    