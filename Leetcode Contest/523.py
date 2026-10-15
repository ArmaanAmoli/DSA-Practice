# import math
# # def threeFibonacciSum(n: int) -> bool:
# #     a = 0
# #     b = 1
# #     c = a+b
    
# #     while(c<=n):
# #         if(a+b+c == n):
# #             return True
        
# #         a = b
# #         b = c
# #         c = a+b
# #     return False

# # print(threeFibonacciSum(2))

# def is_prime(i:int)->bool:
#     for j in range(2 , math.ceil(math.sqrt(i))+1):
#         if i%j ==0:
#             return False
#     return True

# def findPrimes(n:int)->list[int]:
#     if n == 1: return [2]
    
#     ans = [2]
    
#     for i in range(3,n+1):
#         if(is_prime(i)):
#             ans.append(i)
#     return ans

# def maxPrimes(n:int , s:int)->list[int]:
#     ans = []
#     final_ans = []
#     primes = findPrimes(n)
#     current_sum = 0
#     i,j=0,0
#     while i<len(primes):
#         right = primes[i]
#         if(right > s):
#             break
        
#         if(current_sum + right <= s):
#             current_sum+=right
#             ans.append(right)
#         else:
#             if (
#                 len(ans) > len(final_ans)
#                 or (
#                     len(ans) == len(final_ans)
#                     and current_sum > sum(final_ans)
#                 )
#             ):
#                 final_ans = ans.copy()
                
#             current_sum += right
#             ans.append(right)
            
#             while(j<=i and current_sum > s):
#                 current_sum -= primes[j]
#                 ans.pop(0)
#                 j+=1
#         i+=1
    
#     if (
#         len(ans) > len(final_ans)
#         or (
#             len(ans) == len(final_ans)
#             and current_sum > sum(final_ans)
#         )
#     ):
#         final_ans = ans.copy()
#     return final_ans

# print(maxPrimes(15 , 1))