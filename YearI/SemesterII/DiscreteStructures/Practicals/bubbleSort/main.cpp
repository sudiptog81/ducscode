/**
 * Write a Program to implement Bubble Sort. Find the number of
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
int bubbleSort(int *, int);
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
    comparisons = bubbleSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;
    // Best Case
    cout << "Best Case:\n------------\n";
    for (int i = 0; i < size; i++)
        array[i] = i + 1;
    comparisons = bubbleSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;
    // Average Case
    cout << "Average Case:\n------------\n";
    ifstream fin("./random.txt");
    for (int i = 0; i < size; i++)
        fin >> array[i];
    fin.close();
    comparisons = bubbleSort(array, size);
    cout << "Total Comparisons Made: "
         << comparisons << endl
         << endl;

    return 0;
}
int bubbleSort(int *array, int size)
{
    int temp, iterCompCount, count = 0;
    cout << "Array: ";
    for (int j = 0; j < size; j++)
        cout << array[j] << " ";
    cout << endl;
    for (int i = 0; i < size - 1; i++)
    {
        iterCompCount = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j + 1] < array[j])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            count++;
            iterCompCount++;
        }
        cout << "Comparisons Made in Pass " << i + 1
             << ": " << iterCompCount << endl;
        cout << "After Pass " << i + 1 << ": ";
        for (int k = 0; k < size; k++)
            cout << array[k] << " ";
        cout << endl;
    }
    return count;
}
