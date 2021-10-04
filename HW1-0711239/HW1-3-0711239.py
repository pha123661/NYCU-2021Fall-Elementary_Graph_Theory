
def Erdos_Gallai(seq, n):
    H = [0]*n
    H[0] = seq[0]
    for i in range(2, n+1):
        H[i-1] = H[i-2] + seq[i-1]
    if H[-1] % 2:
        return False
    w = n
    for i in range(1, n+1):
        while w>0 and seq[w-1] < i:
            w = w-1
        y = max(i, w)
        if H[i-1] > i*(y-1) + H[n-1] - H[y-1]:
            return False
    return True


def main():
    input()
    seq = [int(k) for k in input().split()]

    seq = sorted(seq, reverse=True)

    if Erdos_Gallai(seq, len(seq)):
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    main()