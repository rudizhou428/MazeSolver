#include <stdio.h>
#include <stdlib.h>
#include "QueueInterface.h"

int main(void)
{
    Queue Q;
    InitializeQueue(&Q);

    int row;
    int column;

    int x;
    int y;

    scanf("%d %d\n", &column, &row); //scan dimensions of maze


    char input[row][column+2];
    ItemType maze[row][column];
    for(x = 0; x < row; x++) {
            fgets(input[x],column+2,stdin);
    }

    for (x = 0; x < row; x++){
            for (y = 0; y < column; y++) {
                    maze[x][y].squareType = input[x][y];
                    maze[x][y].xCoordinate = x;
                    maze[x][y].yCoordinate = y;
                    maze[x][y].recordedSquare = 0;
            }
    }

    for(x = 0; x < row; x++){
            for(y = 0; y < column; y++) {
                    if (maze[x][y].squareType == 'o')
                      Insert(maze[x][y],&Q);  //INSERTED HERE
            }
    }
    for (x = 0; x < row; x++) {
            for (y = 0; y < column; y++) {
                    printf("%c", maze[x][y].squareType);
            }
    printf("\n");
    }

}