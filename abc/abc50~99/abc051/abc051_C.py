def range_up(x):
  for i in range(x):
    print("U", end="")

def range_down(x):
  for i in range(x):
    print("D", end="")

def range_left(x):
  for i in range(x):
    print("L", end="")

def range_right(x):
  for i in range(x):
    print("R", end="")

sx, sy, tx, ty = map(int,input().split())

range_right(tx-sx)
range_up(ty-sy)
range_left(tx-sx)
range_down(ty-sy)

range_down(1)
range_right(tx-sx + 1)
range_up(ty-sy + 1)
range_left(1)

range_up(1)
range_left(tx-sx + 1)
range_down(ty-sy + 1)
range_right(1)
print()