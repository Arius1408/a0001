#include <vector>
#include <queue>
#include <iostream>

const int limit = 20000;

int n, d;
int max = 0;

std::vector <int> arr[limit];
int depth[limit];
bool used[limit];
std::queue <int> q;
std::vector <int> result;

void craft(int *x, int *y) {
    arr[*x].push_back(*y);
    arr[*y].push_back(*x);
}

void measure(int *key) {
    q.push(*key);
    used[*key] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int x : arr[u]) {
            if (!used[x]) {
                used[x] = true;
                depth[x] = depth[u] + 1;

                q.push(x);
            }
        }
    }
}

int main (int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;

    int i;
    for (i = 1; i <= n; i ++) {
        std::cin >> d;

        if (d == -1) result.push_back(i);
        else craft(&d, &i);
    }

    for (i = 0; i <= (int)result.size(); i ++) {
        measure(&result[i]);
    }

    for (i = 1; i <= n; i ++) {
        if (depth[i] > max) max = depth[i];
    }

    std::cout << max+1;

    return 0;
}
