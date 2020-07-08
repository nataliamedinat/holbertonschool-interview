#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void changes(int grid1[3][3]);
void add_grids(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid1[3][3]);

#endif
