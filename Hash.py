import array as hash

def insert(size, table):    
    key1=input("key: ")
    key=int(key1)
    location=key % size
    
    if table[location] == -1:
        table[location]=key
        print("key is stored at index", location)
    else:
        print("which method you want to apply: \n1.linear probing\n2.quadratic probing" )
        choice=int(input("choice: "))
        
        if choice==1:
            linear_probing(table, location, key, size)
        else:
            quadratic_probing(table, location, key, size)
            
def linear_probing(table, location, key, size):
    for i in range(location+1, size):
        if table[i]==-1:
            table[i]=key
            return
            print("collision is resolved by lineasr probing\nkey is stored at index ", i)

    for i in range(0, location):
        if table[i]==-1:
            table[i]=key
            return
            print("collision is resolved by lineasr probing\nkey is stored at index ", i)
    
def quadratic_probing(table, location, key, size):
    for i in range(1, size):
        new_location=(key + i*i)%size
        if table[new_location]==-1:
            table[new_location]=key
            break
    print("collision is resolved by quadratic probing\nkey is stored at index: ", new_location )
    
    
def display(size, table):
    print("|", end=" ")
    for i in range (size):
        print(table[i], "|", end=" ")

def delete(size, table):
    del_key1=input("key to be deleted: ")
    del_key=int(del_key1)
    for i in range(size):
        if table[i]==del_key:
            table[i]=-1
            break
    print("key is deleted")

def main():
    loop=True
    size=int(input("size: "))
    table=hash.array('i', [-1]*size)
    print("choose the option: ")
    while loop:
        print("1.insert\n2.display\n3.delete\n4.exit")
        ch=int(input("choice: "))
        if ch ==1:
            insert(size, table)
        elif ch==2:
            display(size, table)
        elif ch==3:
            delete(size, table)
        elif ch==4:
            loop=False
    
    
main()
