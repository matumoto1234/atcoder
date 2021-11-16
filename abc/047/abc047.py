w, h, n = map(int,input().split())

left = down = 0
up = h
right = w

for _ in range(n):
  x, y, a = map(int, input().split())
  if a == 1:
    left = max(left, x)
  if a == 2:
    right = min(right, x)
  if a == 3:
    down = max(down, y)
  if a == 4:
    up = min(up, y)

print(max(0,up-down)*max(0,right-left))