# with open('./prog.txt') as t:
#     text = t.read().split()

# keywords = ["void", "main", "int", "float", "bool", "double", "signed", "unsigned", "if", "else", "for", "while", "do"
#             , "goto", "return", "char", "case", "enum", "include", "stdio.h", "%d", "printf", "scanf", "void", "const"
#             , "volatile", "struct", "sizeof", "typeof", "static"]

# operators = ["=", "==", "+", "-", "*", "/", "%", "++", "--", "+=", "-=", "<", ">", "<=", ">=", "!=", "||", "&&"]

# punctuations = [";", "(", ")", "{", "}", "[", "]", "'", ",", "#", ":", '"']


# def detect_keyword(text):
#     arr=[]
#     for word in text:
#         if word in keywords:
#             arr.append(word)
#     return list(set(arr))


# def detect_operator(text):
#     arr=[]
#     for word in text:
#         if word in operators:
#             arr.append(word)
#     return list(set(arr))


# def detect_punctuation(text):
#     arr=[]
#     for word in text:
#         if word in punctuations:
#             arr.append(word)
#     return list(set(arr))


# def detect_num(text):
#     arr=[]
#     for word in text:
#         try:
#             int(word)
#             arr.append(word)
#         except:
#             pass
#     return list(set(arr))


# def detect_identifier(text):
#     k = detect_keyword(text)
#     o = detect_operator(text)
#     p = detect_punctuation(text)
#     n = detect_num(text)
#     not_idet = k+o+p+n
#     arr=[]
#     for word in text:
#         if word not in not_idet:
#             arr.append(word)
#     return list(set(arr))

# print("Keywords: ", detect_keyword(text))
# print("Operators: ", detect_operator(text))
# print("Punctuations: ", detect_punctuation(text))
# print("Identifier: ", detect_identifier(text))
# print("Numbers: ", detect_num(text))

with open("./data.txt") as t:
    text = t.read().split()

keywords = ["void", "main", "int", "float", "bool", "double", "signed", "unsigned", "if", "else", "for", "while", "do"
            , "goto", "return", "char", "case", "enum", "include", "stdio.h", "%d", "printf", "scanf", "void", "const"
            , "volatile", "struct", "sizeof", "typeof", "static"]

operators = ["=", "==", "+", "-", "*", "/", "%", "++", "--", "+=", "-=", "<", ">", "<=", ">=", "!=", "||", "&&"]

punctuations = [";", "(", ")", "{", "}", "[", "]", "'", ",", "#", ":", '"']

def detectKeyword(text):
    arr=[]
    for word in text:
        if word in keywords:
            arr.append(word)
    return list(set(arr))

def detectOperators(text):
    arr=[]
    for word in text:
        if word in operators:
            arr.append(word)
    return list(set(arr))

def detectPunctuation(text):
    arr=[]
    for word in text:
        if word in punctuations:
            arr.append(word)
    return list(set(arr))

def detect_num(text):
    arr=[]
    for word in text:
        try:
            int(word)
            arr.append(word)
        except:
            pass
    return list(set(arr))

def detect_identifier(text):
    k = detectKeyword(text)
    o = detectOperators(text)
    p = detectPunctuation(text)
    n = detect_num(text)

    all = k+o+p+n
    arr=[]
    for word in text:
        if word not in all:
            arr.append(word)
    return list(set(arr))


print("Keywords: ", detectKeyword(text))
print("Operators: ", detectOperators(text))
print("Punctuations: ", detectPunctuation(text))
print("Numbers: ", detect_num(text))
print("Identifiers: ", detect_identifier(text))

