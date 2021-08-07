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
    int images[MAX_DIM][MAX_DIM];

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
    if (size != 0)
    {
        printf("Enter Elements of Set: ");
        for (int i = 0; i < size; i++)
            scanf("%i", &set[i]);
    }
}

/**
 * Print the Set
 */
void Relation::putSet()
{
    printf("Set: { ");
    if (size != 0)
    {
        for (int i = 0; i < size; i++)
            printf("%i, ", set[i]);
        printf("\b\b }\n");
    }
    else
    {
        printf("}\n");
    }
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
 * Accept images for each preimage in the Set
 */
void Relation::getRelation()
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter number of images for Set Element %i: ", set[i]);
        scanf("%i", &imageCount[i]);
        if (imageCount[i] != 0)
        {
            printf("Enter images of Set Element %i: ", set[i]);
            for (int j = 0; j < imageCount[i]; j++)
            {
                scanf("%i", &images[i][j]);
                if (indexOf(images[i][j]) == -1)
                {
                    printf("Error: Image not in Set\n");
                    i--;
                    break;
                }
                else
                {
                    matrix[i][indexOf(images[i][j])] = 1;
                }
            }
        }
    }
    printf("\n");
}

/**
 * Print the Relation as a set of ordered pairs and relation matrix
 */
void Relation::putRelation()
{
    printf("Relation R:\n{ ");
    if (size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (imageCount[i] != 0)
                printf("\n ");
            {
                for (int j = 0; j < imageCount[i]; j++)
                {
                    if (i == size - 1 && j == imageCount[i] - 1)
                        printf("(%i, %i)\n", set[i], images[i][j]);
                    else
                        printf("(%i, %i), ", set[i], images[i][j]);
                }
            }
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
    else
    {
        printf("}\n\n");
    }
}

/**
 * Check if the Relation is Reflexive
 * => (a, a) in R for every a in Set
 */
bool Relation::isReflexive()
{
    if (size == 0)
        return false;
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