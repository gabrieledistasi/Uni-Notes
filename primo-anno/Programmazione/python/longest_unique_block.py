def longest_unique_block(lst):

    if not lst:
        return (0, 0)

    pos = {}  # valore -> ultima posizione

    curr_start = 0

    best_start = 0
    best_len = 1

    for i in range(len(lst)):

        # duplicato dentro il blocco corrente
        if lst[i] in pos and pos[lst[i]] >= curr_start:
            curr_start = pos[lst[i]] + 1

        pos[lst[i]] = i

        curr_len = i - curr_start + 1

        if curr_len > best_len:
            best_len = curr_len
            best_start = curr_start

    return (best_start, best_start + best_len - 1)


lst = [1,2,3,2,4,5,6]

print(longest_unique_block(lst))