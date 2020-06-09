#define MAX_DIM 1000

class DisjointSet
{
protected:
  int parent[MAX_DIM] = {0};
  int rank[MAX_DIM] = {0};

public:
  void makeSet(int index)
  {
    parent[index] = index;
    rank[index] = 0;
  }

  int find(int index)
  {
    if (index != parent[index])
      parent[index] = find(parent[index]);
    return parent[index];
  }

  void Union(int index1, int index2)
  {
    int index1_id = find(index1);
    int index2_id = find(index2);
    if (index1_id == index2_id)
      return;
    if (rank[index1_id] > rank[index2_id])
      parent[index2_id] = index1_id;
    else
    {
      parent[index1_id] = index2_id;
      if (rank[index1_id] == rank[index2_id])
        rank[index2_id]++;
    }
  }
};
