#include <iostream>
#include <vector>
#include <string>

int n, d;
int count = 0;
std::string str;

int main (int argc, const char * argv[]) {
    std::cin >> n >> d;
    std::cin >> str;

    int i = 0;
    while (i != n-1) {

        for (int j = i +d; j > i; j --) {
            if (str[j] == '1') {
                i = j;
                std::cout << i << "\n";
                count ++;
                break;
            } else if (j = i+1 && str[j] != '1') {
                std::cout << -1;
                return 0;
            }
        }
    }

    if (i = n-1) std::cout << count;

    return 0;
}
