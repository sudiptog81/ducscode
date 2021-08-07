class Account:
    def __init__(self):
        self.num = 0
        self.holder = ''
        self.balance = 0

    def __str__(self):
        return f'''
A/C No.: {self.num}
A/C Holder: {self.holder}
A/C Balance: {self.balance}'''


class Accounts:
    def __init__(self):
        self.accounts = []

    def add(self, num=0, holder=''):
        a = Account()
        a.num = num
        a.holder = holder
        a.balance = 0
        self.accounts.append(a)

    def search(self, num):
        for i in range(len(self.accounts)):
            if self.accounts[i].num == num:
                return i
        return -1

    def modify(self, num, bal):
        res = self.search(num)
        if res != -1:
            self.accounts[res].balance = bal
            print(f'A/C {num} Updated.')
        else:
            print('\nAccount Not Found.')

    def delete(self, num):
        res = self.search(num)
        if res != -1:
            print(f'Deleting A/C {num}.')
            self.accounts.remove(self.accounts[res])
        else:
            print('\nAccount Not Found.')


if __name__ == "__main__":
    accounts = Accounts()
    while True:
        print('''
        MENU
=====================
 (1) Add Account
 (2) Modify Account
 (3) Delete Account
 (4) Search Account
 (0) Exit
        ''')
        ch = int(input('Enter Choice: '))
        if ch == 1:
            try:
                num = int(input('Enter A/C No.: '))
                holder = input('Enter A/C Holder: ')
                if accounts.search(num) != -1:
                    raise KeyError()
                accounts.add(num, holder)
            except KeyError as e:
                print('Account Already Exists. Not Added.')
            except Exception as e:
                print('Invalid Input. Try Again.')
        elif ch == 2:
            num = int(input('Enter A/C No. for Updating: '))
            bal = int(input('Enter Updated A/C Balance: '))
            accounts.modify(num, bal)
        elif ch == 3:
            num = int(input('Enter A/C No. for Deleting: '))
            accounts.delete(num)
        elif ch == 4:
            num = int(input('Enter A/C No. for Searching: '))
            res = accounts.search(num)
            if res != -1:
                print(f'A/C {num} Found.')
                print(accounts.accounts[res])
            else:
                print('Account Not Found.')
        elif ch == 0:
            break
        input('\nPress Enter to Continue...')
