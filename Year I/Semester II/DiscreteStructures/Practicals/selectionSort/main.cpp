/**
 * Write a Program to implement Selection Sort. Find the number of
 * comparisons during each pass and display the intermediate result. 
 * Use the observed values to plot a graph to analyse the complexity 
 * of algorithm.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
int selectionSort(int[], int);
int main()
{
    int size, comparisons;
    cout << "Enter array size: ";
    cin >> size;
    int array[size];
    // Worst Case
    cout << "Worst Case:\n------------\n";
    for (int i = 0; i < size; i++)
        array[i] = size - i;
    comparisons = selectionSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;
    // Best Case
    cout << "Best Case:\n------------\n";
    for (int i = 0; i < size; i++)
        array[i] = i + 1;
    comparisons = selectionSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;
    // Average Case
    cout << "Average Case:\n------------\n";
    ifstream fin("./random.txt");
    for (int i = 0; i < size; i++)
        fin >> array[i];
    fin.close();
    comparisons = selectionSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;
    return 0;
}
int selectionSort(int array[], int size)
{
    int i, j, k, small, iterCompCount, count = 0;
    cout << "Array: ";
    for (k = 0; k < size; k++)
        cout << array[k] << " ";
    cout << endl;
    for (i = 0; i < size; i++)
    {
        iterCompCount = 0;
        small = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[small])
            {
                small = j;
            }
            count++;
            iterCompCount++;
        }
        int temp = array[i];
        array[i] = array[small];
        array[small] = temp;
        cout << "Comparisons Made in Pass " << i + 1 << ": " << iterCompCount << endl;
        cout << "After Pass " << i + 1 << ": ";
        for (k = 0; k < size; k++)
            cout << array[k] << " ";
        cout << endl;
    }
    return count;
}
