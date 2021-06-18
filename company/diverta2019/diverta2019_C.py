n = int(input())
s = [input() for _ in range(n)]

acnt = 0
bcnt = 0
bacnt = 0
cnt = 0
for i in range(n):
  if s[i][len(s[i]) - 1] == 'A' and s[i][0] == 'B':
    bacnt += 1
  elif s[i][len(s[i]) - 1] == 'A':
    acnt += 1
  elif s[i][0] == 'B':
    bcnt += 1

  cnt += s[i].count('AB')

if bacnt == 0:
  cnt += min(acnt, bcnt)
elif acnt + bcnt > 0:
  cnt += bacnt + min(acnt, bcnt)
else:
  cnt += bacnt - 1

print(cnt)