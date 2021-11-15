# __REPRESENTATION:__
- __V vertices__ 
- __E edges__ 
## Adjacency Matrix:
- Space Required             -- __O(V*V)__
- Check u and v are adjacent -- __Complexity:O(1)__
- All vertices adjacent to u -- __Complexity:O(V)__
- Find Degree of u           -- __Complexity:O(V)__
- Add or remove edge         -- __Complexity:O(1)__
- Add or remove veritces     -- __Complexity:O(V)__
## Adjacency List
- Space Required             -- __O(V+2*E)__
- Check u and v are adjacent -- __Complexity:O(V)__
- All vertices adjacent to u -- __Complexity:O(degreeOf(u))__
- Find Degree of u           -- __Complexity:O(1)__
- Add or remove edge         -- __Complexity:O(1)__
- Add or remove veritces     -- __Complexity:O(V)__
# __TRAVERSAL:__
## Breadth First Search (BFS)
- Time Complexity            -- __O(V+E)__
- Goes Level By Level
- Can be used To find Shortest Path in Undirected Graph
- Cycle Detection in Graph
- Count Connected Components in Graph
- Topolocgical Sort (Kahn's Algorithm)
## Depth First Search (DFS)
- Time Complexity            -- __O(V+E)__
- Goes Like Preorder Traversal i.e. We go to some node print it and then recurrsively visit all Adjacent of it
- Cycle Detection in Graph Both Directed And Undirected
- Count Connected Components in Graph
- Strongly Connected Components (Kosaraju's Algortihm)
- Topological Sort

# __DIRECTED ACYCLIC GRAPH:__
## TOPOLOGICAL SORT
-----------------------
- Helps find out order of Verties Which Follows Certain Dependencies But Does not Have Cycles.
### Using BFS
- First We need To make List of All vertices indegree
- Push All Vertices With Zero Indegree in Queue
- While Queue is not Empty Take all the Adjacent of that Vertex And decrease There Indegree By one if it has Become 0
We can Push that Vertex to Queue

### Using DFS
- We do Usual DFS Traversal 
- But After We have Called For All the Adjacent Of a Vertex We Push Current Vertex to Stack
- And After We Have Finished All the Vertex We Pop All the Elements Of stack
- It works Because We Always Push Depedencies Of A vertex in stack First And when We Pop it gets Reverse.

# __DETECT CYCLE:__
#### By Using DFS 
- Just Check if Current Node Adjacent is Already in the __VISITED ARRAY__ and is Not parent of Current Node.
---------------------------------
#### By Using DFS 
- Just Check if Current Node Adjacent is Already in __RECURSION STACK__. Check for Back edge if there is Back edge means there is a Cycle.
#### By Using Kahn's Algorithm (Topological Sort Using BFS)
- First We need To make List of All vertices indegree
- Push All Vertices With Zero Degree in Queue
- While Queue is not Empty We pop An Vertex
- Take all the Adjacent of that Vertex And decrease There Indegree By one if it has Become 0 We can Push that Vertex to Queue
- while We are Popping An Element We increment A count variable 
- At last We Check If count==V if not then There is Cycle 
- As this Signify Some Group Of vertex can Never Have 0 dependecies
- As they Are in Cycle So All are depedent on Each other

# __SHORTEST PATH SINGLE SOURCE:__
### For Undirected Unweighted Graph
- __COMPLEXITY: O(V+E)__
- Using BFS ( We can just Go level wise and keep the record of distance of newly Visited Node)- Complexity:O(V+E);
### USING TOPOLOGICAL SORT (VALID FOR <u>__DAG__</u> ONLY)
- __COMPLEXITY: O(V+E)__
- Intialize Vertex Distances As INF for Every Vertex Except Obv Source INTIALIZE dist[v]={INF,INF,INF,0,INF,INF,INF,INF}
- Find Topological Sort Of The Graph
- Move in Topological Order And relax All Adjacent Of Current vertex in That Order.
### <u>Dijkstra's Algorithm</u>
- __Not Work For Negative Weight Edges__
- __Directed Or Undirected__
- __Cyclic Or Acyclic__
- It is Similar To Prim's Algorithm
- if I add Some Constant To All Edges My shortest Path Changes As No of edges For shortest Path Will be Different.
- if I Multiply Some Constant To All Edges My shortest Path Does Not Changes.
### Implementation 
- __COMPLEXITY: O(V*V)__
- We make a Distance set Which is Initialised as INF for all Vertex
- What this Dist Array Represent is We relax All the Vertex Which are Adjacent To Vertex Which Are not already Been Selected.
- We set dist[s]=0,Where s is Source.
- So We Run an Outer Loop Which Runs for V times Each Time We Select Shortest Dist And relax All adjacent of this.
- Then We Select The Vertex Which is Not selected Currently And Has Min dist value.
- We add it To Selected Vertex and Relax All non Visted Adjacent Of its.
- Done.
### Improvements
- __COMPLEXITY: O((V+E)*(Log(V)))__
- What we Do is Generate a priority Queue Which Hold Distance of all vertex
- We pick the minimum of them and Relax All adjacent of it by Adjacent Matrix.
### <u>Bell Man Ford Algorithm</u>
- __COMPLEXITY: O(V*E)__
- __Work For Negative Weight Edges__
- __Not Work For Negative Weight Cycles But Can Detect Them__
- __Direceted Or Undirected__
- __Cyclic Or Acyclic__
- It is A DP Way We Build On Previous State
- What We Do is At Every Stage We find Shortest Path of i th or Less Edge 
- Max Edge Simple Path Will be V-1 So we Go upto V-1
### Implementation
- It is Simple We Just Relax Every Edge And Repeat it For (V-1) times

# __SPANNING TREE:__
- A graph With Every Vertex reachable by every other Vertex And Has minimum Edges __(i.e V-1)__

# __MINIMUM SPANNING TREE:__
- Defined For __WEIGHTED CONNECTED__ And __UNDIRECTED GRAPH__.
## USING PRIM'S ALGORITHM
----------------------------
- So we Maintain Two Set One Which We have Already Included in Our Minimum Spanning Tree And All left Vertices
- Now What we do is We Find The min Edge Joining Any Set1 Vertex To vertex of Set 2 Until Set2 Is Empty
### Implementation 
- __COMPLEXITY: O(V*V)__
- Firstly We make a mSet[V]={false,false,false,false,false,false} 
- We make a Key set Which is Initialised as INF for all Vertex
- What this Key Array Represent is We relax All the Vertex Which are Adjacent To Vertex Which Are already in adjacent Set
- So We Run an Outer Loop Which Runs for V times Each Time We add a Vertex To mSet (Selected Set).
- We set Key[0]=0,We can give this To any Vertex This is the First Vertex That is Selected.
- Then We Select The Vertex Which is Not in Mset Currently And Has Min Key value.
- We add it To Mset and Relax All non Mset Adjacent Of its.
- Done.
### Improvements:
- __COMPLEXITY: O((V+E)*(Log(V)))__
- So We can Find minimum Key using Heap Data srtucture in Log(V) time 
- Also We can Use Adjacency Matrix which Will Take in all (V+E) time as We have to relax All Adjacent Which is Like decrease key Operation Will take log(V) time 
- So Net Complexity is Vlog(V)+(V+E)log(V)
## USING KRUSKAL'S ALGORITHM
----------------------------

# __Strongly Connected Components__
- __Valid For directed Graph (IMPORTANT)__
- Defined as group of vertices Which Can be reachable from one another i.e in this Group there is a path from u to v if u,v belong to this group 
### <u>Kosaraju's Algorithm </u>
- __Based On DFS Traversal__
- __Complexity O(V+E) Same as DFS(Only That it Does 2 Times DFS and 1 times Edge reversal)__
- Store the order of Vertices On Decreasing Order of Finish Time on DFS Traversal
- Above Step is Done As Topological Sort By DFS only Difference Here We can Have Cycles.
- Reverse All Edges 
- Do A DFS traversal Of graph With Reversed Edges And Just look For connected Components
### <u> Tarjan's Algorithm </u>
- __Based On DFS Traversal Along With Low Value And Discovery Time Concept__
- __Complexity O(V+E) Same as DFS(Better Than Kosaraju's Algo As only one DFS traversal)__
- __As this is For Dircted Graph So unlike Articulation And Bridge It Will Have Both Cross Edge And Back Edge Keep in mind__
- We Do DFS Traversal Maintain Discovery Time And Low Value
- __Whenever All the Adjacent Child Of A node are Done We Compare low Value and Discovery Time If They are Equal We remove All node until Current Node.__
- We do not Consider Cross Edge in Low Value Calculation But While Looking For Backedge Relaxtion For Vertices We should Check that We are relaxing it for Ancestor (Back Edge) i.e we have to look that this adjacent is Ancestor By Checking it is Present in Stack or Not 
- [GFG Code For better Understanding](https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components)
- [CP Algorithm Code For better Understanding](https://cp-algorithms.com/graph/strongly-connected-components.html)

# __ARTICULATION POINTS__
- __Undirected And Connected Graph__
- Articulation Points Are those Vertices Removal Of Which and Their Associated Edges Increase No of Connected Components By 1 or more.
### <u>Method To find Articulation Points </u>
- __Complexity O(V+E) Same as DFS(Only Does 1 DFS Traversal)__
- We First Do a DFS Traversal And Make A Tree out of it
- We Assign 2 variables TO every Vertices 
- 1st Discovery Time : Which is Just The Order in Which DFS took Place
- 2nd Low Value      : Which is That for Every Vertex The min Discovery Time Vertex it Can reach By back Edge or Normal Edge
- __For Root Node it is Simple if it has two or More than 2 child than it is Articulation Point.__
- __For any Non-Root Node it is to check if any of its Child has Higher or Equal Low Value than its Discovery Time (i.e. if v is child of u than if lowValue[v] >= DiscoveryTime[u] than 'u' is a Articulation Point) Then its is Articulation Point.__ 
- Both rules Are easy To digest As if root has more than two child this means There is No connection Between Any Node of 1st subtree to Node of 2nd Subtree.
- 2nd rule Just state That if The child Of this Node Does Not Has Back edge Than it is Pretty Clear that Removing This Node Will remove Child From Graph.
- [GFG Code For better Understanding](https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/)
- [CP Algorithm Code For better Understanding](https://cp-algorithms.com/graph/cutpoints.html)

# __BRIDGES IN GRAPH__
- __Undirected And Connected Graph__
### <u>Method To find Bridges</u>
- __Complexity O(V+E) Same as DFS(Only Does 1 DFS Traversal)__
- Bridge is A Edge Removing which Causes Increase in Connected Components by 1 or More Than 1.
- Everthing is Same As Articulation Point
- Let's say we are in the DFS, looking through the edges starting from vertex u. The current edge (u,v) is a bridge if and only if none of the vertices v and its descendants in the DFS traversal tree has a back-edge to vertex u or any of its ancestors. Indeed, this condition means that there is no other way from u to v except for edge (u,v).
- Just That We have No Exceptional Condition For Root And condition for an edge (u, v) to be a bridge is, 
- low[v] > disc[u]
- [GFG Code For better Understanding](https://www.geeksforgeeks.org/bridge-in-a-graph/)
- [CP Algorithm Code For better Understanding](https://cp-algorithms.com/graph/bridge-searching.html)
