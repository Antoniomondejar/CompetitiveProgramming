from typing import List, Tuple


def add_with_cents(x: Tuple[int, int], y: Tuple[int, int]) -> Tuple[int, int]:
    xd, xc = x
    yd, yc = y

    ansd = xd + yd
    ansc = xc + yc

    if ansc >= 100:
        ansc -= 100
        ansd += 1

    return ansd, ansc


def read_number(s: str) -> Tuple[int, int]:

    parts: List[str] = s.split('.')

    if len(parts) == 1:
        return int(parts[0]), 0
    elif (len(parts[-1]) == 3):
        ans = ""
        for p in parts:
            ans += p

        return int(ans), 0

    else:
        ans = ""
        for p in parts[:-1]:
            ans += p

        return int(ans), int(parts[-1])


def show_with_cents(x: Tuple[int, int]) -> str:
    xd, xc = x

    ans = ""

    if xd > 0:
        while xd > 0:
            if ans != "":
                ans = '.' + ans
            part = str(xd % 1000)
            if xd > 1000:
                while len(part) < 3:
                    part = '0' + part
            ans = part + ans
            xd = xd // 1000
    else:
        ans += '0'

    if xc != 0:
        if xc >= 10:
            ans += '.' + str(xc)
        else:
            ans += '.0' + str(xc)

    return ans


def main():
    s = input()

    ans: Tuple[int, int] = (0, 0)

    last_was_number = False
    number = ""
    for c in s:
        if c.isalpha():
            if last_was_number:
                ans = add_with_cents(ans, read_number(number))
                number = ""
                last_was_number = False
        else:
            last_was_number = True
            number += c

    if last_was_number:
        ans = add_with_cents(ans, read_number(number))

    print(show_with_cents(ans))


main()
