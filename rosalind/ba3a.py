def main():
    k = int(input())
    text = input()

    for i in range(len(text)-k+1):
        print(text[i: i+k])

main()
