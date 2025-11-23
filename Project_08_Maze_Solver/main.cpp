/*
 * ============================================================================
 * PROJECT #8: MAZE SOLVER & GENERATOR
 * ============================================================================
 * Data Structure: Graph (adjacency matrix), BFS, DFS algorithms
 * Features: Generate random maze, solve using BFS/DFS, visualize path
 * ============================================================================
 */

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10;

struct Point {
    int row, col;
    Point(int r = 0, int c = 0) : row(r), col(c) {}
    bool operator==(const Point& other) const {
        return row == other.row && col == other.col;
    }
};

class Maze {
private:
    int grid[SIZE][SIZE];
    Point start, end;
    bool visited[SIZE][SIZE];

    // Direction vectors: Up, Right, Down, Left
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool isValid(int r, int c) {
        return r >= 0 && r < SIZE && c >= 0 && c < SIZE;
    }

    void resetVisited() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                visited[i][j] = false;
            }
        }
    }

public:
    Maze() {
        srand(time(0));
        generateMaze();
    }

    void generateMaze() {
        // Initialize with walls
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = (rand() % 100 < 30) ? 1 : 0; // 30% walls
            }
        }

        // Set start and end
        start = Point(0, 0);
        end = Point(SIZE - 1, SIZE - 1);
        grid[start.row][start.col] = 0;
        grid[end.row][end.col] = 0;

        // Ensure at least one path exists (simple approach)
        for (int i = 0; i < SIZE; i++) {
            grid[i][i] = 0;
        }

        cout << "✅ New maze generated!" << endl;
    }

    void displayMaze() const {
        cout << "\n  ";
        for (int i = 0; i < SIZE; i++) cout << "══";
        cout << "\n";

        for (int i = 0; i < SIZE; i++) {
            cout << "  ";
            for (int j = 0; j < SIZE; j++) {
                if (i == start.row && j == start.col) {
                    cout << "S "; // Start
                } else if (i == end.row && j == end.col) {
                    cout << "E "; // End
                } else if (grid[i][j] == 1) {
                    cout << "# "; // Wall
                } else if (grid[i][j] == 2) {
                    cout << ". "; // Path
                } else {
                    cout << "  "; // Open space
                }
            }
            cout << "\n";
        }

        cout << "  ";
        for (int i = 0; i < SIZE; i++) cout << "══";
        cout << "\n";
    }

    void displayWithPath(const vector<Point>& path) {
        // Mark path
        for (const Point& p : path) {
            if (!(p == start) && !(p == end)) {
                grid[p.row][p.col] = 2;
            }
        }

        displayMaze();

        // Clean up path markers
        for (const Point& p : path) {
            if (!(p == start) && !(p == end)) {
                grid[p.row][p.col] = 0;
            }
        }
    }

    bool solveBFS() {
        resetVisited();
        queue<Point> q;
        Point parent[SIZE][SIZE];
        
        q.push(start);
        visited[start.row][start.col] = true;
        parent[start.row][start.col] = Point(-1, -1);

        while (!q.empty()) {
            Point curr = q.front();
            q.pop();

            if (curr == end) {
                // Reconstruct path
                vector<Point> path;
                Point p = end;
                while (!(p == Point(-1, -1))) {
                    path.push_back(p);
                    p = parent[p.row][p.col];
                }

                cout << "\n✅ Path found using BFS! (Length: " << path.size() << ")" << endl;
                displayWithPath(path);
                return true;
            }

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int newR = curr.row + dr[i];
                int newC = curr.col + dc[i];

                if (isValid(newR, newC) && !visited[newR][newC] && grid[newR][newC] == 0) {
                    visited[newR][newC] = true;
                    q.push(Point(newR, newC));
                    parent[newR][newC] = curr;
                }
            }
        }

        cout << "\n❌ No path found using BFS!" << endl;
        return false;
    }

    bool solveDFS() {
        resetVisited();
        stack<Point> s;
        Point parent[SIZE][SIZE];
        
        s.push(start);
        visited[start.row][start.col] = true;
        parent[start.row][start.col] = Point(-1, -1);

        while (!s.empty()) {
            Point curr = s.top();
            s.pop();

            if (curr == end) {
                // Reconstruct path
                vector<Point> path;
                Point p = end;
                while (!(p == Point(-1, -1))) {
                    path.push_back(p);
                    p = parent[p.row][p.col];
                }

                cout << "\n✅ Path found using DFS! (Length: " << path.size() << ")" << endl;
                displayWithPath(path);
                return true;
            }

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int newR = curr.row + dr[i];
                int newC = curr.col + dc[i];

                if (isValid(newR, newC) && !visited[newR][newC] && grid[newR][newC] == 0) {
                    visited[newR][newC] = true;
                    s.push(Point(newR, newC));
                    parent[newR][newC] = curr;
                }
            }
        }

        cout << "\n❌ No path found using DFS!" << endl;
        return false;
    }

    void setCustomMaze() {
        cout << "\n  Enter maze (0=path, 1=wall):" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << "  Row " << i << ": ";
            for (int j = 0; j < SIZE; j++) {
                cin >> grid[i][j];
            }
        }
        grid[start.row][start.col] = 0;
        grid[end.row][end.col] = 0;
        cout << "✅ Custom maze set!" << endl;
    }
};

int main() {
    Maze maze;

    cout << "\n========================================================\n";
    cout << "             MAZE SOLVER & GENERATOR                    \n";
    cout << " S = Start, E = End, # = Wall,   = Path, . = Solution  \n";
    cout << "========================================================\n";

    int choice;
    while (true) {
        cout << "\n  1. Display Maze\n";
        cout << "  2. Generate New Maze\n";
        cout << "  3. Solve using BFS (Breadth-First Search)\n";
        cout << "  4. Solve using DFS (Depth-First Search)\n";
        cout << "  5. Set Custom Maze\n";
        cout << "  6. Exit\n";
        cout << "  Choice: ";
        cin >> choice;

        if (choice == 1) {
            maze.displayMaze();
        }
        else if (choice == 2) {
            maze.generateMaze();
            maze.displayMaze();
        }
        else if (choice == 3) {
            maze.solveBFS();
        }
        else if (choice == 4) {
            maze.solveDFS();
        }
        else if (choice == 5) {
            maze.setCustomMaze();
        }
        else if (choice == 6) {
            cout << "\n  🧩 Thanks for using Maze Solver!\n";
            break;
        }
    }

    return 0;
}
