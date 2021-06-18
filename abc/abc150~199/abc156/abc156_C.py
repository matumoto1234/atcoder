n = int(input())
x = list(map(int,input().split()))

ans = 100100100100100
for p in range(1,101):
  sum = 0
  for i in range(n):
    sum+=(x[i]-p)*(x[i]-p)
  
  ans = min(ans,sum)

print(ans)