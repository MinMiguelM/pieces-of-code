filenameInput = "A-small-attempt1.in"
#filenameInput = "test.in"
filenameOutput = "A-small-attempt1.out"

numbers = dict({0:"ZERO",1:"ONE",2:"TWO",3:"THREE",4:"FOUR",5:"FIVE",6:"SIX",7:"SEVEN",8:"EIGHT",9:"NINE"})
numbersR = dict({"ZERO":0,"ONE":1,"TWO":2,"THREE":3,"FOUR":4,"FIVE":5,"SIX":6,"SEVEN":7,"EIGHT":8,"NINE":9})

def stringNumber(S):
    if S.count('\n') > 0:
        S.remove('\n')
    S.sort()
    ret = []
    k=0
    while len(S) != 0 and k!=6:
        for i in range(10):
            subString = S[:]
            listIndex = []
            for j in list(numbers[i]):
                num = compare(subString,j)
                if num >= 0:
                    subString.pop(num)
                    listIndex.append(j)
            if len(listIndex) == len(list(numbers[i])):
                ret.append(listIndex[:])
                S = subString[:]
        k+=1
    retn = []
    for k in ret:
        retn.append(numbersR[(''.join(k))])
    retn.sort()
    return retn

def compare(S,l):
    i=0
    while i < len(S):
        if S[i] == l:
            return i
        i+=1
    return -1

def loadFile():
    f = open(filenameInput,"r")
    tc = int(f.readline())
    string=""
    i=1
    while(i<=tc):
        c = stringNumber(list(f.readline()))
        num = ""
        for k in c:
            num += str(k)
        string += "Case #"+(str(i))+": "+num+"\n" if i<tc else "Case #"+str(i)+": "+num
        i+=1
    saveFile(string)
    f.close()

def saveFile(string):
    f = open(filenameOutput,"w")
    #f.write("Case #",x,": ",y, )
    f.write(string)
    f.close()

loadFile()
