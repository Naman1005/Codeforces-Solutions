palindromes = []
def check(hour, min):
    h = str(hour)
    m = str(min)
    while len(h) < 2:
        h = "0" + h
    while len(m) < 2:
        m = "0" + m
    if h[::-1] == m or h == m[::-1]:
        palindromes.append((int(h), int(m)))
 def add_time(curr_hour, curr_min, add_minutes):
    new_min = curr_min + add_minutes
    new_hour = curr_hour
    if new_min >= 60:
        new_hour = curr_hour + new_min // 60
        new_min %= 60
    if new_hour >= 24:
        new_hour %= 24
    return new_hour, new_min
  for h in range(24):
    for m in range(60):
        check(h, m)
for _ in range(int(input())):
    ans = 0
    time, gap = input().split()
    hour, min = map(int, time.split(':'))
    gap = int(gap)
    rec = dict()
    for i in range(1442):
        if (hour,min) in rec:
            break
        else:
            rec[(hour, min)] = 1
        if (hour, min) in palindromes:
            ans += 1
        hour, min = add_time(hour, min, gap)
    print(ans)