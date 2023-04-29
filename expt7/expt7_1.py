# OPERATORS = set(['+', '-', '*', '/', '(', ')'])
# PRI = {'+': 1, '-': 1, '*': 2, '/': 2}

# ### INFIX ===> POSTFIX ###
# def infix_to_postfix(formula):
#     stack = []  # only pop when the coming op has priority
#     output = ''
#     for ch in formula:
#         if ch not in OPERATORS:
#             output += ch
#         elif ch == '(':
#             stack.append('(')
#         elif ch == ')':
#             while stack and stack[-1] != '(':
#                 output += stack.pop()
#             stack.pop()  # pop '('
#         else:
#             while stack and stack[-1] != '(' and PRI[ch] <= PRI[stack[-1]]:
#                 output += stack.pop()
#             stack.append(ch)
#     # leftover
#     while stack:
#     	output += stack.pop()
#     print("POSTFIX: {}".format(output))
#     return output

#     # leftover
#     while op_stack:
#         op = op_stack.pop()
#         a = exp_stack.pop()
#         b = exp_stack.pop()
#         exp_stack.append( op+b+a )
#     print(f'PREFIX: {exp_stack[-1]}')
#     return exp_stack[-1]

# ### THREE ADDRESS CODE GENERATION ###
# def generate3AC(pos):
# 	print("### THREE ADDRESS CODE GENERATION ###")
# 	exp_stack = []
# 	t = 1
	
# 	for i in pos:
# 		if i not in OPERATORS:
# 			exp_stack.append(i)
# 		else:
# 			print(f't{t} := {exp_stack[-2]} {i} {exp_stack[-1]}')
# 			exp_stack=exp_stack[:-2]
# 			exp_stack.append(f't{t}')
# 			t+=1

# expres = input("INPUT THE EXPRESSION: ")
# pos = infix_to_postfix(expres)
# generate3AC(pos)




OPERATORS=['+', '-', '*', '/']
PRI = {'+':2, '-':2, '*':3, '/':3}

def postFix(inpt):
    output=""
    stack=[]
    for ch in inpt:
        if ch not in OPERATORS:
            output+=ch
        elif ch =='(':
            stack.append(ch)
        elif ch==')':
            while stack and stack[-1]!='(':
                output+=stack.pop()
            stack.pop()
        else:
            while stack and stack[-1]!='(' and PRI[ch]<=PRI[stack[-1]]:
                output+=stack.pop()
            stack.append(ch)
    
    while stack:
        output+=stack.pop()
    return output

def generate3AC(pos):
    exp_stack = []
    t = 1
    ans = []
    for i in pos:
        if i not in OPERATORS:
            exp_stack.append(i)
        else:
            ans.append([t, exp_stack[-2], i, exp_stack[-1]])
            # print(f't{t} = {exp_stack[-2]} {i} {exp_stack[-1]}')
            exp_stack = exp_stack[:-2]
            exp_stack.append(f'#{t}')
            t+=1
    return ans

opcode = {
    '+': "ADD",
    '-': "SUB",
    '*': "MUL",
    '/': "DIV"
}
    
def CodeGen(tac):
    reg = 1
    moved = {}
    curr = {}
    for exps in tac:
        print(f'#{exps[0]} = {exps[1]} {exps[2]} {exps[3]}')
        operand = [1,3]
        new = []
        for x in operand:
            if exps[x] not in moved and "#" not in exps[x]:
                moved.update({exps[x]:reg})
                reg+=1
                new.append(exps[x])
            elif exps[x] not in moved and "#" in exps[x]:
                moved.update({exps[x]:curr[int(str(exps[x]).strip('#'))]})
            
        for x in new:
            print(f'MOV R{moved[x]}, {x}')
        
        print(f'{opcode[exps[2]]} R{moved[exps[1]]}, R{moved[exps[3]]}\n')
        curr.update({exps[0]:moved[exps[1]]})

inpt = input("Enter an Expression: ")
pos = postFix(inpt)
print(pos)
tac = generate3AC(pos)
print(tac)
CodeGen(tac)