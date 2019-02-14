def isFibonaccciNumber(n):
    a = 0
    b = 0
    while (b<n):
        temp = b
        b += a
        a = temp
    return b == n

