# <u>__REPRESENTATION:__</u>
- __V,n vertices__ 
- __E,m edges__ 

## <u>Adjacency Matrix:</u>
- Space Required             -- __O(V*V)__
- Check u and v are adjacent -- __Complexity:O(1)__
- All vertices adjacent to u -- __Complexity:O(V)__
- Find Degree of u           -- __Complexity:O(V)__
- Add or remove edge         -- __Complexity:O(1)__
- Add or remove vertices     -- __Complexity:O(V)__

## <u>Adjacency List</u>
- Space Required             -- __O(V+2*E)__
- Check u and v are adjacent -- __Complexity:O(V)__
- All vertices adjacent to u -- __Complexity:O(degreeOf(u))__
- Find Degree of u           -- __Complexity:O(1)__
- Add or remove edge         -- __Complexity:O(1)__
- Add or remove vertices     -- __Complexity:O(V)__

# <u>__TRAVERSAL:__</u>
## <u>Breadth First Search (BFS)</u>
- Time Complexity            -- __O(V+E)__
- Goes Level By Level
- Can be used To find Shortest Path in Undirected Graph
- Cycle Detection in Graph
- Count Connected Components in Graph
- Topological Sort (Kahn's Algorithm)
- __Find all the edges that lie on any shortest path between a given pair of vertices (a,b)__. To do this, run two breadth first searches: one from a and one from b. Let da[] be the array containing shortest distances obtained from the first BFS (from a) and db[] be the array containing shortest distances obtained from the second BFS from b. Now for every edge (u,v) it is easy to check whether that edge lies on any shortest path between a and b: the criterion is the condition da[u]+1+db[v]=da[b].

- __Find all the vertices on any shortest path between a given pair of vertices (a,b).__ To accomplish that, run two breadth first searches: one from a and one from b. Let da[] be the array containing shortest distances obtained from the first BFS (from a) and db[] be the array containing shortest distances obtained from the second BFS (from b). Now for each vertex it is easy to check whether it lies on any shortest path between a and b: the criterion is the condition __da[v]+db[v]=da[b]__.

- __Find the shortest path of even length from a source vertex s to a target vertex t in an unweighted graph: For this, we must construct an auxiliary graph, whose vertices are the state (v,c), where v - the current node, c=0 or c=1 - the current parity. Any edge (a,b) of the original graph in this new column will turn into two edges ((u,0),(v,1)) and ((u,1),(v,0)). After that we run a BFS to find the shortest path from the starting vertex (s,0) to the end vertex (t,0).__

## <u>Depth First Search (DFS)</u>
- Time Complexity            -- __O(V+E)__
- Goes Like Pre-order Traversal i.e. We go to some node print it and then recursively visit all Adjacent of it
- Cycle Detection in Graph Both Directed And Undirected
- Count Connected Components in Graph
- Strongly Connected Components (Kosaraju's Algorithm)
- Topological Sort
- Depth First Search will also find the shortest paths in a __<u>tree</u>__ (because there only exists one simple path), but on general graphs this is not the case.
- Check if a vertex in a tree is an ancestor of some other vertex:
- At the beginning and end of each search call we remember the entry and exit "time" of each vertex. Now you can find the answer for any pair of vertices (i,j) in O(1): vertex i is an ancestor of vertex j if and only if entry[i]<entry[j] and exit[i]>exit[j].
- Find strongly connected components in a directed graph:
    * First do a topological sorting of the graph. Then transpose the graph and run another series of depth first searches in the order defined by the topological sort. For each DFS call the component created by it is a strongly connected component.
- Check if a vertex in a tree is an ancestor of some other vertex:
    * At the beginning and end of each search call we remember the entry and exit "time" of each vertex. Now you can find the answer for any pair of vertices (i,j) in O(1): vertex i is an ancestor of vertex j if and only if entry[i]<entry[j] and exit[i]>exit[j].
- __(NOT DONE IT YET)__ Find The LCA of Two Vertices.

# __<u>Classification of edges of a graph</u>__

-We can classify the edges using the entry and exit time of the end nodes u and v of the edges (u,v). These classifications are often used for problems like finding bridges and finding articulation points.

- We perform a DFS and classify the encountered edges using the following rules:
* __If v is not visited:__

    * <u>Tree Edge</u> - If v is visited after u then edge (u,v) is called a tree edge. In other words, if v is visited for the first time and u is currently being visited then (u,v) is called tree edge. These edges form a DFS tree and hence the name tree edges.

* __If v is visited before u:__

    * <u>Back edges</u> : If v is an ancestor of u, then the edge (u,v) is a back edge. v is an ancestor exactly if we already entered v, but not exited it yet. Back edges complete a cycle as there is a path from ancestor v to descendant u (in the recursion of DFS) and an edge from descendant u to ancestor v (back edge), thus a cycle is formed. Cycles can be detected using back edges.

    * <u>Forward Edges</u> :If v is a descendant of u, then edge (u,v) is a forward edge. In other words, if we already visited and exited v and entry[u]<entry[v] then the edge (u,v) forms a forward edge.

    * <u>Cross Edges</u>: if v is neither an ancestor or descendant of u, then edge (u,v) is a cross edge. In other words, if we already visited and exited v and entry[u]> entry[v] then (u,v) is a cross edge.
### __Note: Forward edges and cross edges only exist in directed graphs.__
# <u>__DIRECTED ACYCLIC GRAPH:__</u>
## <u>TOPOLOGICAL SORT</u>
- Helps find out order of Vertices Which Follows Certain Dependencies But Does not Have Cycles.
### <u>Using BFS</u>
- First We need To make List of All vertices in-degree
- Push All Vertices With Zero In-degree in Queue
- While Queue is not Empty Take all the Adjacent of that Vertex And decrease There In-degree By one if it has Become 0
We can Push that Vertex to Queue

### <u>Using DFS</u>
- We do Usual DFS Traversal 
- But After We have Called For All the Adjacent Of a Vertex We Push Current Vertex to Stack
- And After We Have Finished All the Vertex We Pop All the Elements Of stack
- It works Because We Always Push Dependencies Of A vertex in stack First And when We Pop it gets Reverse.


# <u>__DETECT CYCLE:__</u>
#### <u>By Using DFS </u>
- Just Check if Current Node Adjacent is Already in the __VISITED ARRAY__ and is Not parent of Current Node.
#### <u>By Using DFS </u>
- Just Check if Current Node Adjacent is Already in __RECURSION STACK__. Check for Back edge if there is Back edge means there is a Cycle.
#### <u>By Using Kahn's Algorithm (Topological Sort Using BFS)</u>
- First We need To make List of All vertices in-degree
- Push All Vertices With Zero Degree in Queue
- While Queue is not Empty We pop An Vertex
- Take all the Adjacent of that Vertex And decrease There In-degree By one if it has Become 0 We can Push that Vertex to Queue
- while We are Popping An Element We increment A count variable 
- At last We Check If count==V if not then There is Cycle 
- As this Signify Some Group Of vertex can Never Have 0 dependencies
- As they Are in Cycle So All are dependent on Each other

# <u>__SHORTEST PATH SINGLE SOURCE:__</u>
### <u>For Undirected Unweighted Graph</u>
- __COMPLEXITY: O(V+E)__
- Using BFS ( We can just Go level wise and keep the record of distance of newly Visited Node)- Complexity:O(V+E);
### <u>USING TOPOLOGICAL SORT (VALID FOR <u>__DAG__</u> ONLY)</u>
- __COMPLEXITY: O(V+E)__
- Initialize Vertex Distances As INF for Every Vertex Except Obv Source INITIALIZE dist[v]={INF,INF,INF,0,INF,INF,INF,INF}
- Find Topological Sort Of The Graph
- Move in Topological Order And relax All Adjacent Of Current vertex in That Order.
### <u>Dijkstra's Algorithm</u>
- __Not Work For Negative Weight Edges__
- __Directed Or Undirected__
- __Cyclic Or Acyclic__


### <u>Algorithm</u>
- Let's create an array d[] where for each vertex v we store the current length of the shortest path from s to v in d[v]. Initially d[s]=0, and for all other vertices this length equals infinity. In the implementation a sufficiently large number (which is guaranteed to be greater than any possible path length) is chosen as infinity. (d[v]=∞, v≠s)
- In addition, we maintain a Boolean array u[] which stores for each vertex v whether it's marked. Initially all vertices are unmarked: (u[v]=false).
- The Dijkstra's algorithm runs for n iterations. At each iteration a vertex v is chosen as unmarked vertex which has the least value d[v]:

- Evidently, in the first iteration the starting vertex s will be selected.

- The selected vertex v is marked. Next, from vertex v relaxations are performed: all edges of the form (v,to) are considered, and for each vertex to the algorithm tries to improve the value d[to]. If the length of the current edge equals len, the code for relaxation is:
    * d[to]=min(d[to],d[v]+len)
- After all such edges are considered, the current iteration ends. Finally, after n iterations, all vertices will be marked, and the algorithm terminates. We claim that the found values d[v] are the lengths of shortest paths from s to all vertices v.

- Note that if some vertices are unreachable from the starting vertex s, the values d[v] for them will remain infinite. 

- Obviously, the last few iterations of the algorithm will choose those vertices, but no useful work will be done for them.Therefore, the algorithm can be stopped as soon as the selected vertex has infinite distance to it.

### <u>Restoring Shortest Paths</u>
- Usually one needs to know not only the lengths of shortest paths but also the shortest paths themselves. Let's see how to maintain sufficient information to restore the shortest path from s to any vertex. 
- We'll maintain an array of predecessors p[] in which for each vertex v≠s p[v] is the penultimate vertex in the shortest path from s to v. Here we use the fact that if we take the shortest path to some vertex v and remove v from this path, we'll get a path ending in at vertex p[v], and this path will be the shortest for the vertex p[v]. 
- This array of predecessors can be used to restore the shortest path to any vertex: starting with v, repeatedly take the predecessor of the current vertex until we reach the starting vertex s to get the required shortest path with vertices listed in reverse order. So, the shortest path P to the vertex v is equal to:
    * P=(s,…,p[p[p[v]]],p[p[v]],p[v],v)
- Building this array of predecessors is very simple: for each successful relaxation, i.e. when for some selected vertex v, there is an improvement in the distance to some vertex to, we update the predecessor vertex for to with vertex v:
    * p[to]=v
### <u>Summary</u>
- It is Similar To Prim's Algorithm
- if I add Some Constant To All Edges My shortest Path Changes As No of edges For shortest Path Will be Different.
- if I Multiply Some Constant To All Edges My shortest Path Does Not Changes.
#### <u>Implementation</u>
- __COMPLEXITY: O(V*V)__
- We make a Distance set Which is Initialized as INF for all Vertex
- What this Dist Array Represent is We relax All the Vertex Which are Adjacent To Vertex Which Are not already Been Selected.
- We set dist[s]=0,Where s is Source.
- So We Run an Outer Loop Which Runs for V times Each Time We Select Shortest Dist And relax All adjacent of this.
- Then We Select The Vertex Which is Not selected Currently And Has Min dist value.
- We add it To Selected Vertex and Relax All non Visited Adjacent Of its.
- Done.

### <u>__Code__</u>
```C++
//Complexity:O(n2+m)
//For Dense Graph
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
```
    First of all, the code initializes arrays: distances d[], labels u[] and predecessors p[]. Then it performs n iterations.
    At each iteration the vertex v is selected which has the smallest distance d[v] among all the unmarked vertices. 
    If the distance to selected vertex v is equal to infinity, the algorithm stops. Otherwise the vertex is marked, 
    and all the edges going out from this vertex are checked. If relaxation along the edge is possible 
    (i.e. distance d[to] can be improved), the distance d[to] and predecessor p[to] are updated.

    After performing all the iterations array d[] stores the lengths of the shortest paths to all vertices, 
    and array p[] stores the predecessors of all vertices (except starting vertex s)

- __The path to any vertex t can be restored in the following way:__

### <u>__Code__</u>
```C++
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
```

#### <u>Improvements</u>
- __COMPLEXITY: O((V+E)*(Log(V)))__
### <u>Dijkstra on sparse graphs</u>
- In the simplest implementation these operations require O(n) and O(1) time. Therefore, since we perform the first operation O(n) times, and the second one O(m) times, we obtained the complexity O(n2+m).

- It is clear, that this complexity is optimal for a dense graph, i.e. when m≈n2. However in sparse graphs, when m is much smaller than the maximal number of edges n2, the complexity gets less optimal because of the first term. Thus it is necessary to improve the execution time of the first operation (and of course without greatly affecting the second operation by much).

- To accomplish that we can use a variation of multiple auxiliary data structures. The most efficient is the Fibonacci heap, which allows the first operation to run in O(logn), and the second operation in O(1). Therefore we will get the complexity O(nlogn+m) for Dijkstra's algorithm, which is also the theoretical minimum for the shortest path search problem. Therefore this algorithm works optimal, and Fibonacci heaps are the optimal data structure. There doesn't exist any data structure, that can perform both operations in O(1), because this would also allow to sort a list of random numbers in linear time, which is impossible. Interestingly there exists an algorithm by Thorup that finds the shortest path in O(m) time, however only works for integer weights, and uses a completely different idea. So this doesn't lead to any contradictions. Fibonacci heaps provide the optimal complexity for this task. However they are quite complex to implement, and also have a quite large hidden constant.

- As a compromise you can use data structures, that perform both types of operations (extracting a minimum and updating an item) in O(logn). Then the complexity of Dijkstra's algorithm is O(nlogn+mlogn)=O(mlogn).

- C++ provides two such data structures: set and priority_queue. The first is based on red-black trees, and the second one on heaps. __Therefore priority_queue has a smaller hidden constant, but also has a drawback: it doesn't support the <u>operation of removing an element.</u>__ Because of this we need to do a "workaround", that actually leads to a slightly worse factor logm instead of logn (although in terms of complexity they are identical).

## <u>Implementation</u>
### <u>Set</u>
### <u>__Code__</u>
```C++
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
```
    We don't need the array u[] from the normal Dijkstra's algorithm implementation any more. We will use the set to store that information, and also find the vertex with the shortest distance with it. It kinda acts like a queue. The main loops executes until there are no more vertices in the set/queue. A vertex with the smallest distance gets extracted, and for each successful relaxation we first remove the old pair, and then after the relaxation add the new pair into the queue.


### <u>Priority Queue</u>
- The main difference to the implementation with set is that we cannot remove elements from the priority_queue (although heaps can support that operation in theory). Therefore we have to cheat a little bit. We simply don't delete the old pair from the queue. As a result a vertex can appear multiple times with different distance in the queue at the same time. Among these pairs we are only interested in the pairs where the first element is equal to the corresponding value in d[], all the other pairs are old. Therefore we need to make a small modification: at the beginning of each iteration, after extracting the next pair, we check if it is an important pair or if it is already an old and handled pair. This check is important, otherwise the complexity can increase up to O(nm).

### <u>__Code__</u>
```C++
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
```
### <u>Summary</u>
- What we Do is Generate a priority Queue Which Hold Distance of all vertex
- We pick the minimum of them and Relax All adjacent of it by Adjacent Matrix.

### <u>Bell Man Ford Algorithm</u>
- __COMPLEXITY: O(V*E)__
- __Work For Negative Weight Edges__
- __Not Work For Negative Weight Cycles But Can Detect Them__
- __Directed Or Undirected__
- __Cyclic Or Acyclic__
- It is A DP Way We Build On Previous State
- What We Do is At Every Stage We find Shortest Path of i th or Less Edge 
- Max Edge Simple Path Will be V-1 So we Go up to V-1
### <u>Implementation</u>
- It is Simple We Just Relax Every Edge And Repeat it For (V-1) times

# <u>__SPANNING TREE:__</u>
- A graph With Every Vertex reachable by every other Vertex And Has minimum Edges __(i.e V-1)__

# <u>__MINIMUM SPANNING TREE:__</u>
- Defined For __WEIGHTED CONNECTED__ And __UNDIRECTED GRAPH__.
## <u>USING PRIM'S ALGORITHM</u>

- So we Maintain Two Set One Which We have Already Included in Our Minimum Spanning Tree And All left Vertices
- Now What we do is We Find The min Edge Joining Any Set1 Vertex To vertex of Set 2 Until Set2 Is Empty
### Poor Implementation
- Trivial implementations: O(nm) and O(n<sup>2</sup>+m*log(n))
    * If we search the edge by iterating over all possible edges, then it takes O(m) time to find the edge with the minimal weight. The total complexity will be O(nm). In the worst case this is O(n3), really slow.
- This algorithm can be improved if we only look at one edge from each already selected vertex. For example we can sort the edges from each vertex in ascending order of their weights, and store a pointer to the first valid edge (i.e. an edge that goes to an non-selected vertex). Then after finding and selecting the minimal edge, we update the pointers. This give a complexity of O(n<sup>2</sup>+m), and for sorting the edges an additional O(m*log(n)), which gives the complexity O(n<sup>2</sup>log(n)) in the worst case.

#### <u>Implementation</u>
- __COMPLEXITY: O(V*V)__
- Firstly We make a mSet[V]={false,false,false,false,false,false} 
- We make a Key set Which is Initialized as INF for all Vertex
- What this Key Array Represent is We relax All the Vertex Which are Adjacent To Vertex Which Are already in adjacent Set
- So We Run an Outer Loop Which Runs for V times Each Time We add a Vertex To mSet (Selected Set).
- We set Key[0]=0,We can give this To any Vertex This is the First Vertex That is Selected.
- Then We Select The Vertex Which is Not in M-set Currently And Has Min Key value.
- We add it To M-set and Relax All non M-set Adjacent Of its.
- Done.


#### <u>__DENSE GRAPH__</u>
- __COMPLEXITY: O(V*V)__

- We approach this problem for a different side: for every not yet selected vertex we will store the minimum edge to an already selected vertex.

- Then during a step we only have to look at these minimum weight edges, which will have a complexity of O(n).

- After adding an edge some minimum edge pointers have to be recalculated. Note that the weights only can decrease, i.e. the minimal weight edge of every not yet selected vertex might stay the same, or it will be updated by an edge to the newly selected vertex. Therefore this phase can also be done in O(n).

- Thus we received a version of Prim's algorithm with the complexity O(n2).

- __In particular this implementation is very convenient for the Euclidean Minimum Spanning Tree problem: we have n points on a plane and the distance between each pair of points is the Euclidean distance between them, and we want to find a minimum spanning tree for this complete graph. This task can be solved by the described algorithm in O(n2) time and O(n) memory, which is not possible with Kruskal's algorithm__.

### <u>__Code__</u>
```C++
// Dense Graph Prims Algorithm Implementation
int n;
vector<vector<int>> adj; // adjacency matrix of graph
const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << endl;
}
```
    The adjacency matrix adj[][] of size n×n stores the weights of the edges, and it uses the weight INF if there doesn't exist an edge between two vertices. 
    The algorithm uses two arrays: the flag selected[], which indicates which vertices we already have selected,and the array min_e[] 
    which stores the edge with minimal weight to an selected vertex for each not-yet-selected vertex (it stores the weight and the end vertex). 
    The algorithm does n steps, in each iteration the vertex with the smallest edge weight is selected, and the min_e[] of all other vertices gets updated.

### <u>Improvements:</u>

- __COMPLEXITY: O((V+E)*(Log(V)))__
- So We can Find minimum Key using Heap Data structure in Log(V) time 
- Also We can Use Adjacency Matrix which Will Take in all (V+E) time as We have to relax All Adjacent Which is Like decrease key Operation Will take log(V) time 
- So Net Complexity is V*log(V)+(V+E)log(V)

#### <u>Sparse graphs</u>
- __COMPLEXITY: O((n+m)*(Log(n)))__
- In the above described algorithm it is possible to interpret the operations of finding the minimum and modifying some values as set operations. These two classical operations are supported by many data structure, for example by set in C++ (which are implemented via red-black trees).

- The main algorithm remains the same, but now we can find the minimum edge in O(Log(n)) time. On the other hand recomputing the pointers will now take O(n*Log(n)) time, which is worse than in the previous algorithm.

- But when we consider that we only need to update O(m) times in total, and perform O(n) searches for the minimal edge, then the total complexity will be O(m*Log(n)). For sparse graphs this is better than the above algorithm, but for dense graphs this will be slower.

### <u>__Code__</u>
```C++
const int INF = 1000000000;

struct Edge {
    int w = INF, to = -1;
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

int n;
vector<vector<Edge>> adj;

void prim() {
    int total_weight = 0;
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    set<Edge> q;
    q.insert({0, 0});
    vector<bool> selected(n, false);
    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            cout << "No MST!" << endl;
            exit(0);
        }

        int v = q.begin()->to;
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (Edge e : adj[v]) {
            if (!selected[e.to] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }
    }

    cout << total_weight << endl;
}
```
    Here the graph is represented via a adjacency list adj[], where adj[v] contains all edges (in form of weight and target pairs) for the vertex v. 
    min_e[v] will store the weight of the smallest edge from vertex v to an already selected vertex (again in the form of a weight and target pair). 
    In addition the queue q is filled with all not yet selected vertices in the order of increasing weights min_e. The algorithm does n steps, 
    on each of which it selects the vertex v with the smallest weight min_e (by extracting it from the beginning of the queue
    , and then looks through all the edges from this vertex and updates the values in min_e (during an update we also
     need to also remove the old edge from the queue q and put in the new edge).

## <u>USING KRUSHKAL'S ALGORITHM</u>

# <u>__Strongly Connected Components__</u>
- __Valid For directed Graph (IMPORTANT)__
- Defined as group of vertices Which Can be reachable from one another i.e in this Group there is a path from u to v if u,v belong to this group 
- __It is obvious, that strongly connected components do not intersect each other, i.e. this is a partition of all graph vertices. Thus we can give a definition of condensation graph G<sup>SCC</sup> as a graph containing every strongly connected component as one vertex. Each vertex of the condensation graph corresponds to the strongly connected component of graph G. There is an oriented edge between two vertices Ci and Cj of the condensation graph if and only if there are two vertices u∈Ci,v∈Cj such that there is an edge in initial graph, i.e. (u,v)∈E.__
- __The most important property of the condensation graph is that it is <u>acyclic</u>. Indeed, suppose that there is an edge between C and C′, let's prove that there is no edge from C′ to C. Suppose that C′↦C. Then there are two vertices u′∈C and v′∈C′ such that v′↦u′. But since u and u′ are in the same strongly connected component then there is a path between them; the same for v and v′. As a result, if we join these paths we have that v↦u and at the same time u↦v. Therefore u and v should be at the same strongly connected component, so this is contradiction. This completes the proof.__


## <u>Kosaraju's Algorithm </u>
- __Based On DFS Traversal__
- __Complexity O(V+E) Same as DFS(Only That it Does 2 Times DFS and 1 times Edge reversal)__


### <u>Description of the algorithm</u>

- This is an easy-to-implement algorithm based on two series of depth first search, and working for O(n+m) time.
- On the first step of the algorithm we are doing sequence of depth first searches, visiting the entire graph. We start at each vertex of the graph and run a depth first search from every non-visited vertex. For each vertex we are keeping track of exit time tout[v]. These exit times have a key role in an algorithm and this role is expressed in next theorem.
- First, let's make notations: let's define exit time __tout[C] from the strongly connected component C as <u>maximum</u> of values tout[v] by all v∈C__. Besides, during the proof of the theorem we will mention entry times tin[v] in each vertex and in the same way consider __tin[C] for each strongly connected component C as <u>minimum</u> of values tin[v] by all v∈C.__

#### <u>Theorem</u>
- Let C and C′ are two different strongly connected components and there is an edge (C,C′) in a condensation graph between these two vertices. Then tout[C]>tout[C′].
- There are two main different cases at the proof depending on which component will be visited by depth first search first, i.e. depending on difference between tin[C] and tin[C′]:
    * The component C was reached first. It means that depth first search comes at some vertex v of component C at some moment, but all other vertices of components C and C′ were not visited yet. By condition there is an edge (C,C′) in a condensation graph, so not only the entire component C is reachable from v but the whole component C′ is reachable as well. It means that depth first search that is running from vertex v will visit all vertices of components C and C′, so they will be descendants for v in a depth first search tree, i.e. for each vertex u∈C∪C′,u≠v we have that tout[v]>tout[u], as we claimed.
    
    * Assume that component C′ was visited first. Similarly, depth first search comes at some vertex v of component C′ at some moment, but all other vertices of components C and C′ were not visited yet. But by condition there is an edge (C,C′) in the condensation graph, so, because of acyclic property of condensation graph, there is no back path from C′ to C, i.e. depth first search from vertex v will not reach vertices of C. It means that vertices of C will be visited by depth first search later, so tout[C]>tout[C′]. This completes the proof.

#### <u>Method</u> 

- The above Proved theorem is the base of algorithm for finding strongly connected components. It follows that any edge (C,C′) in condensation graph comes from a component with a larger value of tout to component with a smaller value.

- If we sort all vertices v∈V in decreasing order of their exit time tout[v] then the first vertex u is going to be a vertex belonging to "root" strongly connected component, i.e. a vertex that has no incoming edges in the condensation graph. Now we want to run such search from this vertex u so that it will visit all vertices in this strongly connected component, but not others; doing so, we can gradually select all strongly connected components: let's remove all vertices corresponding to the first selected component, and then let's find a vertex with the largest value of tout, and run this search from it, and so on.

- Let's consider transposed graph G<sup>T</sup>, i.e. graph received from G by reversing the direction of each edge. Obviously, this graph will have the same strongly connected components as the initial graph. Moreover, the condensation graph G<sup>SCC</sup> will also get transposed. It means that there will be no edges from our "root" component to other components.

- Thus, for visiting the whole "root" strongly connected component, containing vertex v, is enough to run search from vertex v in graph G<sup>T</sup>. This search will visit all vertices of this strongly connected component and only them. As was mentioned before, we can remove these vertices from the graph then, and find the next vertex with a maximal value of tout[v] and run search in transposed graph from it, and so on.

- Thus, we built next algorithm for selecting strongly connected components:
    1. Run sequence of depth first search of graph G which will return vertices with increasing exit time tout, i.e. some list order.
    2. Build transposed graph GT. Run a series of depth (breadth) first searches in the order determined by list order (to be exact in reverse order, i.e. in decreasing order of exit times). Every set of vertices, reached after the next search, will be the next strongly connected component.

##### <u>Short Summary</u>

- Store the order of Vertices On Decreasing Order of Finish Time on DFS Traversal.
- Above Step is Done As Topological Sort By DFS only Difference Here We can Have Cycles.
- Reverse All Edges.
- Do A DFS traversal Of graph With Reversed Edges And Just look For connected Components

### <u>__Code__</u>
```C++
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    int n;
    // ... read n ...

    for (;;) {
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);

            // ... processing next component ...

            component.clear();
        }
}
```
    Here, g is graph, gr is transposed graph. Function dfs1 implements depth first search on graph G, function dfs2 - on transposed graph GT. 
    Function dfs1 fills the list order with vertices in increasing order of their exit times (actually, it is making a topological sort). 
    Function dfs2 stores all reached vertices in list component, that is going to store next strongly connected component after each run.


### <u> Tarjan's Algorithm </u>
- __Based On DFS Traversal Along With Low Value And Discovery Time Concept__
- __Complexity O(V+E) Same as DFS(Better Than Kosaraju's Algo As only one DFS traversal)__
- __As this is For Directed Graph So unlike Articulation And Bridge It Will Have Both Cross Edge And Back Edge Keep in mind__
- We Do DFS Traversal Maintain Discovery Time And Low Value
- __Whenever All the Adjacent Child Of A node are Done We Compare low Value and Discovery Time If They are Equal We remove All node until Current Node.__
- We do not Consider Cross Edge in Low Value Calculation But While Looking For Back-edge Relaxation For Vertices We should Check that We are relaxing it for Ancestor (Back Edge) i.e we have to look that this adjacent is Ancestor By Checking it is Present in Stack or Not 
- [GFG Code For better Understanding](https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components)
- [CP Algorithm Code For better Understanding](https://cp-algorithms.com/graph/strongly-connected-components.html)

# <u>__ARTICULATION POINTS__</u>
- __Undirected And Connected Graph__
- Articulation Points Are those Vertices Removal Of Which and Their Associated Edges Increase No of Connected Components By 1 or more.
### <u>Method To find Articulation Points </u>
- __Complexity O(V+E) Same as DFS(Only Does 1 DFS Traversal)__
- We First Do a DFS Traversal And Make A Tree out of it
- We Assign 2 variables TO every Vertices 
- 1st Discovery Time : Which is Just The Order in Which DFS took Place
- 2nd Low Value      : Which is That for Every Vertex The min Discovery Time Vertex it Can reach By back Edge or Normal Edge
- __For Root Node it is Simple if it has two or More than 2 child than it is Articulation Point.__
- __For any Non-Root Node it is to check if <u>any</u> of its Child has Higher or Equal Low Value than its Discovery Time (i.e. if v is child of u than if lowValue[v] >= DiscoveryTime[u] than 'u' is a Articulation Point) Then its is Articulation Point.__ 
- Both rules Are easy To digest As if root has more than two child this means There is No connection Between Any Node of 1st subtree to Node of 2nd Subtree.
- 2nd rule Just state That if The child Of this Node Does Not Has Back edge Than it is Pretty Clear that Removing This Node Will remove Child From Graph.
- [GFG Code For better Understanding](https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/)
- [CP Algorithm Code For better Understanding](https://cp-algorithms.com/graph/cutpoints.html)

### <u>__Code__</u>
```C++
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
```
# <u>__BRIDGES IN GRAPH__</u>
- __Undirected And Connected Graph__
- Find bridges in an undirected graph:
- First convert the given graph into a directed graph by running a series of depth first searches and making each edge directed as we go through it, in the direction we went. Second, find the strongly connected components in this directed graph. Bridges are the edges whose ends belong to different strongly connected components.
### <u>Method To find Bridges</u>
- __Complexity O(V+E) Same as DFS(Only Does 1 DFS Traversal)__
- Bridge is A Edge Removing which Causes Increase in Connected Components by 1 or More Than 1.
- Everything is Same As Articulation Point
- Let's say we are in the DFS, looking through the edges starting from vertex u. The current edge (u,v) is a bridge if and only if none of the vertices v and its descendants in the DFS traversal tree has a back-edge to vertex u or any of its ancestors. Indeed, this condition means that there is no other way from u to v except for edge (u,v).
- Just That We have No Exceptional Condition For Root And condition for an edge (u, v) to be a bridge is, 
- low[v] > disc[u]
- [GFG Code For better Understanding](https://www.geeksforgeeks.org/bridge-in-a-graph/)
- [CP Algorithm Code For better Understanding](https://cp-algorithms.com/graph/bridge-searching.html)

##### The implementation needs to distinguish three cases: when we go down the edge in DFS tree, when we find a back edge to an ancestor of the vertex and when we return to a parent of the vertex. These are the cases:

- visited[to]=false - the edge is part of DFS tree;
- visited[to]=true && to≠parent - the edge is back edge to one of the ancestors;
- to=parent - the edge leads back to parent in DFS tree
### <u__Code__</u>
```C++
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

```
