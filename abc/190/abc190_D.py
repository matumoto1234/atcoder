n=int(input())

def is_valid(l,r,n):
  sum = (l+r)*(r-l+1)//2
  return sum>=n

ans=0
# sum([i,valid]) >= Nを二分探索
for i in range(1,10**7):
  if i>n:
    break
  valid=10**13
  invalid=i-1
  while(abs(valid-invalid)>1):
    mid=(valid+invalid)//2
    if(is_valid(i,mid,n)): valid=mid
    else: invalid=mid

  sum=(i+valid)*(valid-i+1)//2
  if(sum==n):
    # print(i,valid)
    ans+=1
  
print(2*ans)