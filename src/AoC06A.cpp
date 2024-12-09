#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>


char map[130][130];

int main() {

    std::ifstream file("../inputs/data06.txt");
    std::string line;

    int x = 0;
    int y = 0;

    int idx = 0;
    
    //   0  
    // 3 X 1
    //   2  
    std::vector<std::pair<int, int>> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int direction = 0;

    while (std::getline(file, line)) {
        char cline [131];
        strcpy(cline, line.c_str());
        memcpy(map[idx], cline, 130);
        idx++;
    }

    for (int idx = 0; idx < 130; idx++) {
        for (int jdx = 0; jdx < 130; jdx++) {
            if (map[jdx][idx] == '^') {
                x = idx;
                y = jdx;
                break;
            }
        }
    }

    while (bool active = true) {
        map[y][x] = 'X'; 
        int new_x = x + directions[direction].first;
        int new_y = y + directions[direction].second;

        if (map[new_y][new_x] == '#') {
            direction = (direction + 1) % 4;
            x = x + directions[direction].first;
            y = y + directions[direction].second;
        } else if (map[new_y][new_x] == '.') {
            x = new_x;
            y = new_y;
        } else if (map[new_y][new_x] == 'X') {
            x = new_x;
            y = new_y;
        } else if (new_x < 0 || new_x >= 130 || new_y < 0 || new_y >= 130) {
            break;
        }
        
    }

    int visited = 0;
    for (int idx = 0; idx < 130; idx++) {
        for (int jdx = 0; jdx < 130; jdx++) {
            printf("%c", map[idx][jdx]);
            if (map[idx][jdx] == 'X') {
                visited++;
            }
        }
        printf("\n");
    }
    printf("Visited: %d\n", visited);

    return 0;
}





