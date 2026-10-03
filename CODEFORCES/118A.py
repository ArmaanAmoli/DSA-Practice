s = str(input()).lower();
vowels = ['a' , 'e' , 'i' , 'o' , 'u' , 'y']
ans  = ""
for c in s:
    if( c not in vowels):
        ans += '.' + c
print(ans)