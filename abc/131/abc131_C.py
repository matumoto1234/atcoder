import math

# [l,r]
def range_cnt(l, r, a):
  return r//a - (l-1)//a

def lcm(x, y):
  return x * y // math.gcd(x, y)

a, b, c, d = map(int,input().split())

ans = 0
ans += range_cnt(a,b,c)
# print(ans)
ans += range_cnt(a,b,d)
# print(ans)
ans -= range_cnt(a,b,lcm(c,d))

ans = b - a + 1 - ans
print(ans)