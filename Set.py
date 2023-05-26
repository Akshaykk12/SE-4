def setA():
    global setA
    setA = set(())
    loop=True
    while loop:
        print("\n1.Enter element \n2.Remove element \n3.Exit \n")
        ch=int(input())
        if ch == 1:
            key = int(input("Element: "))
            setA.add(key)
            print("=========DONE==========")
        elif ch == 2:
            key = int(input("Element: "))
            setA.discard(key)
            print("=========DONE==========")
        elif ch == 3:
            loop= False
            print("=========DONE==========")

def setB():
    global setB
    setB = set(())
    loop=True
    while loop:
        print("\n1.Enter element \n2.Remove element \n3.Exit \n")
        ch=int(input())
        if ch == 1:
            key = int(input("Element: "))
            setB.add(key)
            print("=========DONE==========")
        elif ch == 2:
            key = int(input("Element: "))
            setB.discard(key)
            print("=========DONE==========")
        elif ch == 3:
            loop= False
            print("=========DONE==========")

def union():
    setC= setA.union(setB)
    print("\nA Union B =",setC)
    print("=========DONE==========")

def intersection():
    setD= setA.intersection(setB)
    print("\nA Intersection B =",setD)
    print("=========DONE==========")

def difference():
    setE= setA.difference(setB)
    print("\nA Difference B =",setE)
    print("=========DONE==========")

def subset():
    print(setA.issubset(setB))
    print("=========DONE==========")

def search():
    print("In which set u want to search\n1.Set A\n2.Set B ")
    choice=int(input("choice: "))
    key=int(input("enter key to be searched: "))
    if choice==1:
        print(key in setA)
    else:
        print(key in setB)

def main():
    print("Choose the operation")
    loop = True
    while loop:
        print("\n1.Create set A \n2.Create set B \n3.Union \n4.Intersection \n5.Difference \n6.Subset \n7.Search \n8.Display \n9.Exit")
        choice= int(input("choice: "))

        if choice==1:
            setA()
        elif choice == 2:
            setB()
        elif choice == 3:
            union()
        elif choice == 4:
            intersection()
        elif choice == 5:
            difference()
        elif choice == 6:
            subset()
        elif choice == 7:
            search()
        elif choice == 8:
            print("\nSet A = ",setA)
            print("\nSet B = ",setB)
            print("=========DONE==========")
        elif choice == 9:
            loop = False

main()
