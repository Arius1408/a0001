#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

const int limit = 20000;
int n, d;
std::vector <bool> used(limit, false);

std::vector <int> arr[limit];
std::vector <int> result;
std::vector <int> height(limit);

void add_edge(int *x, int *y) {
    arr[*x].push_back(*y);
    arr[*y].push_back(*x);
}

void depth(int *key) {
    std::queue <int> q;

    q.push(*key);
    used[*key] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i : arr[v]) {
            if (!used[i]) {
                q.push(i);
                used[i] = true;
                height[i] = height[v] + 1;
            }
        }
    }
}

int max_num(std::vector <int> &h)  {
    int max = 0;
    for (int i : h) {
        if (i > max) max = i;
    }

    return max;
}

int main (int agrc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    freopen("cin.txt", "r", stdin); freopen("cout.txt", "w", stdout);
    
    std::cin >> n;
    height.resize(n+1);
    used.resize(n+1);

    for (int i = 1; i <= n; i ++) {
        arr[i].clear();
    }

    for (int i = 1; i <= n; i ++) {
        std::cin >> d;
        if (d != 1) {
            add_edge(&d, &i);
        } else {
            result.push_back(i);
            height[i] = 1;
        }
    }

    for (int i = 0; i < result.size(); i ++) {
        depth(&result[i]);
    }

    std::cout << max_num(height);

    return 0;
}
