import cs50

while True:
    dollars = cs50.get_float("Change owed: ")
    if dollars >= 0:
        break

cents = round(dollars * 100)
# print(cents)
#z = int(cents / 25)
# if (cents - 25 * z == 0):
#     print(z)
# else:
#     y = int((cents - 25 * z) / 10)
#     if (cents - 25 * z - 10 * y == 0):
#         print(y + z)
#     else:
#         x = int((cents - 25 * z - 10 * y) / 5)
#         if (cents - 25 * z - 10 * y - 5 * x == 0):
#             print(x + y + z)
#         else:
#             m = cents - 25 * z - 10 * y - 5 * x
#             print(z + y + x + m)
total = 0
for coin in [25, 10, 5, 1]:
    total += cents // coin
    cents %= coin
print(total)    