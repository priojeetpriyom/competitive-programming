#!/usr/bin/env python3

def main():
    text = input()
    # print(text)
    mp = {}
    lenn = input()
    lenn = int(lenn)
    for i in range(0, len(text) - lenn + 1):
        if text[i: i + lenn] in mp:
            mp[text[i:i + lenn]] = mp[text[i:i + lenn]] + 1
        else:
            mp[text[i:i + lenn]] = 1
    mx = 0

    for i in mp.values():
        if i > mx:
            mx = i

    for i in mp.keys():
        if mp[i] == mx:
            print(i, end=' ')


main()
