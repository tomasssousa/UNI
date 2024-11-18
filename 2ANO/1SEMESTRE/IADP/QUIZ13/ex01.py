def iscons(letter):
    vogais = ['a', 'e', 'i', 'o', 'u']
    res = letter.lower()
    if 'a' <= res <= 'z':
        if res not in vogais:
            return True
        else:
            return False
    else:
        return False
    
print(iscons('/'))