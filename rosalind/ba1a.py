def main():
    text = input()
    pattern = input()
    cnt = 0
    for i in range(len(text)-len(pattern)+1):
        if text[i:i+len(pattern)] == pattern:
            cnt = cnt + 1

    print(cnt)
main()
