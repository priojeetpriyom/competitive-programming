def isPrime(n, k=1000): 
    from random import randint
    if n < 2: return False
    for p in [2,3,5,7,11,13,17,19,23,29]:
        if n % p == 0: return n == p
    s, d = 0, n-1
    while d % 2 == 0:
        s, d = s+1, d/2
    for i in range(k):
        x = pow(randint(2, n-1), int(d), n)
        if x == 1 or x == n-1: continue
        for r in range(1, s):
            x = (x * x) % n
            if x == 1: return False
            if x == n-1: break
        else: return False
    return True

t = int(input()) 
#print("t ", t)
#v = []
# v = [int(x) for x in input().split(' ')]
# v = [int(x) for x in input().split()] 

# print("aise len_v: ", len(v))


for i in range(0, t):
    v = [int(x) for x in input().split()] 
    a = int(v[0])
    b = int(v[1])
    n = a*a - b*b

    if isPrime(n):
        print("YES")
    else:
        print("NO")
