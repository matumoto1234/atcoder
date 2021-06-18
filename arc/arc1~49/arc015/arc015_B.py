import pprint

n = int(input())

cnt = [[0]*6]*3

for i in range(n):
  a, b = map(float, input().split())
  if a >= 35:
    cnt[0][0] += 1
  elif a >= 30:
    cnt[0][1] += 1
  elif a >= 25:
    cnt[0][2] += 1
  if b >= 25:
    cnt[0][3] += 1
  if b < 0 and a >= 0:
    cnt[0][4] += 1
  if a < 0:
    cnt[0][5] += 1

pprint.pprint(cnt)