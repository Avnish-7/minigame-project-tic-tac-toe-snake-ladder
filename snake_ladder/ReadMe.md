🐍🪜 Snake and Ladder (C++)

A classic, console-based 2-player Snake and Ladder game developed in C++. The game utilizes a 1D array to map out hidden snakes and ladders across a 100-square board, demonstrating core programming concepts like arrays, loops, conditional logic, and Object-Oriented Programming (OOP).

🚀 Features

👥 2-Player Local Multiplayer (Player 1 vs Player 2)
🎲 Randomized Dice Rolls using C++ `<cstdlib>` and `<ctime>` libraries
🐍 Built-in Traps and Boosts (Snakes drop you down, Ladders boost you up!)
📌 Dynamic Status Updates showing player positions after every roll
🏆 Automatic Win detection (Must roll exact number to hit 100)
🔄 "Play Again" feature with automatic board reset

🛠️ Technologies Used

C++ (Object-Oriented Programming)

📂 Project Structure

snake-and-ladder-cpp/
│
├── main.cpp             # Main source code containing the SnakeAndLadder class
├── README.md            # Project documentation

▶️ How to Run

Download or clone the repository
Open the project folder
Compile the code using a C++ compiler (e.g., `g++ main.cpp -o snakeladder`)
Run the executable file (`./snakeladder` or `snakeladder.exe`)

🧠 Concepts Used

Object-Oriented Programming (Classes, Methods, Encapsulation)
1D Arrays (`int board[101]` to map out the 100 squares)
Pass-by-Reference (`int &currentPos` to cleanly update player positions)
Random Number Generation (`srand` and `rand()`)
Game Loops & Input Buffer Management (`cin.get()` and `cin.ignore()`)

📌 Note

Press `ENTER` when prompted to roll the dice. The game will automatically calculate your new position and trigger any snakes or ladders you land on!

🎯 Future Improvements

🤖 Add a Single-Player mode against an AI opponent
🎲 Add ASCII art for the dice rolls
🎨 Implement a visual 10x10 grid display for the board

👨‍💻 Author

Avnish Singh
