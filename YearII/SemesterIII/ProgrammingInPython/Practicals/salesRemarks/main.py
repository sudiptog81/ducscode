"""
Consider a showroom of electronic products, where there are various salesmen.
Each salesman is given a commission of 5%, depending on the sales made per 
month. In case the sale done is less than 50000, then the salesman is not 
given any commission. Write a function to calculate total sales of a salesman 
in a month, commission and remarks for the salesman. Sales done by each 
salesman per week is to be provided as input. Assign remarks according to the 
following criteria:
    Excellent: Sales >=80000
    Good: Sales>=60000 and <80000
    Average: Sales>=40000 and <60000
    Work Hard: Sales < 40000

Written by Sudipto Ghosh for the University of Delhi
"""


def calculateRenumeration():
    totalSales = 0
    totalCommission = 0
    for i in range(1, 5):
        sales = float(input(f"Enter Sales in Week {i}: "))
        assert sales >= 0, 'invalid entry'
        totalSales += sales
    if totalSales > 50000:
        totalCommission = 0.05 * totalSales
    if totalSales >= 80000:
        remark = "Excellent"
    elif totalSales >= 60000:
        remark = "Good"
    elif totalSales >= 40000:
        remark = "Average"
    elif totalSales < 40000:
        remark = "Work Hard"
    print("""
        Employee Summary
================================
  Total Sales:      %10.2f
  Total Commission: %10.2f
  Remarks:          %10s
    """ % (totalSales, totalCommission, remark))


def main():
    calculateRenumeration()


if __name__ == "__main__":
    main()
