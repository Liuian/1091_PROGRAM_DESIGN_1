#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}#include <stdbool.h>
// Your code goes here

void check_sudoku(int (*grid_p)[NUM]){
/*
	struct nine_squr{
		bool bul;
		int rol;
		int col;
	};
	struct nine_squr sudoku[NUM][NUM];
*/
	struct nine{
		bool buul;
		int row/*num*/;
		int col;
	};
	struct nine judge[NUM];
	//initialize nine
	for(int i = 0; i < NUM; i++){
		judge[i].buul = false;
	}
/*
	//initialize nine_squr
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			sudoku[i][j].bul = false;
		}
	}
*/
	bool sudoku[NUM][NUM];
	for(int i = 0; i < NUM; i ++){
		for(int j = 0; j < NUM; j++){
			sudoku[i][j] = false;
		}
	}
	//check every row
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			if(judge[grid_p[i][j] - 1].buul == false){
				judge[grid_p[i][j] - 1].buul = true;
				judge[grid_p[i][j] - 1].col = j;
				//judge[grid_p[i][j] - 1].buul = true;
			}
			else{
				sudoku[i][judge[grid_p[i][j] - 1].col] = true;
				sudoku[i][j] = true;
			}
		}
		for(int i = 0; i < NUM; i++){
			judge[i].buul = false;
		}
	}
	//check every column
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			if(judge[grid_p[j][i] - 1].buul == false){
				judge[grid_p[j][i] - 1].buul = true;
				judge[grid_p[j][i] - 1].col = j;
				//judge[grid_p[i][j] - 1].buul = true;
			}
			else{
				sudoku[judge[grid_p[j][i] - 1].col][i] = true;
				sudoku[j][i] = true;
			}
		}
		for(int i = 0; i < NUM; i++){
			judge[i].buul = false;
		}
	}
	//check every block
	for(int m = 0; m < 3; m++){
		for(int n = 0; n < 3; n++){
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j ++){
					if(judge[grid_p[m * 3 + i][n * 3 + j] - 1].buul == false){
						judge[grid_p[m * 3 + i][n * 3 + j] - 1].buul = true;
						//不能直接給
						judge[grid_p[m * 3 + i][n * 3 + j] - 1].row = m * 3 + i;
						judge[grid_p[m * 3 + i][n * 3 + j] - 1].col = n * 3 + j;
					}
					else{
						sudoku[judge[grid_p[m * 3 + i][n * 3 + j] - 1].row][judge[grid_p[m * 3 + i][n * 3 + j] - 1].col] = true;
						sudoku[m * 3 + i][n * 3 + j] = true;
					}
				}
			}
		for(int i = 0; i < NUM; i++){
			judge[i].buul = false;
		}
		}
	}

	//print frame
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			if(sudoku[i][j] == true){
				printf("(%d,%d)\n", i, j);
			}
		}
	}
}
