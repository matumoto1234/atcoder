N = int(input())
A = list(map(int,input().split()))
Q = []
i = 0
while True:
    if i == N:
        break
    elif i == N - 1:
        if min(Q) >= A[i]:
          break
        else:
            Q.append(A[i])
            break
    else:
        if A[i] >= A[i + 1]:
            Q.append(A[i])
            i += 1
        else:
            Q.append(A[i+1])
            i += 2

print(Q)