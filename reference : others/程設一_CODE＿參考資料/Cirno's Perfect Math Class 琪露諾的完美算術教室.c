//
//  main.c
//  progHw#4
//
//  Created by 劉翊安 on 2020/9/24.
//  Copyright © 2020 劉翊安. All rights reserved.
//

#include <stdio.h>
 
int main()
{
    int x, y, z;
    int A = 0, B = 0, C = 0 , D = 0;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    x = A;
    y = x - B + C;
    z = y - D;
    printf("%.4d %.4d %.4d", x, y, z);
    return 0;
}
