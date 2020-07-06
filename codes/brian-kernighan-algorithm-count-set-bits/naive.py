def count_set_bits(n):
    count = 0
    while n > 0:
        count += n & 1
        n = n >> 1
    return count

if __name__ == '__main__':
    print('Number of set bits of', 31, 'is', count_set_bits(31))
    print('Number of set bits of', 42, 'is', count_set_bits(42))
