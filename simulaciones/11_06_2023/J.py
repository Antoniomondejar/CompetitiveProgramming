




def main():
    n = int(input())
    s = input()

    ans = 1
    i = 1
    while i < n:
        if 2*i <= n and s[0:i] + s[0:i] == s[0:2*i]:
            ans += 1
            i *= 2
        else:
            ans += 1
            i += 1

    print(ans)

main()


