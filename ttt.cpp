#include <iostream>
#include <vector>
using namespace std;

void Grid(const vector<vector<char> > &board)
{
    for(const auto &row : board)
    {
        for(char cell: row)
        {
            cout << cell << "  ";
        }
        cout << "\n...........\n";
    }
}

bool W(const vector<vector<char> > &board, char Player)
{
    for(int i = 0; i < 3; i++)
    {
        if((board[i][0] == Player && board[i][1] == Player && board[i][2] == Player) ||
           (board[0][i] == Player && board[1][i] == Player && board[2][i] == Player))
        {
            return true;
        }
    }
    
    if((board[0][0] == Player && board[1][1] == Player && board[2][2] == Player) ||
       (board[0][2] == Player && board[1][1] == Player && board[2][0] == Player))
    {
        return true;
    }
    
    return false;
}

bool Draw(const vector<vector<char> > &board)
{
    for(const auto &row : board)
    {
        for(char cell: row)
        {
            if(cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout << "Welcome to TIC TAC TOE!" << endl;
    vector<vector<char> > board(3, vector<char>(3,' '));
    char Player='X';
    int row, col;
    bool gameOver=false;
    while(!gameOver)
    {
        Grid(board);
        cout << "Player Move --> " << Player << " Enter row and column (0-2): ";
        cin >> row >> col;
        if(row < 0 || row > 2 || col < 0 || col > 2)
        {
            cout << "Invalid input! Please enter row and column values within the range 0-2." << endl;
            continue; // Restart the loop to prompt the player again
        }
        if(board[row][col]==' ')
        {
            board[row][col]=Player;
            gameOver=W(board, Player);
            
            if(gameOver)
            {
                Grid(board);
                cout << "Player " << Player << " wins!" << endl;
            }
            else if(Draw(board))
            {
                Grid(board);
                cout << "It's a draw :/ " << endl;
                gameOver=true;
            }
            Player=(Player=='X')? 'O': 'X';
        }
        else
        {
            cout << "That spot is already taken. Try again ;)" << endl;
        }
    }
    return 0;
}
