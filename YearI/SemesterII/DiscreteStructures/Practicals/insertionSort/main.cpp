/**
 * Write a Program to implement Insertion Sort. Find the number of
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
int insertionSort(int *, int);
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
    comparisons = insertionSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;
    // Best Case
    cout << "Best Case:\n------------\n";
    for (int i = 0; i < size; i++)
        array[i] = i + 1;
    comparisons = insertionSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;
    // Average Case
    cout << "Average Case:\n------------\n";
    ifstream fin("./random.txt");
    for (int i = 0; i < size; i++)
        fin >> array[i];
    fin.close();
    comparisons = insertionSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;
    return 0;
}
int insertionSort(int *array, int size)
{
    int i, j, k, key, iterCompCount, count = 0;
    cout << "Array: ";
    for (k = 0; k < size; k++)
        cout << array[k] << " ";
    cout << endl;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        iterCompCount = 0;
        for (j = i - 1; j >= 0; j--)
        {
            count++;
            iterCompCount++;
            if (array[j] > key)
            {
                array[j + 1] = array[j];
            }
            else
            {
                break;
            }
        }
        array[j + 1] = key;
        cout << "Comparisons Made in Pass " << i << ": " << iterCompCount << endl;
        cout << "After Pass " << i << ": ";
        for (k = 0; k < size; k++)
            cout << array[k] << " ";
        cout << endl;
    }
    return count;
}
