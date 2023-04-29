num = int(input("Enter Number of Production : "))
productions = []

for i in range(num):
    productions.append(input("Enter the grammar as E->E-A :"))

for production in productions:
    print("\nGRAMMAR : : : ", production)
    non_terminal = production[0]
    index = 3
    
    if non_terminal == production[index]:
        alpha = production[index+1]
        print(" is left recursive.")
        while production[index] != 0 and production[index] != '|':
            index += 1
            
        if production[index] != 0:
            beta = production[index+1]
            print("Grammar without left recursion:")
            print(non_terminal, "->", beta, non_terminal + "'")
            print(non_terminal + "'", "->", alpha, non_terminal + "'|E")
        else:
            print(" can't be reduced")
    else:
        print(" is not left recursive.")


