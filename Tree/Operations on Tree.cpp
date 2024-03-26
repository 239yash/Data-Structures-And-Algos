class LockingTree {
public:
    int n;
    vector<pair<int, pair<vector<int>, vector<int>>>> adj;
    LockingTree(vector<int>& parent) {
        n = parent.size();
        vector<pair<int, pair<vector<int>, vector<int>>>> graph(n);
        for (int i = 0 ; i < n; i++) {
            int child = i;
            int par = parent[i];
            
            if (child == 0) {
                graph[child].first = -1;
                continue;
            }
            
            // storing parents second.second
            graph[child].second.second.push_back(par);
            // storing child second.first
            graph[par].second.first.push_back(child);
            graph[child].first = -1;
            
        }
        adj = graph;
    }
    
    bool lock(int num, int user) {
        if (adj[num].first == -1) {
            adj[num].first = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (adj[num].first == user) {
            adj[num].first = -1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (adj[num].first != -1) return false;
        vector<int> lockedChild;
        getLockedChild(num, lockedChild);
        bool lockedAnc = checkForLockedAnc(num);
        if (lockedChild.size() == 0) return false;
        if (lockedAnc) return false;
        adj[num].first = user;
        for (auto x : lockedChild) {
            adj[x].first = -1;
        }
        return true;
    }
    
    bool checkForLockedAnc(int num) {
        bool ans = false;
        for (auto x : adj[num].second.second) {
            if (adj[x].first != -1) return true;
            ans = ans || checkForLockedAnc(x);
        }
        return ans;
    }
    
    void getLockedChild(int num, vector<int>& vec) {
        for (auto x : adj[num].second.first) {
            if (adj[x].first != -1) {
                vec.push_back(x);
            }
            getLockedChild(x, vec);
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */








// You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of the ith node. The root of the tree is node 0, so parent[0] = -1 since it has no parent. You want to design a data structure that allows users to lock, unlock, and upgrade nodes in the tree.

// The data structure should support the following functions:

// Lock: Locks the given node for the given user and prevents other users from locking the same node. You may only lock a node using this function if the node is unlocked.
// Unlock: Unlocks the given node for the given user. You may only unlock a node using this function if it is currently locked by the same user.
// Upgrade: Locks the given node for the given user and unlocks all of its descendants regardless of who locked it. You may only upgrade a node if all 3 conditions are true:
// The node is unlocked,
// It has at least one locked descendant (by any user), and
// It does not have any locked ancestors.
// Implement the LockingTree class:

// LockingTree(int[] parent) initializes the data structure with the parent array.
// lock(int num, int user) returns true if it is possible for the user with id user to lock the node num, or false otherwise. If it is possible, the node num will become locked by the user with id user.
// unlock(int num, int user) returns true if it is possible for the user with id user to unlock the node num, or false otherwise. If it is possible, the node num will become unlocked.
// upgrade(int num, int user) returns true if it is possible for the user with id user to upgrade the node num, or false otherwise. If it is possible, the node num will be upgraded.
 

// Example 1:


// Input
// ["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"]
// [[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]
// Output
// [null, true, false, true, true, true, false]

// Explanation
// LockingTree lockingTree = new LockingTree([-1, 0, 0, 1, 1, 2, 2]);
// lockingTree.lock(2, 2);    // return true because node 2 is unlocked.
//                            // Node 2 will now be locked by user 2.
// lockingTree.unlock(2, 3);  // return false because user 3 cannot unlock a node locked by user 2.
// lockingTree.unlock(2, 2);  // return true because node 2 was previously locked by user 2.
//                            // Node 2 will now be unlocked.
// lockingTree.lock(4, 5);    // return true because node 4 is unlocked.
//                            // Node 4 will now be locked by user 5.
// lockingTree.upgrade(0, 1); // return true because node 0 is unlocked and has at least one locked descendant (node 4).
//                            // Node 0 will now be locked by user 1 and node 4 will now be unlocked.
// lockingTree.lock(0, 1);    // return false because node 0 is already locked.
 

// Constraints:

// n == parent.length
// 2 <= n <= 2000
// 0 <= parent[i] <= n - 1 for i != 0
// parent[0] == -1
// 0 <= num <= n - 1
// 1 <= user <= 104
// parent represents a valid tree.
// At most 2000 calls in total will be made to lock, unlock, and upgrade.
