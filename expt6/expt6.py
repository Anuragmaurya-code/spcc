def compute_first(grammar, non_terminal):
    first = set()

    # If the symbol is a terminal, add it to the first set and return
    if non_terminal not in grammar:
        first.add(non_terminal)
        return first

    # For each production rule for the non-terminal, recursively compute the first set of the symbol that appears first
    for rule in grammar[non_terminal]:
        if rule[0] == non_terminal:
            continue
        first_of_rule = compute_first(grammar, rule[0])
        first.update(first_of_rule)

        # If the symbol can derive epsilon, add the first set of the next symbol in the rule to the first set
        if 'ε' in first_of_rule:
            first_without_epsilon = first_of_rule.copy()
            first_without_epsilon.remove('ε')
            if len(rule) > 1:
                first_of_rest = compute_first(grammar, rule[1])
                first.update(first_of_rest.intersection(first_without_epsilon))
            else:
                first.update(first_without_epsilon)

    return first


def compute_follow(grammar, non_terminal):
    follow = set()

    # The follow set of the start symbol is always {$}
    if non_terminal == grammar['start']:
        follow.add('$')

    # For each non-terminal symbol in the grammar, find all the occurrences of the current symbol in the right-hand side of the rules
    for nt in grammar:
        for rule in grammar[nt]:
            if non_terminal in rule:
                follow_of_nt = compute_follow_nt(grammar, nt, rule, non_terminal)
                follow.update(follow_of_nt)

    return follow


def compute_follow_nt(grammar, nt, rule, symbol):
    follow = set()

    # If the symbol is at the end of the rule, add the follow set of the non-terminal to the follow set
    if rule[-1] == symbol:
        if nt != symbol:
            follow.update(compute_follow(grammar, nt))

    # For each symbol in the rule, add the first set of the next symbol to the follow set
    for i in range(len(rule) - 1):
        if rule[i] == symbol:
            next_symbol = rule[i+1]
            if next_symbol not in grammar:
                follow.add(next_symbol)
            else:
                first_of_next = compute_first(grammar, next_symbol)
                follow.update(first_of_next.difference({'ε'}))
                if 'ε' in first_of_next:
                    follow.update(compute_follow_nt(grammar, nt, rule[i+1:], symbol)) 

    # If the rule can derive epsilon and the symbol is not at the end, add the follow set of the non-terminal to the follow set
    if symbol in rule and 'ε' in compute_first(grammar, rule[rule.index(symbol)+1:]):
        if nt != symbol:
            follow.update(compute_follow(grammar, nt))

    return follow


# Example grammar
grammar = {
    'start': 'S',
    'S': ['AB', 'BC'],
    'A': ['a'],
    'B': ['b', 'ε'],
    'C': ['c']
}

# Compute first sets
for nt in grammar:
    first = compute_first(grammar, nt)
    print(f'First({nt}) = {first}')

# Compute follow sets
for nt in grammar:
    follow = compute_follow(grammar, nt)
    print(f'Follow({nt}) = {follow}')
 
