#include <stdio.h>
#include <stdlib.h>
#define n 8000

// Ignore this
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){exit(1);}
// Ignore this

void quicksort(int a[], int low, int high);
int main(void) {
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  quicksort(a, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  return 0;
}
void split(int a[], int lows, int highs);

void quicksort(int a[], int low, int high) {
	int low1, high1, part_element = a[low], middle;
	low1 = low;
	high1 = high;
	
	while(1){
		while(low < high && part_element <= a[high]){
			high = high - 1;
		}
		if(low == high) break;
		a[low] = a[high];
		low = low + 1;
		//if(low == high) break;
		/*
		if(part_element > a[high]){
			a[low] = a[high];
			low = low + 1;
		}
		*/
		while(low < high && part_element >= a[low]){
			low = low + 1;
		}
		if(low == high) break;
		a[high] = a[low];
		high = high - 1;
		//if(low == high) break;
		/*
		if(part_element >= a[low]){
			a[high] = a[low];
			high = high - 1;
		}
		*/
	}
	a[high] = part_element;
	//middle = high;
	split(a, low1, high - 1);
	split(a, high + 1, high1);
	/*
	if(low1 >= high - 1 && high1 <= high + 1) return;
	else if (low1 < high - 1 && high1 <= high + 1) quicksort(a, low1, high - 1);
	else if (low1 >= high - 1 && high1 > high + 1) quicksort(a, high + 1, high1);
	else{
	*/	
}

void split(int a[], int lows, int highs){
	if(lows >= highs) return;
	else quicksort(a, lows, highs);
}
