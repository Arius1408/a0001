#include <iostream>
#include <string>
#include <vector>

int h, w;

int main (int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);

    std::cin >> h >> w;
    char str[w][h];

    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            std::cin >> str[i][j];
        }
    }

    int dx[4] = {-1, 0, 1, 1};
    int dy[4] = {0, -1, 0, 1};

    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if (str[i][j] == 'S') {
                for (int k = 0; k < 4; k ++) {
                    int newi = i + dx[k];
                    int newj = j + dy[k];

                    if (newi < 0 || newi >= h) continue;
                    if (newj < 0 || newj >= w) continue;

                    if (str[newi][newj] != 'W') {
                        str[newi][newj] = 'D';
                    } else {
                        std::cout << "NO";
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "YES" << "\n";
    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            std::cout << str[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
