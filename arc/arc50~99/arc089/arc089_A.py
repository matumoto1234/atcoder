n = int(input())
ts = []
xs = []
ys = []

ts.append(0)
xs.append(0)
ys.append(0)

for i in range(n):
  t, x, y = map(int,input().split())
  ts.append(t)
  xs.append(x)
  ys.append(y)

ans = True
for i in range(1,n+1):
  t = ts[i] - ts[i-1]
  dist = abs(xs[i] - xs[i-1]) + abs(ys[i] - ys[i-1])
  t -= dist
  if (t < 0):
    ans = False
    break
  
  if (t % 2 == 1):
    ans = False
    break

if (ans == True):
  print("Yes")
else:
  print("No")