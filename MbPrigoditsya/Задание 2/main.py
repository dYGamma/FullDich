import random

RED = [1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36]
BLACK = [2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35]
FIRSTDOZEN = list(range(1, 13))
SECONDDOZEN = list(range(13, 25))
THIRDDOZEN = list(range(25, 37))

def print_welcome():
    print("===== Казино рулетка by demonyga =====")

def print_balance(balance):
    print("Ваш баланс:", balance, "фишек")

def print_minimum_bet():
    print("Сумма ставки не может быть меньше 5 фишек")

def print_insufficient_funds():
    print("У Вас недостаточно фишек")

def print_invalid_bet_type():
    print("Неверно указан тип ставки")

def print_invalid_dozen():
    print("Неверно указана дюжина")

def print_invalid_number():
    print("Неверно указано число")

def print_winning_number(number):
    print("Выпало число:", number)

def print_win(balance):
    print("Вы выиграли! Ваш баланс:", balance, "фишек")

def input_bet_amount():
    return int(input("Введите сумму Вашей ставки (минимальная ставка 5 фишек): "))

def input_bet_type():
    return int(input("На что ставите? (1 - Красное, 2 - Черное, 3 - Дюжины, 4 - Число): "))

def input_dozen():
    return int(input("На какую дюжину ставите? (1, 2, 3): "))
def input_number():
    return int(input("На какое число ставите? (0-36): "))


def play_roulette():
    balance = 100
    bet_amount = 0
    choise = 0

    print_welcome()
    print_balance(balance)

    while balance >= 5:
        while bet_amount == 0:
            bet_amount = input_bet_amount()
            if bet_amount < 5:
                print_minimum_bet()
                bet_amount = 0
            if bet_amount > balance:
                print_insufficient_funds()
                bet_amount = 0

        choise = input_bet_type()
        while (choise <= 0 or choise > 4):
            print_invalid_bet_type()
            choise = input_bet_type()
        if (choise == 3):
            dozen = input_dozen()
            while (dozen <= 0 or dozen > 3):
                print_invalid_dozen()
                dozen = input_dozen()
        if (choise == 4):
            number_bet = input_number()
            while (number_bet < 0 or number_bet > 36):
                print_invalid_number()
                number_bet = input_number()

        balance -= bet_amount
        number = random.randint(0, 36)
        print_winning_number(number)

        if ((choise == 1 and number in RED) or (choise == 2 and number in BLACK)):
            balance += bet_amount * 2
            print_win(balance)
        elif ((choise == 3 and dozen == 1 and number in FIRSTDOZEN) or (choise == 3 and dozen == 2 and number in SECONDDOZEN) or (
                choise == 3 and dozen == 3 and number in THIRDDOZEN)):
            balance += bet_amount * 3
            print_win(balance)
        elif (choise == 4 and number_bet == number):
            balance += bet_amount * 36
            print_win(balance)
        else:
            print("Вы проиграли. Ваш баланс:", balance, "фишек")

        bet_amount = 0

play_roulette()