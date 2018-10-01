def main():
    str = input()
    mn = 1e9
    cnt =0
    for i in str:
        if i == 'G':
            cnt+=1
        elif i=='C':
            cnt-=1
        if cnt < mn:
            mn = cnt
    # print(mn)
    cnt=0
    for i in range(len(str)):
        if str[i]=='G':
            cnt+=1
        elif str[i]=='C':
            cnt-=1
        if cnt == mn:
            print(i+1, end=' ')

main()
