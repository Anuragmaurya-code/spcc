OPERATORS = set(['+', '-', '*', '/', '(', ')'])
PRI = {'+': 1, '-': 1, '*': 2, '/': 2}

def infix_to_postfix(formula):
    stack = []  # only pop when the coming op has priority
    output = ''
    for ch in formula:
        if ch not in OPERATORS:
            output += ch
        elif ch == '(':
            stack.append('(')
        elif ch == ')':
            while stack and stack[-1] != '(':
                output += stack.pop()
            stack.pop()  # pop '('
        else:
            while stack and stack[-1] != '(' and PRI[ch] <= PRI[stack[-1]]:
                output += stack.pop()
            stack.append(ch)
    # leftover
    while stack:
        output += stack.pop()
    # print("POSTFIX: {}".format(output))
    return output

def generate3AC(pos):
    # print("### THREE ADDRESS CODE GENERATION ###")
    exp_stack = []
    t = 1
    ac_exp = []

    for i in pos:
        if i not in OPERATORS:
            exp_stack.append(i)
        else:
            # print(f't{t} := {exp_stack[-2]} {i} {exp_stack[-1]}')
            ac_exp.append([t, exp_stack[-2], i, exp_stack[-1]])
            exp_stack = exp_stack[:-2]
            exp_stack.append(f'#{t}')
            t += 1
    return ac_exp

op_code = {
    '+' : 'ADD',
    '-' : 'SUB',
    '*' : 'MUL',
    '/' : 'DIV'
}
def CodeGen(res):
    reg_idx = 1
    moved = {}
    curr_reg = {}

    for exps in res:
        print(f'\n#{exps[0]} = {exps[1]} {exps[2]} {exps[3]}')
        operands = [1,3]
        new = []

        for x in operands:
            if exps[x] not in moved and '#' not in exps[x]:
                moved.update({exps[x]: reg_idx})
                reg_idx += 1
                new.append(exps[x])
            if exps[x] not in moved and '#' in exps[x]:
                # moved.update({ '#' + str(exps[x]).strip('#'): curr_reg[int(str(exps[x]).strip('#'))]})
                moved.update({ exps[x]: curr_reg[int(str(exps[x]).strip('#'))]})

        for x in new:
            print(f'MOV R{moved[x]}, {x}')

        print(f'{op_code[exps[2]]} R{moved[exps[1]]}, R{moved[exps[3]]}')
        curr_reg.update({exps[0]: moved[exps[1]]})        


exp = input("Enter your expression: ")
pos = infix_to_postfix(exp)
res = generate3AC(pos)
print(res)
# print(pos)
CodeGen(res)

