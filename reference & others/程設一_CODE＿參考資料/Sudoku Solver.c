#include <stdio.h>
#include <stdbool.h>

struct element {
    int num;        // 1~9: valid, 0: don't have value yet
    bool can_modify;       // true: white area in the figure, false: gray area in the figure
};

void solve(struct element (*grid_p)[9]);
void print_grid(struct element (*grid_p)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", grid_p[i][j].num);
        }
        printf("\n");
    }
}

int main(void) {
    struct element grid[9][9];
    char ch;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf(" %c", &ch);
            if (ch == '.') {    // can_modify assign true, num assign 0
                grid[i][j].num = 0;
                grid[i][j].can_modify = true;
            }
            else {      // value gotten from input, so we can't change this
                grid[i][j].num = ch - '0';
                grid[i][j].can_modify = false;
            }
        }
    }
    solve(grid);
    print_grid(grid);
    return 0;
}void solve(struct element (*grid_p)[9]) {
}