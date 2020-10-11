"""
Consider a showroom of electronic products, where there are various salesmen.
Each salesman is given a commission of 5%, depending on the sales made per 
month. In case the sale done is less than 50000, then the salesman is not 
given any commission. Write a function to calculate total sales of a salesman 
in a month, commission and remarks for the salesman. Sales done by each sales
man per week is to be provided as input. Use tuples/list to store data of sal
esmen. Assign remarks according to the following criteria:

    Excellent: Sales >=80000
    Good: Sales>=60000 and <80000
    Average: Sales>=40000 and <60000
    Work Hard: Sales < 40000

Written by Sudipto Ghosh for the University of Delhi
"""


def calculateRenumeration(n):
    '''
    Calculates sales, commission and determines
    the remarks for n salesmen

    Accepts:
        n {int} -- number of salesmen
    '''
    s = 0
    salesmen = []
    for i in range(1, n + 1, 1):
        salesman = [0, 0, '']
        print(f'\nSalesman {i}')
        print('============')
        for j in range(1, 5, 1):
            s = float(input(f'Enter Sales in Week {j}: '))
            assert s >= 0, 'invalid entry'
            salesman[0] += s
        if salesman[0] > 50000:
            salesman[1] = 0.05 * salesman[0]
        if salesman[0] >= 80000:
            salesman[2] = 'Excellent'
        elif salesman[0] >= 60000:
            salesman[2] = 'Good'
        elif salesman[0] >= 40000:
            salesman[2] = 'Average'
        elif salesman[0] < 40000:
            salesman[2] = 'Work Hard'
        salesmen.append(salesman)
    print()
    for i in range(1, n + 1, 1):
        print('''
    Salesman %d Summary
================================
Total Sales:      %10.2f
Total Commission: %10.2f
Remarks:          %10s
        ''' % (i,
               salesmen[i - 1][0],
               salesmen[i - 1][1],
               salesmen[i - 1][2]))


def main():
    n = 0
    n = int(input('Enter Number of Salesmen: '))
    calculateRenumeration(n)


if __name__ == '__main__':
    main()
