

n = int(input())
points = []
x_sum = 0
y_sum = 0
for i in range(n):
    l = list(map(int , input().split()))
    x_sum += l[0]
    y_sum += l[1]
    points.append(l)

x_avg = x_sum / n
y_avg = y_sum / n

print(x_avg , y_avg)

num = 0
den = 0
print(points)
for i in range(n):
    num += (points[i][0] - x_avg) * (points[i][1] - y_avg)
    den += ((x_avg-points[i][0]) ** 2)
    # varience += (((points[i][0] - x_avg) * (points[i][1] - y_avg)) / ((x_avg-points[i][0]) ** 2))

b = num /den
print(b)
print(y_avg - (b* x_avg))
