/**
 * Create a class Relation, use Matrix notation to represent a relation. 
 * Include functions to check if the relation is Reflexive, Symmetric, 
 * Anti-symmetric and Transitive. Write a Program to use this class.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#define MAX_DIM 100

using namespace std;

/**
 * Relation Class Definition
 */
class Relation
{
private:
    int size;
    int set[MAX_DIM];
    int imageCount[MAX_DIM];
    int matrix[MAX_DIM][MAX_DIM];
    int relationInput[MAX_DIM][MAX_DIM];

protected:
    void getSet();
    void putSet();
    void getRelation();
    void putRelation();
    int indexOf(int);

public:
    Relation();
    void display();
    bool isReflexive();
    bool isSymmetric();
    bool isAntiSymmetric();
    bool isTransitive();
};

/**
 * Initialize a Relation object
 */
Relation::Relation()
{
    getSet();
    getRelation();
}

/**
 * Print the Relation object
 */
void Relation::display()
{
    putSet();
    putRelation();
}

/**
 * Accept user input for Set
 */
void Relation::getSet()
{
    printf("Enter Size of Set: ");
    scanf("%i", &size);
    printf("Enter Elements of Set: ");
    for (int i = 0; i < size; i++)
        scanf("%i", &set[i]);
}

/**
 * Print the Set
 */
void Relation::putSet()
{
    printf("Set: { ");
    for (int i = 0; i < size; i++)
        printf("%i, ", set[i]);
    printf("\b\b }\n");
}

/**
 * Finds the index of an element in an array
 */
int Relation::indexOf(int el)
{
    int i = 0;
    while (i < size)
    {
        if (set[i] == el)
            return i;
        i++;
    }
    return -1;
}

/**
 * Accept the Relation Matrix
 */
void Relation::getRelation()
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter number of images for Set Element %i: ", set[i]);
        scanf("%i", &imageCount[i]);
        printf("Enter images of Set Element %i: ", set[i]);
        for (int j = 0; j < imageCount[i]; j++)
        {
            scanf("%i", &relationInput[i][j]);
            if (indexOf(relationInput[i][j]) == -1)
            {
                printf("Error: Image not in Set");
                exit(-1);
            }
            matrix[i][indexOf(relationInput[i][j])] = 1;
        }
    }
    printf("\n");
}

/**
 * Print the Relation as a set of ordered pairs
 */
void Relation::putRelation()
{
    printf("Relation R:\n{\n");
    for (int i = 0; i < size; i++)
    {
        printf(" ");
        for (int j = 0; j < imageCount[i]; j++)
        {
            if (i < size - 1)
                printf("(%i, %i), ", set[i], relationInput[i][j]);
            else
                printf("(%i, %i)", set[i], relationInput[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
    printf("Relation Matrix for Relation R:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%i ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

/**
 * Check if the Relation is Reflexive
 * => (a, a) in R for every a in Set
 */
bool Relation::isReflexive()
{
    for (int i = 0; i < size; i++)
        if (!matrix[i][i])
            return false;
    return true;
}

/**
 * Check if the Relation is Symmetric
 * => (a, b) in R -> (b, a) in R 
 *    for every a, b in Set
 */
bool Relation::isSymmetric()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] && !matrix[j][i])
                return false;
    return true;
}

/**
 * Check if the Relation is Anti-symmetric
 * => (a, b) in R && (b, a) in R <=> a == b 
 *    for every a, b in Set
 */
bool Relation::isAntiSymmetric()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] && matrix[j][i] && i != j)
                return false;
    return true;
}

/**
 * Check if the Relation is Transitive
 * => (a, b) in R && (b, c) in R -> (a, c) in R
 *    for every a, b, c in Set
 */
bool Relation::isTransitive()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                if (matrix[i][j] && matrix[j][k] && !matrix[i][k])
                    return false;
    return true;
}

/**
 * Driver Code
 */
int main()
{
    Relation r;
    r.display();
    printf("Relation R is %s reflexive\n",
           (r.isReflexive() ? "\b" : "not"));
    printf("Relation R is %s symmetric\n",
           (r.isSymmetric() ? "\b" : "not"));
    printf("Relation R is %s antisymmetric\n",
           (r.isAntiSymmetric() ? "\b" : "not"));
    printf("Relation R is %s transitive\n",
           (r.isTransitive() ? "\b" : "not"));
    return 0;
}