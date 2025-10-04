def countdigi(iput):
    count = 0
    while iput>0: 
         iput = iput//10
         count = count + 1 
    return count

iput = int(input("Enter a Number: "))
countdigi(iput)