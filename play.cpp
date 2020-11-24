// #include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
std::string const asciiTest = R"~(
    $$$$$$\   $$$$$$\  $$\   $$\  $$$$$$\
   $$  __$$\ $$$ __$$\ $$ |  $$ |$$  __$$\
   \__/  $$ |$$$$\ $$ |$$ |  $$ |$$ /  $$ |
    $$$$$$  |$$\$$\$$ |$$$$$$$$ | $$$$$$  |
   $$  ____/ $$ \$$$$ |\_____$$ |$$  __$$<
   $$ |      $$ |\$$$ |      $$ |$$ /  $$ |
   $$$$$$$$\ \$$$$$$  /      $$ |\$$$$$$  |
   \________| \______/       \__| \______/
)~";

//To print the grid as it is
void printGrid(int g[]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(g[(4*i)+j]!=0)
                cout << g[(4*i)+j] << "\t";
            else
                cout << "*\t";
        }
        cout << endl;
    }
    cout << endl;
}

int sumCells(int g[]){
    int sum = 0;
    for(int i=0; i<16; i++){
        sum = sum+g[i];
    }
    return sum;
}
//To initialize random cells as starting cells
void start(int g[]){
    cout << asciiTest<<endl;
    cout << "\nWelcome to the game!\n";
    cout << "\nControls are as follows:\nw : Move up\nd : Move right\na : Move left\ns : Move down\nend : Exit\n";
    cout << "\n\nHere is your starting Grid!\n\n";
    srand(time(0));
    int pos1 = rand() % 16;
    int pos2 = rand() % 16;
    while(pos1==pos2){
        pos2 = rand() % 16;
    }
    g[pos1] = 2;
    g[pos2] = 2;
    printGrid(g);
}

int shift_up_all(int g[]){
    int ret_val = 0;
    while(1){
        int moves = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<4; j++){
                if(g[4*i+j]!=0){
                    continue;
                }
                else{
                    if(g[4*i+j+4]!=0){
                        g[4*i+j] = g[4*i+j+4];
                        g[4*i+j+4] = 0;
                        moves++;
                        ret_val++;
                    }
                }
            }
        }
        if(moves==0)
            break;
    }
    return ret_val;
}

int move_up(int g[]){
    int ret_val = 0;
    ret_val += shift_up_all(g);
    int modified[16] = {0};
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(modified[(4*i)+j]==0 && modified[(4*i)+j+4]==0){
                if(g[(4*i)+j]==g[(4*i)+j+4] && g[(4*i)+j]!=0){
                    modified[(4*i)+j]++;
                    modified[(4*i)+j+4]++;
                    g[(4*i)+j] = 2*g[(4*i)+j];
                    g[(4*i)+j+4] = 0;
                    ret_val++;
                }
            }
        }
    }
    ret_val += shift_up_all(g);
    return ret_val;
    // printGrid(g);
}

int shift_down_all(int g[]){
    int ret_val = 0;
    while(1){
        int moves = 0;
        for(int i=3; i>0; i--){
            for(int j=0; j<4; j++){
                if(g[4*i+j]!=0){
                    continue;
                }
                else {
                    if(g[4*i+j-4]!=0){
                        g[4*i+j] = g[4*i+j-4];
                        g[4*i+j-4] = 0;
                        moves++;
                        ret_val++;
                    }
                }
            }
        }
        if(moves==0)
            break;
    }
    return ret_val;
}

int move_down(int g[]){
    int ret_val = 0;
    ret_val+=shift_down_all(g);
    int modified[16] = {0};
    for(int i=3; i>0; i--){
        for(int j=0; j<4; j++){
            if(modified[(4*i)+j]==0 && modified[(4*i)+j-4]==0){
                if(g[(4*i)+j]==g[(4*i)+j-4] && g[(4*i)+j]!=0){
                    modified[(4*i)+j]++;
                    modified[(4*i)+j-4]++;
                    g[(4*i)+j] = 2*g[(4*i)+j];
                    g[(4*i)+j-4] = 0;
                    ret_val++;
                }
            }
        }
    }
    ret_val+=shift_down_all(g);
    return ret_val;
    // printGrid(g);
}

int shift_right_all(int g[]){
    int ret_val = 0;
    while(1){
        int moves = 0;
        for(int i=0; i<4; i++){
            for(int j=3; j>0; j--){
                if(g[4*i+j]!=0){
                    continue;
                }
                else {
                    if(g[4*i+j-1]!=0){
                        g[4*i+j] = g[4*i+j-1];
                        g[4*i+j-1] = 0;
                        moves++;
                        ret_val++;
                    }
                }
            }
        }
        if(moves==0)
            break;
    }
    return ret_val;
}

