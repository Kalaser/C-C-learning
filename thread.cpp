#include <graphics.h>
#include <conio.h>
#include <ctime>

const int rows = 40;  // 行数
const int cols = 60;  // 列数
const int cellSize = 10;  // 细胞大小
const int delayTime = 100;  // 帧间隔

bool grid[rows][cols];
bool newGrid[rows][cols];

// 随机初始化细胞状态
void randomizeGrid() {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// 绘制细胞状态
void drawGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j]) {
                setfillcolor(YELLOW);
                fillrectangle(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
            } else {
                setfillcolor(BLACK);
                fillrectangle(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
            }
        }
    }
}

// 计算下一代细胞状态
void computeNextGeneration() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int liveNeighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = (i + di + rows) % rows;
                    int nj = (j + dj + cols) % cols;
                    liveNeighbors += grid[ni][nj];
                }
            }

            if (grid[i][j]) {
                // 细胞存活情况
                newGrid[i][j] = (liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                // 细胞繁衍情况
                newGrid[i][j] = (liveNeighbors == 3);
            }
        }
    }

    // 更新细胞状态
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

void clearGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = false;
        }
    }
}
void setInitialPattern() {
    clearGrid();

    // 示例：设置一个滑翔机初始模式
    grid[1][2] = true;
    grid[2][3] = true;
    grid[3][1] = true;
    grid[3][2] = true;
    grid[3][3] = true;
}

int main() {
    initgraph(cols * cellSize, rows * cellSize);
    setbkcolor(BLACK);
    cleardevice();
    setInitialPattern();
    randomizeGrid();
    while (!kbhit()) {
        
        drawGrid();
        computeNextGeneration();
        Sleep(delayTime);
        
    }
    

    closegraph();
    return 0;
}
