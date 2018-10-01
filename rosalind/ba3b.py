def main():
    str = input()
    print(str, end='')
    times = len(str)
    while True:
        str = input()
        if str=='':
            break
        print(str[times-1], end='')

main()
