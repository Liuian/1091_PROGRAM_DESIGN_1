#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

void find_fruit(char input[],char fruit[][15]);

int main(void) {
	char fruit[20][15] = {
        "guava",
        "litchi",
        "longan",
        "watermelon",
        "pomelo",
        "pear",
        "banana",
        "papaya",
        "pumpkin",
        "tomato",
        "mango",
        "kiwi",
        "persimmon",
        "cantaloupe",
        "strawberry",
        "grape",
        "peach",
        "orange",
        "coconut",
        "lemon"
    };
    char input[N];
    scanf("%s", input);
    find_fruit(input,fruit);
    return 0;
}
// Your code goes here
int cmp(const void *a, const void *b);	
struct record{
		int num;
unsigned long long int cou;
	};
	struct record record[20];
void find_fruit(char input[],char fruit[][15]){
	char *plus = "+_+", *num;

	for(int i = 0; i < 20; i++){
		record[i].num = i;
		record[i].cou = 0;
	}
	num = strtok(input, plus);
    if(num == NULL){
        printf(""); 
        }
	while(num != NULL){
		for(int i = 0; i < 20; i++){
			if(strcmp(fruit[i], num) == 0){
				record[i].cou += 1;
				break;
			}
		}
		num = strtok(NULL, plus);
	}
	qsort((void*)record, 20, sizeof(struct record), cmp);
	unsigned long long int q;
	q = record[0].cou;
	long long int k = 0;
	while(record[k].cou == q && k <= 20){
		k+=1;
	}
	k -=1;
	//printf("%d", k);
	for(int i = k;i >= 0;i--){
		printf("%s\n", fruit[record[i].num]);
	}
}
int cmp(const void *a, const void *b){
	long long int i = (*(struct record*)a).cou;
	long long int j = (*(struct record*)b).cou;
	if(i > j) return -1;
	else if(i == j) return 0;
	else return 1;
}
