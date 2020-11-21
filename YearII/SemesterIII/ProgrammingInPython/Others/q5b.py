def matrixMultiplication(A, B):
    assert(len(A[0]) == len(B))
    C = [[0 for j in range(len(A[0]))] for i in range(len(B))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]
    return C


def matrixTranspose(A):
    B = [[0 for j in range(len(A[0]))] for i in range(len(A))]
    for i in range(len(A)):
        for j in range(len(A[0])):
            B[i][j] = A[j][i]
    return B


def matrixInput(rows=0, cols=0):
    A = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(int(input(f'Enter Element ({i + 1},{j + 1}): ')))
        A.append(row)
    return A


def matrixDisplay(A):
    for i in range(len(A)):
        for j in range(len(A[0])):
            print(A[i][j], end='\t')
        print()


if __name__ == '__main__':
    r = c = ch = 0

    r = int(input('Enter the No. of Rows in Matrix A: '))
    c = int(input('Enter the No. of Columns in Matrix A: '))
    A = matrixInput(r, c)

    r = int(input('Enter the No. of Rows in Matrix B: '))
    c = int(input('Enter the No. of Columns in Matrix B: '))
    B = matrixInput(r, c)

    while True:
        print('''
       MENU
==================
 (1) Multiply A.B
 (2) Transpose A
 (3) Transpose B
 (4) Display A
 (5) Display B
 (0) Exit
        ''')
        ch = int(input('Enter Choice: '))
        if ch == 1:
            M = matrixMultiplication(A, B)
            print('\nM = A.B')
            print('=======')
            matrixDisplay(M)
        elif ch == 2:
            T = matrixTranspose(A)
            print('\nT = A\'')
            print('=======')
            matrixDisplay(T)
        elif ch == 3:
            T = matrixTranspose(B)
            print('\nT = B\'')
            print('=======')
            matrixDisplay(T)
        elif ch == 4:
            print('\nMatrix A')
            print('========')
            matrixDisplay(A)
        elif ch == 5:
            print('\nMatrix B')
            print('========')
            matrixDisplay(B)
        elif ch == 0:
            break
        input('\nPress Enter to Continue...')
