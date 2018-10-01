def main():
    pat = input()
    text = input()

    for i in range(len(text)-len(pat)+1):
        if text[i : i+ len(pat)] == pat:
            print(i, end=' ')

main()
