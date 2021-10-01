import cs50

while True:
    height = cs50.get_int("Half-pyramid’s height?\n")
    if 1 <= height <= 8:
        break
# print(f"Height: {height}")

for i in range(height):
    for j in range(height - i - 1):
        print(" ", end="")
    for j in range(i + 1):
        print("#", end="")
    print()    