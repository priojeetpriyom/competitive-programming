def main():
    text = input()
    ans=""
    mp = {
        'A':'T',
        'G':'C',
        'T':'A',
        'C':'G'
    }
    for i,j in zip(range(len(text)-1, -1, -1), range(0, len(text))):
        ans = ans + mp[text[i]]

    print(ans)


main()
