#include <bits/stdc++.h>

using namespace std;

class TicTacToe{
    private:
        char board[3][3];
        char currentPlayer;

    public:
        // Constructor: Runs automatically when a game starts
        TicTacToe() {
        //a nested for-loop to fill the 3x3 board array with numbers '1' through '9'
        char num='1';
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j]=num;
                num++;
            }
        }
        // This helps the user know which number to type to pick a square!
        currentPlayer = 'X'; // 'X' always goes first
        }

        void display_board() {
        system("cls");
        cout << "\n\n=== TIC TAC TOE ===\n\n";
        cout << "Player 1 (X)  -  Player 2 (O)\n\n";

        
        cout << "     |     |     \n";
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
        cout << "     |     |     \n\n";   
        }

        bool make_move(int choice){
            int index=choice-1;

            int row=index/3;
            int col=index%3;

            if(board[row][col] != 'X' && board[row][col] != 'O'){
                board[row][col] = currentPlayer;
                return true;
            }

            return false;
        }

        bool check_win(){
            //checking horizontal rows
            if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) return true;
            if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) return true;
            if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) return true;

            //checking vertical rows
            if(board[0][0] == board[1][0] && board[1][0] == board[2][0]) return true;
            if(board[0][1] == board[1][1] && board[1][1] == board[2][1]) return true;
            if(board[0][2] == board[1][2] && board[1][2] == board[2][2]) return true;

            //checking diagonals
            if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
            if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

            return false;
            
        }

        bool check_draw() {
            
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        if(board[i][j] != 'X' && board[i][j] != 'O'){
                            return false;
                        }
                }
            }

            return true;
        
        }   

        // Function to swap players
        void switch_player() {
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        }

        void play() {
            int choice;
            bool game_over = false;

            while (!game_over) {
                display_board();
                cout << "Player " << currentPlayer << ", enter a number (1-9): ";
                cin >> choice;

                // Validate input range and attempt the move
                if (choice >= 1 && choice <= 9 && make_move(choice)) {
                
                    // Check if that move won the game
                    if (check_win()) {
                        display_board();
                        cout << "==== GAME OVER ====\n";
                        cout << "Player " << currentPlayer << " Wins!\n";
                        game_over = true;
                    } 
                    // Check if that move resulted in a draw
                    else if (check_draw()) {
                        display_board();
                        cout << "==== GAME OVER ====\n";
                        cout << "It's a Draw!\n";
                        game_over = true;
                    } 
                    // If neither, switch player and loop again
                    else {
                        switch_player();
                    }
                } 
                else{
                    cout << "\nInvalid move! That spot is taken or out of bounds. Try again.\n";
                }
            }
        }
};

int main() {
    
    char playAgain;

    
    do {
        TicTacToe game;
        // Run the game
        game.play();

        // Ask the user if they want to play another round
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

        

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing! Goodbye.\n";

    return 0;
}
