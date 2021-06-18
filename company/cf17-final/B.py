s = input()

cnta = s.count('a')
cntb = s.count('b')
cntc = s.count('c')

mi = min(cnta,cntb,cntc)
cnta-=mi
cntb-=mi
cntc-=mi

ans = 1
if cnta >= 2:
  ans = 0
if cntb >= 2:
  ans = 0
if cntc >= 2:
  ans = 0

if ans == 1:
  print("YES")
else:
  print("NO")