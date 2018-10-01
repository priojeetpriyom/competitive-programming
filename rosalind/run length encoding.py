def main():
    text = input()
    i=0
    while i< len(text):
        c = text[i]
        cnt=0
        while i< len(text) and c == text[i]:
            cnt+=1
            i+=1
        print(cnt, end='')
        print(c, end='')

main()
