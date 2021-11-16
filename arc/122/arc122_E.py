import math

def lcm(a,b):
  return a*b//math.gcd(a,b)

n=int(input())
a=list(map(int,input().split()))

ans=[]
update=True
while update:
  update=False
  for i in range(len(a)):
    p=1
    for j in range(len(a)):
      if i==j:
        continue
      p=lcm(p,a[j])
      p=math.gcd(p,a[i])

    if a[i]>p:
      ans.append(a[i])
      a=a[:i]+a[i+1:]
      update=True
      break

ans=ans[::-1]
if len(ans)==n:
  print("Yes")
  print(*ans)
else:
  print("No")