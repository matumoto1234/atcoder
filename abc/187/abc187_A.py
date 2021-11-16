a,b = map(int,input().split())

def S(n):
  s=str(n)
  array=list(map(int,s))
  return sum(array)

if S(a)>S(b):
  print(S(a))
else:
  print(S(b))