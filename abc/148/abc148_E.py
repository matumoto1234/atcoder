n=int(input())
if n%2==1:
  print(0)
else:
  ans=0
  for i in range(1,100):
    ans+=n//2//pow(5,i)
  print(ans)