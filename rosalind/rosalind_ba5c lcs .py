import numpy as np

mat = np.zeros((1000,1000), dtype = np.int)

str1 = input()
str2 = input()

for i in range(1, len(str1)+1):
    for j in range(1, len(str2)+1):
        if(str1[i-1] == str2[j-1]):
            mat[i][j] = mat[i-1] [j-1]+1
        else:
            mat[i][j] = max(mat[i][j-1], mat[i-1][j])
            
            
    r = len(str1)
    c = len(str2)
    
    ans =""
    while(r>0 and c>0):
        if(mat[r][c] == mat[r-1][c-1]+1):
            ans = ans + str1[r-1]
            r-=1
            c-=1
        elif mat[r-1][c]==mat[r][c]:
            r-=1
        else:
            c-=1
    
            
print(ans[::-1])