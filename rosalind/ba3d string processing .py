k = input()
k = int(k)
text = input()
mp = {}

for i in range(len(text)-k+1):
#     print(text[i:i+k])
    pref = text[i: i+k-1]
    suf = text[i+1:i+k]
    if pref not in mp:
        mp[pref] =[suf]
    else:
        mp[pref].append(suf)
    
for i in sorted(mp.keys()):
    print(i,' -> ', end='')
    first = True
    for j in mp[i]:
        if first==False:
            print(',', end='')
        print(j, end='')
        first = False
    print()