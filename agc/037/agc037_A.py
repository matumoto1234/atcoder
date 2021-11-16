s = input()

pre = ""
now = ""
ans = 0
for i in range(len(s)):
  now += s[i]
  if pre != now:
    ans += 1
    pre = now
    now = ""

print(ans)