//import library sesuai kebutuhan
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#if defined(_WIN32) || defined(_WIN64) 
#include <conio.h>
#else 
#include <termios.h>
//getch() alternatif untuk linux
//sumber = https://gist.github.com/ninovsnino/f910701ea912f03b73a1d0895d213b0e
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo){
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

void resetTermios(void) {
tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo){
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
char getch(void) 
{
  return getch_(0);
}
#endif

//USER INTERFACE
void clearScreen(){
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #else
    system("clear");
    #endif
}
//kontrol dimasukin ke fungsi biar bisa dipake ulang
int navControls(int *selection, int Options) {
    while(1){
    char key = getch();
     if(key == 'w' || key == 'W') {
            if(*selection > 0) {
                (*selection)--;
            }
        } else if(key == 's' || key == 'S') {
            if(*selection < Options - 1) {
                (*selection)++;
            }
        } else if(key == '\n') {
            break;
        }
    }
}

//matiin cursor
void disableCursor() {
     printf("\033[?25l");
}
//main menu
void mainMenu(int *menuSelection){
    clearScreen();
    printf("/$$$$$$$$ /$$$$$$  /$$$$$$        /$$$$$$$$ /$$$$$$   /$$$$$$        /$$$$$$$$ /$$$$$$  /$$$$$$$$\n");
    printf("|__  $$__/|_  $$_/ /$$__  $$      |__  $$__//$$__  $$ /$$__  $$      |__  $$__//$$__  $$| $$_____/ \n");
    printf("   | $$     | $$  | $$  \\__/         | $$  | $$  \\ $$| $$  \\__/         | $$  | $$  \\ $$| $$      \n");
    printf("   | $$     | $$  | $$               | $$  | $$$$$$$$| $$               | $$  | $$  | $$| $$$$$   \n");
    printf("   | $$     | $$  | $$               | $$  | $$__  $$| $$               | $$  | $$  | $$| $$__/   \n");
    printf("   | $$     | $$  | $$    $$         | $$  | $$  | $$| $$    $$         | $$  | $$  | $$| $$      \n");
    printf("   | $$    /$$$$$$|  $$$$$$/         | $$  | $$  | $$|  $$$$$$/         | $$  |  $$$$$$/| $$$$$$$$\n");
    printf("   |__/   |______/ \\______/          |__/  |__/  |__/ \\______/          |__/   \\______/ |________/ \n");
    puts("group nasi daun ayam geprek");
    puts("note: mohon menggunakan program ini dalam full screen");
    puts("selamat datang di permainan tic tac toe pilih salah satu opsi:");
    printf("\033[0;33mHINT: GUNAKAN W UNTUK SELEKSI KEATAS DAN S UNTUK SELEKSI KEBAWAH\n\033[0m");
    if (*menuSelection == 0) {
        printf("\033[0;32mmulai permainan\033[0m \nkeluar dari game \nLeaderboard");
    }
    else if(*menuSelection == 1) {
         printf("mulai permainan\033[0;32m \nkeluar dari game \033[0m \nLeaderboard");
        }
        else if(*menuSelection == 2) {
            printf("mulai permainan \nkeluar dari game \033[0;32m\nLeaderboard\033[0m");
        }
}
//menu difficulty
void difficultyMenu(int *diffSelection) {
    clearScreen();
    printf(" __       __   ______   _______   ________        _______   ________  _______   __       __   ______   ______  __    __   ______   __    __ \n");
    printf("/  \\     /  | /      \\ /       \\ /        |      /       \\ /        |/       \\ /  \\     /  | /      \\ /      |/  \\  /  | /      \\ /  \\  /  | \n");
    printf("$$  \\   /$$ |/$$$$$$  |$$$$$$$  |$$$$$$$$/       $$$$$$$  |$$$$$$$$/ $$$$$$$  |$$  \\   /$$ |/$$$$$$  |$$$$$$/ $$  \\ $$ |/$$$$$$  |$$  \\ $$ | \n");
    printf("$$$  \\ /$$$ |$$ |  $$ |$$ |  $$ |$$ |__          $$ |__$$ |$$ |__    $$ |__$$ |$$$  \\ /$$$ |$$ |__$$ |  $$ |  $$$  \\$$ |$$ |__$$ |$$$  \\$$ | \n");
    printf("$$$$  /$$$$ |$$ |  $$ |$$ |  $$ |$$    |         $$    $$/ $$    |   $$    $$< $$$$  /$$$$ |$$    $$ |  $$ |  $$$$  $$ |$$    $$ |$$$$  $$ | \n");
    printf("$$ $$ $$/$$ |$$ |  $$ |$$ |  $$ |$$$$$/          $$$$$$$/  $$$$$/    $$$$$$$  |$$ $$ $$/$$ |$$$$$$$$ |  $$ |  $$ $$ $$ |$$$$$$$$ |$$ $$ $$ | \n");
    printf("$$ |$$$/ $$ |$$ \\__$$ |$$ |__$$ |$$ |_____       $$ |      $$ |_____ $$ |  $$ |$$ |$$$/ $$ |$$ |  $$ | _$$ |_ $$ |$$$$ |$$ |  $$ |$$ |$$$$ | \n");
    printf("$$ | $/  $$ |$$    $$/ $$    $$/ $$       |      $$ |      $$       |$$ |  $$ |$$ | $/  $$ |$$ |  $$ |/ $$   |$$ | $$$ |$$ |  $$ |$$ | $$$ | \n");
    printf("$$/      $$/  $$$$$$/  $$$$$$$/  $$$$$$$$/       $$/       $$$$$$$$/ $$/   $$/ $$/      $$/ $$/   $$/ $$$$$$/ $$/   $$/ $$/   $$/ $$/   $$/ \n");
       if (*diffSelection == 0) {
        printf("\033[0;32mmulai permainan\033[0m \nkeluar dari game \nlocal multiplayer \nbalik ke menu utama");
    }
    else if (*diffSelection == 1) {
        printf("mulai permainan \033[0;32m\nkeluar dari game\033[0m \nlocal multiplayer \nbalik ke menu utama");
    }
    else if (*diffSelection == 2) {
        printf("mulai permainan \nkeluar dari game \n033[0;32mlocal multiplayer \033[0m \nbalik ke menu utama");
    }
    else if (*diffSelection == 3) {
        printf("mulai permainan \nkeluar dari game \nlocal multiplayer  \nbalik ke menu utama \033[0m");
    }  
}
int leaderboardMenu(int *leadSelection) {
    printf("leaderboard in progress...");
    return 0;
}

void loadingScreen() {
    puts("LOADING");
    for (int i = 0; i <= 10; i++) {
        printf("\r[");
        
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        
        for (int j = i; j < 10; j++) {
            printf(" ");
        }
        
        printf("]");
        
        fflush(stdout);
        

        usleep(50000);  
    }
}

int main() {
    //declare variable disini
    int valueWhileLoop = 1, menuSelection = 0, diffSelection = 0, leadSelection = 0;
    system("stty -echo");//buat linux
    while(valueWhileLoop){
    mainMenu(&menuSelection);
    disableCursor();
    navControls(&menuSelection, 3);
    switch(menuSelection){
        case 0:
        clearScreen();
        loadingScreen();
        clearScreen();
        difficultyMenu(&diffSelection);
        valueWhileLoop = 1;
        navControls(&diffSelection, 4);
        break;
        case 1:
        clearScreen();
        puts("terima kasih telah memainkan game kami :)");
        sleep(2);
        valueWhileLoop = 0;
        break;
        case 2: 
        clearScreen();
        loadingScreen();
        clearScreen();
        leaderboardMenu(&leadSelection);
        break;
        default:
        break;
        }
    }  
    return 0;
}

//KOMPONEN GAME
char arr[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void resetBoard() {
	int x;
    for (x = 1; x <= 9; x++) {
        arr[x] = '0' + x;
    }
}
void showboard() {
    printf("\t TIC TAC TOE\n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[1], arr[2], arr[3]);
    printf("-------|-------|-------\n");
    printf("   %c   |   %c   |   %c   \n", arr[4], arr[5], arr[6]);
    printf("-------|-------|-------\n");
    printf("   %c   |   %c   |   %c   \n", arr[7], arr[8], arr[9]);
    printf("       |       |      \n");
}

int checkForWin() {
    if (arr[1] == arr[2] && arr[2] == arr[3]) return 1;
    if (arr[4] == arr[5] && arr[5] == arr[6]) return 1;
    if (arr[7] == arr[8] && arr[8] == arr[9]) return 1;
    if (arr[1] == arr[4] && arr[4] == arr[7]) return 1;
    if (arr[2] == arr[5] && arr[5] == arr[8]) return 1;
    if (arr[3] == arr[6] && arr[6] == arr[9]) return 1;
    if (arr[1] == arr[5] && arr[5] == arr[9]) return 1;
    if (arr[3] == arr[5] && arr[5] == arr[7]) return 1;
	int i;
    for (i = 1; i <= 9; i++) {
        if (arr[i] == '0' + i) return -1; // Game lanjutt
    }
    return 0; // seri
}

int minimax(int depth, int isMaximizing) {
    int score = checkForWin();
    if (score == 1) return isMaximizing ? -10 + depth : 10 - depth;
    if (score == 0) return 0;

    int bestScore = isMaximizing ? -1000 : 1000;
    char mark = isMaximizing ? 'O' : 'X';
	int i;
    for (i = 1; i <= 9; i++) {
        if (arr[i] == '0' + i) {
            arr[i] = mark;
            int currentScore = minimax(depth + 1, !isMaximizing);
            arr[i] = '0' + i;
            bestScore = isMaximizing
                        ? (currentScore > bestScore ? currentScore : bestScore)
                        : (currentScore < bestScore ? currentScore : bestScore);
        }
    }
    return bestScore;
}

int getBestMove() {
    int bestMove = -1;
    int bestScore = -1000;
	int i;
    for (i = 1; i <= 9; i++) {
        if (arr[i] == '0' + i) {
            arr[i] = 'O'; // karakter untuk botnya
            int moveScore = minimax(0, 0);
            arr[i] = '0' + i;
            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

void botTurn(int difficulty) {
    if (difficulty == -1) { // Easy difficulty
        int move;
        do {
            move = rand() % 9 + 1; // Random number between 1 and 9
        } while (arr[move] != '0' + move); // Ensure the move is valid
        arr[move] = 'O';
    } else { // Hard difficulty
        int move = getBestMove();
        arr[move] = 'O';
    }
}

void playerTurn(int player) {
    int choice;
    char mark = player == 1 ? 'X' : 'O';
    printf("Player %d turn: ", player);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 9 && arr[choice] == '0' + choice) {
        arr[choice] = mark;
    } else {
        printf("Invalid move! Try again.\n");
        playerTurn(player);
    }
}

int game(int botDifficulty) {
    resetBoard();
    int player = 1, result;

    do {
        showboard();
        if (botDifficulty != 0 && player == 2) {
            printf("Bot is thinking...\n");
            sleep(1);
            botTurn(botDifficulty);
        } else {
            playerTurn(player);
        }

        result = checkForWin();
        player = (player % 2) + 1;
    } while (result == -1);

    showboard();
    if (result == 1) {
        printf("Player %d wins!\n", (player % 2) + 1);
    } else {
        printf("Game draw!\n");
    }
    return 0;
}