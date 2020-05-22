def intersection_array(a, b, n, m):
    i = 0
    j = 0

    while i < n and j < m:

        if a[i] == b[j]:
            print(a[i])
            i = i + 1
            j = j + 1
        else:
            if a[i] < b[j]:
                i = i + 1
            else:
                j = j + 1


if __name__ == "__main__":
    a = [2, 5, 8, 13, 15]
    b = [1, 3, 8, 15, 18, 20, 25]
    intersection_array(a, b, 5, 7)
