import matplotlib.pyplot as plt
def main():
    # print("something")
    str = input()
    print(str)
    mn = 1e9
    cnt =0
    points = []
    for i in str:
        if i == 'G':
            cnt+=1
        elif i=='C':
            cnt-=1
        points.append(cnt)

    plt.plot(points)
    plt.show()

main()
