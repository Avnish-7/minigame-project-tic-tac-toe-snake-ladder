#include <bits/stdc++.h>

using namespace std;

class SnakeAndLadder{
    private:
        int player1Pos;
        int player2Pos;
        int board[101]; // Index 0 is ignored. 1-100 represents the squares

        public:
            SnakeAndLadder(){
                reset_game();
            }

            void reset_game(){
                player1Pos = 0; // Players start off the board at 0
                player2Pos = 0;

                // 1. Make every square a "normal" square by default
                for (int i = 1; i <= 100; i++) {
                board[i] = 0; 
                }

                // 2. Add the Ladders (Start -> End)
                board[3] = 22;
                board[5] = 8;
                board[11] = 26;
                board[20] = 29;
                board[27] = 84; // The mega ladder!
                board[50] = 67;
                board[71] = 92;

                // 3. Add the Snakes (Start -> End)
                board[21] = 9;
                board[47] = 26;
                board[54] = 34;
                board[62] = 19; 
                board[80] = 60;
                board[93] = 73;
                board[98] = 28; // The heartbreak snake!
        
                // Seed the random number generator so dice rolls are different every game
                srand(time(0)); 
            }

            // Function to roll a 6-sided die
            int roll_dice() {
                return (rand() % 6) + 1; // Generates a number between 1 and 6
            }

            // Function to show where everyone is
            void display_status() {
                
                cout << "\n----------------------------------------";
                cout << "\nPlayer 1 is on square: " << player1Pos;
                cout << "\nPlayer 2 is on square: " << player2Pos;
                cout << "\n----------------------------------------\n";
            }

            void play_turn(int &currentPos,int playerNum){
                int roll=roll_dice();
                cout<<"\n Player "<<playerNum<<" rolled a "<<roll<<"!";
                int newPos=currentPos + roll;

                // Rule: You must roll the exact number to land on 100. 
                if (newPos > 100) {
                    cout << "\nToo high! You need an exact roll to hit 100. You stay at " << currentPos << ".";
                } 
                else if (newPos == 100) {
                    currentPos = newPos; // They hit 100 exactly!
                }

                else{  //newpos<100
                    currentPos = newPos;
                    cout << "\nPlayer " << playerNum << " moves to square " << currentPos << ".";
                    // CHECK THE ARRAY: Did they land on a snake or ladder?
                    // If the board array isn't 0, there is a trap or boost here!
                    if (board[currentPos] != 0) {
                
                        // If the new square is HIGHER than the current one, it's a ladder!
                        if (board[currentPos] > currentPos) {
                            cout << "\n🎉 YAY! You found a ladder! Climbing up to " << board[currentPos] << "!";
                        } 
                        // Otherwise, it must be a snake!
                        else {
                            cout << "\n🐍 OH NO! A snake bit you! Sliding down to " << board[currentPos] << "!";
                        }
                
                        // Teleport the player to the end of the snake or ladder
                        currentPos = board[currentPos]; 
                    }

                }
                cout<<"\n";
            }

        void play() {
            bool gameOver = false;
            int currentPlayer = 1;
            //Start with a clean screen for the very first board
            system("cls");
            display_status();

            while (!gameOver) {
                
            
                cout << "Player " << currentPlayer << "'s turn. Press ENTER to roll the dice...";
            
                // This trick pauses the console until the user presses Enter 
                cin.get();   
                
                // Wipe the screen right after they press Enter! 
                system("cls");

                if (currentPlayer == 1) {
                    // Pass Player 1's position variable into the turn function
                    play_turn(player1Pos, 1);
                    display_status();
                
                    // Check if they won
                    if (player1Pos == 100) {
                        display_status();
                        cout << "\n\n🏆 CONGRATULATIONS! PLAYER 1 WINS THE GAME! 🏆\n\n";
                        gameOver = true;
                    } 
                    else {
                        currentPlayer = 2; // Pass the turn to Player 2
                    }
                } 
                else {
                    // Pass Player 2's position variable into the turn function
                    play_turn(player2Pos, 2);
                    display_status();
                
                    // Check if they won
                    if (player2Pos == 100) {
                        cout << "\n\n🏆 CONGRATULATIONS! PLAYER 2 WINS THE GAME! 🏆\n\n";
                        gameOver = true;
                    } else {
                        currentPlayer = 1; // Pass the turn to Player 1
                    }
                }
            }
        }


            


};

int main() {
    char playAgain;
    SnakeAndLadder game;
    do {
        // Run the actual game match
        game.play();


        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        cin.ignore();

        // If they want to play again, scrub the board clean!
        if(playAgain == 'Y' || playAgain == 'y'){
            game.reset_game();
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}