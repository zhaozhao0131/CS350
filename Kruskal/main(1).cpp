//
//  main.cpp
//  kruskal Algorithem



#include<iostream>
#include <vector>
#include<string>
#include<map>
#include<fstream>
using namespace std;
map<int, string> mapint2string;
map<string,int> mapstring2int;
// Creating shortcut for an integer pair
typedef  pair<int, int> iPair;

// Structure to represent a graph
struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;
    
    // Constructor
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    
    // Utility function to add an edge
    void addEdge(int u, int v, int w)
    {
        edges.push_back(make_pair(w,make_pair(u,v)));
    }
    
    // Function to find MST using Kruskal's
    // MST algorithm
    int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets
{
    int *parent, *rnk;
    int n;
    
    // Constructor.
    DisjointSets(int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        
        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            
            //every element is parent of itself
            parent[i] = i;
        }
    }
    
    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
         from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    
    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        
        /* Make tree with smaller height
         a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;
        
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

/* Functions returns weight of the MST*/

int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result
    
    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());
    
    // Create disjoint sets
    DisjointSets ds(V);
    
    // Iterate through all sorted edges
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        
        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            map<int, string>::iterator iteru;
            map<int, string>::iterator iterv;
            
            cout << mapint2string.find(u)->second << " - " << mapint2string.find(v)->second << endl;
            
            // Update MST weight
            mst_wt += it->first;
            
            // Merge two sets
            ds.merge(set_u, set_v);
        } 
    } 
    
    return mst_wt; 
} 


// Driver program to test above functions
int main()
{
    /* Let us create above shown weighted
     and unidrected graph */

    int V = 9, E = 14;
    Graph g(V, E);
    ifstream in("city-pairs.txt");
    if(!in.is_open()){
        cout<<"Error opening file";
    }
    string v, w;
    int weight;

    int verticeNum=0;
    while (!in.eof())            // 若未到文件结束一直循环
    {
        in >> v >> w >> weight;
//        cout<< v <<" "<< w << " "<<weight<<endl;
        map<string, int>::iterator iterv, iterw;
        iterv = mapstring2int.find(v);
        iterw = mapstring2int.find(w);
        int vIndex=0, wIndex=  0;
        if(iterv==mapstring2int.end()){
            vIndex = verticeNum;
            mapstring2int.insert(pair<string, int>(v, verticeNum++));
            mapint2string.insert(pair<int,string>(verticeNum-1, v));
        } else {
            vIndex = iterv->second;
        }
        if(iterw==mapstring2int.end()){
            wIndex = verticeNum;
            mapstring2int.insert(pair<string, int>(w, verticeNum++));
            mapint2string.insert(pair<int,string>(verticeNum-1, w));
        } else {
            wIndex = iterw->second;
        }
        g.addEdge(vIndex, wIndex, weight);
    }
//    map<string, int>::iterator iter;
//    iter = mapstring2int.begin();
//    while(iter != mapstring2int.end()) {
//        cout << iter->first << " : " << iter->second << endl;
//        iter++;
//    }
//    
//    map<int, string>::iterator iter2;
//    iter2 = mapint2string.begin();
//    while(iter2 != mapint2string.end()) {
//        cout << iter2->first << " : " << iter2->second << endl;
//        iter2++;
//    }
    
    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();
    
    cout << "\nWeight of MST is " << mst_wt<<endl;
    
    return 0; 
}
