x,a,b=map(int,input().split())

a,b,x
if a>=b:
  print("delicious")
elif b<=a+x:
  print("safe")
else:
  print("dangerous")