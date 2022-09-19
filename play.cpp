#include <iostream>

std::string board[9] =  {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int player = 0;

void Introduction(){

    std::cout << "Press [Enter] to begin";
    std::cin.ignore();

    std::cout  << "\n";

    std::cout << "=======================  \n";
    std::cout << "Tic-Tac-Toe \n"
    std::cout << "======================= \n\n"

    std::cout << "Player 1 is O \n";
    std::cout << "Player 2 is X \n\n";

    std::cout << "Here is the 3X3 grid for you to play \n\n";

    std::cout << "     |     |     \n";
    std::cout << "  1  |  2  |  3  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  4  |  5  |  6  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  7  |  8  |  9  \n";
    std::cout << "     |     |     \n\n";

    
}

bool is_Winner(){

    bool winner = false;

    //rows
    if((board[0] == board[1])  && (board[1] == board[2]) && (board[0] != " ")){
        winner = true;
    }elseif((board[3] == board[4]) && (board[4] == board[5]) && (board[3] != " ")){
        winner = true;
    }elseif((board[6] ==  board[7]) && (board[7] == board[8]) && (board[6] != " ")){
        winner = true;
    }

    //column
    if((board[0] == board[3]) && (board[3] == board[6]) && (board[0] != " ")){
        winner =  true;
    }elseif((board[1] == board[4]) && (board[4] == board[5]) && (board[1] != " ")){
        winner =true;
    }elseif((board[2]  == board[5]) && (board[5] == board[8]) && (board[2] != " ")){
        winner = true;
    }

    //diagonal
    if((board[0] == board[4]) && (board[4] == board[8]) && (board[0] != " ")){
        winner = true;
    }elseif((board[2] == board[4]) && (board[4] ==  board[6]) && (board[2] != " ")){
        winner = true;
    }

    return winner;
}

bool filled_up() {

    bool filled = true;

    for(int i = 0; i < 9; i++){
        if( board [i] ==  " "){

            filled = false;
        }
    }

    return filled;
}

void draw(){

    std::cout << "     |     |     \n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
    std::cout << "_____|_____|_____\n"; 
    std::cout << "     |     |     \n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
    std::cout << "     |     |     \n";
}

void set_position(){

    std::cout << "Player " << player << "'s turn. Please choose a number between (1-9): ";
    
    while(!(std::cin >> position)){

        std::cout<< "Player " << player << ". Please enter a valid number between 1 - 9 : ";
        std::cin.clear();
        std::cin.ignore();

    }

    std::cout << "\n";

    while(board[position - 1] != " "){
        std::cout << "Oops! Looks like there is already something there. Please choose another position \n\n";
        std::cout << "Player "<< player <<"'s turn. Pick a number: ";
        std::cin >> position;
        std::cout << "\n";
    }

}

void update_board(){

    if(player % 2 == 1){
        board[position-1]  = "X";
    }else{
        board[position-1] = "O";
    }
}

void change_player(){

    if(player == 1){
        player ++;
    }else{
        player --;
    }
}

void take_turn(){
    while (!is_Winner() && !filled_up()){
        set_position();
        update_board();
        draw();
        change_player();
    }
}

void end_game(){
    if(is_Winner()){
        std::cout << "Yeay!!  We have a winner!!!\n";
    }
    if(filled_up()){
        std::cout << "It is a tie!!!\n";
    }
}

