#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ll long long
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pic pair<int,char>
#define psc pair<string,char>

// Define infinity as a very large value
const int INF = 1000000;

// Define a graph as a vector of vectors of edges
typedef map<string,map<psc,int>> Graph;

int dijkstra(Graph& graph, string start, string destination) {
    int n = graph.size();
    map<psc,int> dist;
    priority_queue<pair<int, psc>> pq; // Min heap for selecting next node
    pq.push({-0, {start, '-'}}); // Push start node to priority queue
    dist[{start, '-'}] = 0;
    while (!pq.empty()) {
        auto elem = pq.top(); // Get node with minimum distance from priority queue
        int cost = elem.first; cost *= -1;
        string u = elem.second.first;
        char c = elem.second.second;
        pq.pop();

        if (cost > dist[elem.second]) {
            continue; // Ignore outdated entries in the priority queue
        }

        if (u == destination) {
            return cost; // Reached the destination node, stop the algorithm
        }

        // Traverse all adjacent nodes of u
        for (const auto& edge : graph[u]) {
            char letter = edge.first.second;
            int weight = edge.second; // Weight of the edge (u,v)

            // Relaxation step
            int newCost = cost + weight;
            if (letter != c && (!dist.count(edge.first) || newCost < dist[edge.first])) {
                dist[edge.first] = newCost;
                pq.push({newCost*(-1), edge.first}); // Push updated distance and vertex to priority queue
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        if(!n) break;
        Graph graph;
        cin.ignore();
        string s1, s2, word;
        string start, destination;
        cin >> start >> destination;
        f(i,n){
            cin >> s1 >> s2 >> word;
            char c = word[0];
            int size = word.size();
            if(!graph[s1].count({s2,c})||graph[s1][{s2,c}]>size) graph[s1][{s2,c}] = size;
            if(!graph[s2].count({s1,c})||graph[s2][{s1,c}]>size) graph[s2][{s1,c}] = size;
        }
        int output = dijkstra(graph, start, destination);
        if(output>0) cout << output << '\n';
        else cout << "impossivel\n";
    }
    
    return 0;
}