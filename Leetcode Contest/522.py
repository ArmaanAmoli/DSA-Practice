# def minRotations(s: str) -> int:
#         ref = ord('0')
#         rot = 0
#         for c in s:
#             code = ord(c)
#             diff = abs(code - ref)
#             diff_rotate = abs(10 - diff)
#             rot += min(diff_rotate , diff)
#             ref = code
#         return rot

def minRotate(s:list , idx , idx_ref):
    ref = ord(s[idx_ref])
    c = s[idx]
    code = ord(c)
    diff = abs(code - ref)
    diff_rotate = abs(10 - diff)
    
    return min(diff_rotate , diff)

def minRotations( n: int, s: str) -> int:
    s_l = list(s)
    ref = ord('0')
    rot = 0
    chance_left = True
    for i in range(n):
        last_ref = ord(s_l[n-1])
        
        c = s_l[i]
        code = ord(c)
        
        diff = abs(code - ref)
        diff_rotate = abs(10 - diff)
        
        rot_current = min(diff , diff_rotate)
        
        # print( rot_current)
        
        last_diff = abs(ref - last_ref)
        last_diff_rotate = abs(10 - last_diff)
        
        rot_last = min(last_diff , last_diff_rotate)
        
        # print(rot_last)
        
        if chance_left and (rot_last <= rot_current) :
            print("ROTATE TRY")
            should_rotate = False
            if(rot_last != rot_current):
                should_rotate == True
            if(rot_last == rot_current):
                j = i
                k = n-1
                while(j<k):
                    j_r = minRotate(s_l , j+1 , j)
                    k_r = minRotate(s_l , k-1 , k)
                    if(j_r != k_r):
                        if(j_r<k_r):
                            break;
                        else:
                            should_rotate = True
                            chance_left = False
                            break        
                    j+=1
                    k-=1
            ref = last_ref
            if(should_rotate):
                print("rotated")
                for j in range(i , (n-i)//2):
                    idx_to_be_replaced_wit = n - (j+1)
                    temp = s_l[j]
                    s_l[j] = s_l[idx_to_be_replaced_wit]
                    s_l[idx_to_be_replaced_wit] = temp
                print(s_l)
            ref = last_ref
            rot+=rot_last
        else:
            ref = code
            print(ref)
            print((ref) - ord('0'))
            rot += rot_current
    return rot

print(minRotations(4, "1502"))