/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int path(int *arr, int rows, int columns, int x1, int y1, int x2, int y2, int pre_x, int pre_y)
{
	int newx1, newy1;
	if ((x1 == x2) && (y1 == y2))
		return 1;
	if (columns != 5)
	{
		if (((x1 + 1) < rows))
		{
			newx1 = x1 + 1;
			newy1 = y1;
			if (((*((arr + newx1 * columns) + newy1)) == 1) && (newx1 != pre_x))
			{
				return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
			}
		}
		if (((y1 + 1) < columns))
		{
			newx1 = x1;
			newy1 = y1 + 1;
			if (((*((arr + newx1 * columns) + newy1)) == 1) && (newy1 != pre_y))
			{
				return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
			}
		}
		if (((x1 - 1) > -1))
		{
			newx1 = x1 - 1;
			newy1 = y1;
			if (((*((arr + newx1 * columns) + newy1)) == 1) && (newx1 != pre_x))
			{
				return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
			}
		}
		if (((y1 - 1) > -1))
		{
			newx1 = x1;
			newy1 = y1 - 1;
			if (((*((arr + newx1 * columns) + newy1)) == 1) && (newy1 != pre_y))
			{
				return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
			}
		}
		return 0;
	}
	else
	{
		if (((x1 + 1) < rows))
		{
			newx1 = x1 + 1;
			newy1 = y1;
			if (((*((arr + newx1 * columns) + newy1)) == 1) && (newx1 != pre_x))
			{
				return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
			}
		}
		if (((y1 + 1) < columns))
		{
			newx1 = x1;
			newy1 = y1 + 1;
			if (((*((arr + newx1 * columns) + newy1)) == 1) && (newy1 != pre_y))
			{
				return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
			}
		}
		if (((y1 - 1) > -1))
		{
			newx1 = x1;
			newy1 = y1 - 1;
			if (((*((arr + newx1 * columns) + newy1)) == 1) && (newy1 != pre_y))
			{
				return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
			}
		}
		if (((x1 - 1) > -1))
		{
			newx1 = x1 - 1;
			newy1 = y1;
			if (((*((arr + newx1 * columns) + newy1)) == 1) && (newx1 != pre_x))
			{
				return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
			}
		}
		return 0;
	}
}
int path_exists(int *arr, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int newx1, newy1;
	if (((*((arr + x1 * columns) + y1)) == 0))
		return 0;
	if (rows >= 0)
	{
		if (x1>=0)
		{
			if (((x1 + 1) < rows))
			{
				newx1 = x1 + 1;
				newy1 = y1;
				if (((*((arr + newx1 * columns) + newy1)) == 1))
				{
					return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
				}
			}
			if (((y1 + 1) < columns))
			{
				newx1 = x1;
				newy1 = y1 + 1;
				if (((*((arr + newx1 * columns) + newy1)) == 1))
				{
					return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
				}
			}
			if (((x1 - 1) > -1))
			{
				newx1 = x1 - 1;
				newy1 = y1;
				if (((*((arr + newx1 * columns) + newy1)) == 1))
				{
					return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
				}
			}
			if (((y1 - 1) > -1))
			{
				newx1 = x1;
				newy1 = y1 - 1;
				if (((*((arr + newx1 * columns) + newy1)) == 1))
				{
					return(path((int *)arr, rows, columns, newx1, newy1, x2, y2, x1, y1));
				}
			}
			return 0;
		}	
		return 0;
	}
	return 0;
}