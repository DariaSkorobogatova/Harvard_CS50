import cs50

credit = cs50.get_string("Number: ")

# выстраивает цифры карты в обратном направлении
copy_credit = credit[::-1]
# умножает на два каждую вторую цифру, начиная с цифры с индексом 1 (т.е. со второй)
#every_other_sum = [int(x) * 2 for x in copy_credit[1::2]]
# умножает на два кажду вторую цифру и результат умножения складывает между собой и суммирует все получившееся
# например цифра в карте была 9, *2 = 18, 1+8
# int от деления 18 на 10 = 1, остаток от деления 18 на 10 = 8
every_other_sum = sum([(int(x) * 2 // 10 + int(x) * 2 % 10) for x in copy_credit[1::2]])
# сумма цифр карты, начиная с цфиры с индексом 0 (т.е. с первой)
first_sum = sum([int(x) for x in copy_credit[0::2]])
total_sum = first_sum + every_other_sum

if total_sum % 10 == 0:
    if len(credit) == 15 and credit[0:2] in ['34', '37']:
        print('AMEX')
    elif len(credit) == 16 and 51 <= int(credit[0:2]) <= 55:
        print('MASTERCARD')
    elif len(credit) in [13, 16] and credit[0] == '4':
        print('VISA')
    else:
        print('INVALID')
else:
    print('INVALID')
