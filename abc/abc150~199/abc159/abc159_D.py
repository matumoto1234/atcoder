import math

maxn = 200000

cnt = [0 for i in range(maxn + 1)]

n = int(input())
a = [0 for i in range(n)]
a = list(map(int,input().split()))

for i in range(n):
  cnt[a[i]] += 1

allsum = 0
for i in range(maxn + 1):
  allsum += cnt[i]*(cnt[i] - 1) // 2

for i in range(n):
  subv = cnt[a[i]] - 1
  print(allsum - subv)