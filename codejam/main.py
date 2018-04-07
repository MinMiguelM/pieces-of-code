def troubleSort(list):
    done = False
    while not done:
        done = True
        for i in range(len(list) - 2):
            if list[i] > list[i+2]:
                done = False
                tmp = list[i]
                list[i] = list[i+2]
                list[i+2] = tmp

    for i in range(len(list)-1):
        if list[i] > list[i+1]:
            return i
    return 'OK'

testCases = int(input())
for i in range(1,testCases+1):
    input()
    D=[int(s) for s in input().split(" ")]
    out = troubleSort(D)
    print("Case #{}: {}".format(i,out))