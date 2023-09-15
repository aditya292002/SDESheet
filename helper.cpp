#include "headers.hpp"

double calculateEuclideanDistance(double x1, double y1, double x2, double y2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}

void func(int ind, vector<pair<int, int>>& cor, vector<int>& vis, double temp, double& ans) {
    bool check = true;
    vis[ind] = 1;
    for (int i = 0; i < cor.size(); i++) {
        if (vis[i] == 0) {
            check = false;
            double dis = calculateEuclideanDistance(cor[ind].first, cor[ind].second, cor[i].first, cor[i].second);
            if(temp + dis >= ans) {
                continue;
            }
            func(i, cor, vis, temp + dis, ans);
        }
    }   
    vis[ind] = 0;
    if(check) {
        ans = min(ans, temp);
    }
}

double minDis(vector<int>& retailers, int hx, int hy, int g) {
    vector<pair<int, int>> cor;
    cor.push_back({g, 0});
    for (int i = 0; i < retailers.size(); i++) {
        cor.push_back({retailers[i], 0});
    }
    cor.push_back({hx, hy});

    int n = cor.size();
    double ans = (double) INT_MAX;
    vector<int> vis(n, 0);
    func(0, cor, vis, 0, ans);

    return ans;
}



int main() {
    vector<int> retailers = {-5, -4, -3, -1, 2, 5, 8, 10, 12, 18};  

    double result = minDis(retailers, 10, 3, 1);
    cout << fixed << setprecision(6); // Set output precision to 6 decimal places
    cout << "Minimum distance for Gregor: " << result << endl;

    return 0;
}



/*
#include "headers.hpp"

vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> diagonals = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};


int func(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    int val = 2;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) {


                queue<vector<int>> check_q;
                queue<vector<int>> q;
                vis[i][j] = 1;
                grid[i][j] = val;
                q.push({i, j});

                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    check_q.push(curr);

                    int x = curr[0], y = curr[1];

                    for (auto dir : directions) {
                        int nx = x + dir[0];
                        int ny = y + dir[1];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m and grid[nx][ny] == 1 and vis[nx][ny] == 0) {
                            vis[nx][ny] = 1;
                            grid[nx][ny] = val;
                            q.push({nx,ny});
                        }
                    }
                }


          
                bool check_ = false;
                while(!check_q.empty()) {
                    auto node = check_q.front(); check_q.pop();
                    int x = node[0]; int y = node[1];
                    for(auto dir : diagonals) {
                        int nx = x + dir[0];
                        int ny = y + dir[1];
                        if(nx >= 0 and ny >= 0 and nx < n and ny < m) {
                            if(grid[nx][ny] != val and grid[nx][ny] != 0) {
                                check_ = 1;
                            }
                        }
                        if(check_) break;
                    }
                    if(check_) {
                        break;
                    }
                }
                if(!check_) count++;

                val++;
            }
        }
    }
    debug(grid)
    return count;
}

int main() {
    int numRows = 5; // Number of rows
    int numCols = 5; // Number of columns

    // Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 1);

    // Create and populate the random 2D array
    vector<vector<int>> randomArray(numRows, vector<int>(numCols));
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            randomArray[i][j] = distribution(gen);
        }
    }
    
    debug(randomArray);
    debug(func(randomArray))

    return 0;
}
// int main() {      
    // vvi grid = {
    //     {1,0,0,0,0,1,1},
    //     {0,1,0,0,0,1,0},
    //     {0,0,1,0,0,1,1},
    //     {1,0,0,1,0,1,1},
    //     {1,0,0,0,0,0,0}
    // };

    // vvi grid = {
    //     {1,1,0,0},
    //     {0,1,0,0},
    //     {0,0,1,1},
    //     {0,0,1,1}
    // };
    // debug(func(grid));
// }  
*/