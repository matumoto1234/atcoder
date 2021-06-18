import math

N, X = map(int,input().split())
x = list(map(int,input().split()))

x.append(X)
x.sort()

ans = x[1] - x[0]
for i in range(2,len(x)):
  ans = math.gcd(ans,x[i] - x[i-1])

print(ans)