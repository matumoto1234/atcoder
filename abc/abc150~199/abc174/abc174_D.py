n = int(input())
c = input()

red_cnt = 0
for i in range(n):
  if c[i] == "R":
    red_cnt += 1

ans = 0
for i in range(red_cnt):
  if c[i] == "W":
    ans += 1

print(ans)