int move_right(int g[]){
    int ret_val = 0;
    ret_val+=shift_right_all(g);
    int modified[16] = {0};
    for(int i=0; i<4; i++){
        for(int j=3; j>0; j--){
            if(modified[(4*i)+j]==0 && modified[(4*i)+j-1]==0){
                if(g[(4*i)+j]==g[(4*i)+j-1] && g[(4*i)+j]!=0){
                    modified[(4*i)+j]++;
                    modified[(4*i)+j-1]++;
                    g[(4*i)+j] = 2*g[(4*i)+j];
                    g[(4*i)+j-1] = 0;
                    ret_val++;
                }
            }
        }
    }
    ret_val+=shift_right_all(g);
    return ret_val;
    // printGrid(g);
}

int shift_left_all(int g[]){
    int ret_val = 0;
    while(1){
        int moves = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(g[4*i+j]!=0){
                    continue;
                }
                else {
                    if(g[4*i+j+1]!=0){
                        g[4*i+j] = g[4*i+j+1];
                        g[4*i+j+1] = 0;
                        moves++;
                        ret_val++;
                    }
                }
            }
        }
        if(moves==0)
            break;
    }
    return ret_val;
}

int move_left(int g[]){
    int ret_val = 0;
    ret_val+=shift_left_all(g);
    //modified keeps track of whether an operation has been performed on cell
    int modified[16] = {0};
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            if(modified[(4*i)+j]==0 && modified[(4*i)+j+1]==0){
                if(g[(4*i)+j]==g[(4*i)+j+1] && g[(4*i)+j]!=0){
                    modified[(4*i)+j]++;
                    modified[(4*i)+j+1]++;
                    g[(4*i)+j] = 2*g[(4*i)+j];
                    g[(4*i)+j+1] = 0;
                    ret_val++;
                }
            }
        }
    }
    ret_val+=shift_left_all(g);
    return ret_val;
    // printGrid(g);
}

void insertRandom(int g[]){
    while(1){
        int nn = rand() % 16;
        int luck = rand() % 100;
        if(g[nn]==0){
            if(luck<90)
                g[nn] = 2;
            else
                g[nn] = 4;
            break;
        }
    }
}

int main(){
    int g[16] = {  };   //Actual playfield
    // printGrid(g);
    start(g);
    int moves = 0;
    string next_move;
    int score = 0;
    // string next_move;
     while(1){
        cout << "Please enter your next move: ";
        cin >> next_move;
        cout << endl;
        int gg;
        if(next_move=="end"){
            cout << "And that is the game! \nFinal Grid is:\n";
            printGrid(g);
            cout << "Your Final Score: " << score << endl;
            cout << "\nThanks for playing!\nPlease send feedback :)\n";
            cout << "Exiting in 5 seconds.\n";
            Sleep(5000);
            break;
        }
        else if(next_move=="w"){
            gg = move_up(g);
            // cout << "Move up operation took " << gg << " number of moves"<<endl;
        }
        else if(next_move=="s"){
            gg = move_down(g);
            // cout << "Move up operation took " << gg << " number of moves"<<endl;
        }
        else if(next_move=="d"){
            gg = move_right(g);
            // cout << "Move up operation took " << gg << " number of moves"<<endl;
        }
        else if(next_move=="a"){
            gg = move_left(g);
            // cout << "Move up operation took " << gg << " number of moves"<<endl;
        }
        else{
            cout << "\nEnter a valid move. Valid moves are 'w', 'a', 's', 'd' or 'end'\n";
            continue;
        }

        if(gg==0){
            int occupied_cells=0;
            for(int i=0; i<16; i++){
                if(g[i]!=0)
                    occupied_cells++;
            }
            if(occupied_cells==16){
                int copy_g_1[16];
                int copy_g_2[16];
                for(int i=0; i<16; i++){
                    copy_g_1[i] = g[i];
                    copy_g_2[i] = g[i];
                }
                if(move_up(copy_g_1)==0 && move_right(copy_g_2)==0){
                    cout << "No more moves possible! \nFinal Grid is:\n";
                    printGrid(g);
                    cout << "Your Final Score: " << score << endl;
                    cout << "\nThanks for playing!\nPlease send feedback :)\n";
                    cout << "Exiting in 5 seconds.\n";
                    Sleep(5000);
                    break;
                }
            }
            cout << "Move not possible. Choose another move.\n";
        }
        else{
            insertRandom(g);
            moves++;
            score = sumCells(g);
            cout << "You are done with " << moves << " moves!\n\n";
        }
        printGrid(g);
        cout << "Your score is: " << score<<"\n\n";
    }
    return 0;
}
