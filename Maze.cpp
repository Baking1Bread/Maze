#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int Height = 5;
const int Width = 5;


bool move(char maze[][Width], bool visited[][Width], int& currentX, int& currentY, int newX, int newY)
{
    bool Exit = false;

    if (maze[newY][newX] == 'E')
    {
        Exit = true; // Ausgang 
    }
    currentX = newX; // Neue Position
    currentY = newY;
    visited[currentY][currentX] = true;
    return Exit;
}
bool goodMove(char maze[][Width], bool visited[][Width], int newX, int newY)
{
    // Check if were going off the edge of the maze
    if (newX < 0 || newX >= Width)
        return false;
    if (newY < 0 || newY >= Height)
        return false;
    // Wallchecker
    if (maze[newY][newX] == 'X')
        return false;
    //Verhindert zurueckgehen
    if (visited[newY][newX])
        return false;
    return true;
}

void printmaze(char maze[][Width], int currentx, int currenty)
{
    for (int y = 0; y < Height; y++)
    {
        for (int x = 0; x < Width; x++)
        {
            if ((x == currentx) && (y == currenty))
            {
                cout << "P";
            }
            else
            {
                cout << maze[y][x];
            }
        }
        cout << endl;
    }
}
int main()
{

    bool visited[Height][Width];
    char maze[Height][Width] =
    {
        {'X','X','X','X','X'},
        {'X',' ',' ',' ','X'},
        {'X',' ','X','X','X'},
        {'X',' ',' ',' ','X'},
        {'X','X','X','E','X'}
    };
    int x = 1;
    int y = 1;

    for (int x = 0; x < Width; x++)
    {
        for (int y = 0; y < Height; y++)
        {
            visited[y][x] = false;
        }
        visited[y][x] = true;
    }
    bool Exit = false;
    //X = Wall
    //' ' = Path
    //E = Exit
    while (!Exit)
    {
        printmaze(maze, x, y);
        cout << "_____" << endl;
        char m;
        int random = rand() % 4;
        if (random == 0)
        {
            m = 'w';
        }
        else if (random == 1)
        {
            m = 'a';
        }
        else if (random == 2)
        {
            m = 's';
        }
        else
        {
            m = 'd';
        }
        //
        switch (m)
        {
        case 'w':
            if (goodMove(maze, visited, x, y - 1))
                Exit = move(maze, visited, x, y, x, y - 1);
            break;
        case 'a':
            if (goodMove(maze, visited, x - 1, y))
                Exit = move(maze, visited, x, y, x - 1, y);
            break;
        case 's':
            if (goodMove(maze, visited, x, y + 1))
                Exit = move(maze, visited, x, y, x, y + 1);
            break;
        case 'd':
            if (goodMove(maze, visited, x + 1, y))
                Exit = move(maze, visited, x, y, x + 1, y);
        }
    }




}

