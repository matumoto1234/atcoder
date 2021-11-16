mod = 1000000007
n = int(input())

dic = {}
for i in range(1, n+1):
  dic[i] = 0

for i in range(2, n+1):
  j = 2
  x = i
  while j * j <= i:
    while x % j == 0:
      dic[j] += 1
      x = x // j
    j += 1
  if x > 1:
    dic[x] += 1

# print(dic.values())

ans = 1
for val in dic.values():
  ans *= val + 1
  ans %= mod

print(ans)