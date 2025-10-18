#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>
using namespace std;

int FjFavCows, a, b; // FjFavCows = number of nodes (cows)
map<int, long long> ids; // cow counts for each unique id (using long long)
int idlist[200005];
map<int, vector<int>> graph;
long long ans = 0;

// Returns the number of neighbors with remaining cows.
int checksize(int node) {
    int tot = 0;
    for (int x : graph[node])
        if (ids[x] > 0) tot++;
    return tot;
}

// Process leaves using a queue so that nodes which become leaves are handled.
void processLeaves() {
    queue<int> q;
    // Initially add all nodes that are leaves.
    for (int i = 0; i < FjFavCows; i++){
        if (ids[idlist[i]] > 0 && checksize(idlist[i]) == 1) {
            q.push(idlist[i]);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // Recheck leaf condition; if node is no longer a leaf or has no cows, skip it.
        if (ids[node] == 0 || checksize(node) != 1)
            continue;
        
        int next = -1;  // find the unique neighbor with remaining cows
        for (int x : graph[node]) {
            if (ids[x] > 0) {
                next = x;
                break;
            }
        }
        if (next == -1)
            continue;
        
        if (node == next) { // self-loop case for a leaf node
            long long pairs = ids[node] / 2;
            ans += pairs;
            ids[node] %= 2;  // leave only the remainder after pairing
            continue;
        }
        // Pair as many cows as possible between node and its neighbor.
        long long added = min(ids[node], ids[next]);
        ans += added;
        ids[node] -= added;
        ids[next] -= added;
        
        // If the neighbor now has a leaf condition, add it to the queue.
        if (ids[next] > 0 && checksize(next) == 1)
            q.push(next);
        // If the current node still has cows and remains a leaf, push it too.
        if (ids[node] > 0 && checksize(node) == 1)
            q.push(node);
    }
}

// This function handles self-loops and any remaining pairings after leaf processing.
void use_loop(int node) {
    if (ids[node] == 0) return; // nothing to pair
    
    for (int next : graph[node]) {
        if (ids[next] == 0)
            continue;
        if (node == next) { // self-loop
            long long pairs = ids[node] / 2;
            ans += pairs;
            ids[node] %= 2;  // leave remainder cows after pairing
            continue;
        }
        long long added = min(ids[node], ids[next]);
        ans += added;
        ids[node] -= added;
        ids[next] -= added;
        use_loop(next);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> FjFavCows >> a >> b;
    for (int i = 0; i < FjFavCows; i++){
        int shared;
        cin >> shared >> idlist[i];
        ids[idlist[i]] = shared;
    }
    
    // Build graph edges only if the partner ID exists and has available cows.
    for (int i = 0; i < FjFavCows; i++){
        int id_n = idlist[i];
        int partnerA = a - id_n;
        int partnerB = b - id_n;
        if (ids.find(partnerA) != ids.end() && ids[partnerA] > 0) {
            graph[id_n].push_back(partnerA);
        }
        if (ids.find(partnerB) != ids.end() && partnerB != partnerA && ids[partnerB] > 0) {
            graph[id_n].push_back(partnerB);
        }
    }
    
    // Process leaves using our new queue-based approach.
    processLeaves();
    
    // Process any remaining possible pairings (including self-loops) in the graph.
    for (int i = 0; i < FjFavCows; i++){
        use_loop(idlist[i]);
    }
    cout << ans << "\n";
    return 0;
}

