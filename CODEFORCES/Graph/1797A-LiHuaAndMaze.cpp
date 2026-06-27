#include <iostream>
#include <algorithm>

using namespace std;

// Function to calculate how many neighbors a cell has
int getDegree(int r, int c, int n, int m) {
    int count = 0;
    if (r > 1) count++; // Can move up
    if (r < n) count++; // Can move down
    if (c > 1) count++; // Can move left
    if (c < m) count++; // Can move right
    return count;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int degree1 = getDegree(x1, y1, n, m);
    int degree2 = getDegree(x2, y2, n, m);
    
    cout << min(degree1, degree2) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}