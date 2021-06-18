h,w = map(int,input().split())

s = [input() for i in range(h)]

ans = 0
for i in range(h):
  for j in range(w):
    if i > 0 and s[i][j] == '.' and s[i-1][j] == s[i][j]:
      ans += 1
    if j > 0 and s[i][j] == '.' and s[i][j-1] == s[i][j]:
      ans += 1

print(ans)