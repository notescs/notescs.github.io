def count_set_bits(n):
    count = 0
    while n > 0:
        n = n & (n - 1)  # clear the right most bit
        count += 1
    return count

if __name__ == '__main__':
    print('Number of set bits of', 31, 'is', count_set_bits(31))
    print('Number of set bits of', 42, 'is', count_set_bits(42))
