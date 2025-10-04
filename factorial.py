def facto(num):
    if num>=1:
        return num*facto(num-1)
    else:
        return 1
fact=1
num=int(input("Enter a Nunmber: "))
fact=facto(num)
print("Factorial =" ,fact)