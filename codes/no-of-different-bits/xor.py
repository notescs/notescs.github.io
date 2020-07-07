def count_set_bits(n):
    count = 0
    while n > 0:
        n = n & (n - 1)  # clear the right most bit
        count += 1
    return count

def count_different_bits(a, b):
    return count_set_bits(a ^ b)

if __name__ == '__main__':
    print('Number of different bits of', 19, 'and', 10, 'is', count_different_bits(19, 10))
