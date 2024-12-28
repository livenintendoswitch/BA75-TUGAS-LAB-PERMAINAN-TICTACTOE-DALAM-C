//import library sesuai kebutuhan
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#if _WIN32 || _WIN64
#include <conio.h>
#else
#include <termios.h>
//dari https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}
#endif

char getKeyboard() {
     #if _WIN32 |_WIN64
    return getch();
    #else
    return getch();
    #endif 
}

void clearScreen() {
    #if _WIN32 || _WIN64
    system("cls");
    #else
    system("clear");
    #endif
}
//kontrol dimasukin ke fungsi biar bisa dipake ulang
int NavKey(char key, int selection, int options){
    if (key == 'W' || key == 'w') {
        selection--;
    } else if (key == 'S' || key == 's') {
        selection++;
    } else if (key == ' ') {
        return -1; 
    }

    if (selection < 0) {
        selection = 0;
    } else if (selection >= options) {
        selection = options - 1;
    }

    return selection;
}

//matiin cursor
void disableCursor() {
     printf("\033[?25l");
}
void enableCursor() {
    printf("\033[?25h");
}
//main menu
void mainMenu(int mainMenuSelection){
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
    printf("\033[0;33mHINT: gunakan W dan S untuk seleksi dan spasi untuk memilih\n\033[0m");
    printf("%smulai permainan%s\n", mainMenuSelection == 0 ? "\033[0;32m" : "", mainMenuSelection == 0 ? " <-\033[0m" : "");
    printf("%sleaderboard%s\n", mainMenuSelection == 1 ? "\033[0;32m" : "", mainMenuSelection == 1 ? " <-\033[0m" : "");
    printf("%skeluar dari game%s\n", mainMenuSelection == 2 ? "\033[0;32m" : "", mainMenuSelection == 2 ? " <-\033[0m" : "");
}
//menu mode
void gameModeMenu(int modeSelection) {
        printf(" __       __   ______   _______   ________        _______   ________  _______   __       __   ______   ______  __    __   ______   __    __ \n");
        printf("/  \\     /  | /      \\ /       \\ /        |      /       \\ /        |/       \\ /  \\     /  | /      \\ /      |/  \\  /  | /      \\ /  \\  /  | \n");
        printf("$$  \\   /$$ |/$$$$$$  |$$$$$$$  |$$$$$$$$/       $$$$$$$  |$$$$$$$$/ $$$$$$$  |$$  \\   /$$ |/$$$$$$  |$$$$$$/ $$  \\ $$ |/$$$$$$  |$$  \\ $$ | \n");
        printf("$$$  \\ /$$$ |$$ |  $$ |$$ |  $$ |$$ |__          $$ |__$$ |$$ |__    $$ |__$$ |$$$  \\ /$$$ |$$ |__$$ |  $$ |  $$$  \\$$ |$$ |__$$ |$$$  \\$$ | \n");
        printf("$$$$  /$$$$ |$$ |  $$ |$$ |  $$ |$$    |         $$    $$/ $$    |   $$    $$< $$$$  /$$$$ |$$    $$ |  $$ |  $$$$  $$ |$$    $$ |$$$$  $$ | \n");
        printf("$$ $$ $$/$$ |$$ |  $$ |$$ |  $$ |$$$$$/          $$$$$$$/  $$$$$/    $$$$$$$  |$$ $$ $$/$$ |$$$$$$$$ |  $$ |  $$ $$ $$ |$$$$$$$$ |$$ $$ $$ | \n");
        printf("$$ |$$$/ $$ |$$ \\__$$ |$$ |__$$ |$$ |_____       $$ |      $$ |_____ $$ |  $$ |$$ |$$$/ $$ |$$ |  $$ | _$$ |_ $$ |$$$$ |$$ |  $$ |$$ |$$$$ | \n");
        printf("$$ | $/  $$ |$$    $$/ $$    $$/ $$       |      $$ |      $$       |$$ |  $$ |$$ | $/  $$ |$$ |  $$ |/ $$   |$$ | $$$ |$$ |  $$ |$$ | $$$ | \n");
        printf("$$/      $$/  $$$$$$/  $$$$$$$/  $$$$$$$$/       $$/       $$$$$$$$/ $$/   $$/ $$/      $$/ $$/   $$/ $$$$$$/ $$/   $$/ $$/   $$/ $$/   $$/ \n");
        printf("%smulai permainan%s\n", modeSelection == 0 ? "\033[0;32m" : "", modeSelection == 0 ? " <-\033[0m" : "");
        printf("%slocal multiplayer %s\n", modeSelection == 1 ? "\033[0;32m" : "", modeSelection == 1 ? " <-\033[0m" : "");
        printf("%skembali ke menu utama%s\n", modeSelection == 2 ? "\033[0;32m" : "", modeSelection == 2 ? " <-\033[0m" : "");
}

void difficultyMenu(int diffselection){
    printf("                         __                                                    __                    __     \n");
    printf("                        /  |                                                  /  |                  /  |    \n");
    printf(" _____  ____    ______  $$ |  ______   __   __   __   ______   _______        $$ |____    ______   _$$ |_   \n");
    printf("/     \\/    \\  /      \\ $$ | /      \\ /  | /  | /  | /      \\ /       \\       $$      \\  /      \\ / $$   |  \n");
    printf("$$$$$$ $$$$  |/$$$$$$  |$$ | $$$$$$  |$$ | $$ | $$ | $$$$$$  |$$$$$$$  |      $$$$$$$  |/$$$$$$  |$$$$$$/   \n");
    printf("$$ | $$ | $$ |$$    $$ |$$ | /    $$ |$$ | $$ | $$ | /    $$ |$$ |  $$ |      $$ |  $$ |$$ |  $$ |  $$ | __ \n");
    printf("$$ | $$ | $$ |$$$$$$$$/ $$ |/$$$$$$$ |$$ \\_$$ \\_$$ |/$$$$$$$ |$$ |  $$ |      $$ |__$$ |$$ \\__$$ |  $$ |/  |\n");
    printf("$$ | $$ | $$ |$$       |$$ |$$    $$ |$$   $$   $$/ $$    $$ |$$ |  $$ |      $$    $$/ $$    $$/   $$  $$/ \n");
    printf("$$/  $$/  $$/  $$$$$$$/ $$/  $$$$$$$/  $$$$$/$$$$/   $$$$$$$/ $$/   $$/       $$$$$$$/   $$$$$$/     $$$$/  \n");
    puts("pilih level kesusahan lawan bot");
    printf("%smudah%s\n", diffselection == 0 ? "\033[0;32m" : "", diffselection == 0 ? " <-\033[0m" : "");
    printf("%ssusah%s\n", diffselection == 1 ? "\033[0;32m" : "", diffselection == 1 ? " <-\033[0m" : "");
    printf("%skembali ke menu mode permainan%s\n", diffselection == 2 ? "\033[0;32m" : "", diffselection == 2 ? " <-\033[0m" : "");
}

typedef struct {
    char name[100];
    int points;
} Player;

void selectionSortDescending(Player players[], int numPlayers) {
    int i,j;
    for (i = 0; i < numPlayers - 1; i++) {
        int maxIndex = i;
        for (j = i + 1; j < numPlayers; j++) {
            if (players[j].points > players[maxIndex].points) {
                maxIndex = j;
            }
        }
        
        if (maxIndex != i) {
            Player temp = players[i];
            players[i] = players[maxIndex];
            players[maxIndex] = temp;
        }
    }
}

void searchPlayer(Player players[], int numPlayers, const char *searchName) {
    int found = 0;
    int i;
    for (i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, searchName) == 0) {
            printf("pemain '%s' ditemukan dengan %d points.\n", players[i].name, players[i].points);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("pemain '%s' tidak ditemukan di leaderboard \n", searchName);
    }
}

void menuLeaderboard() {
    FILE *file = fopen("leaderboard.txt", "r");
    if (file == NULL) {
        printf("Error: file tidak ditemukan\n");
        return;
    }

    int numPlayers;
    fscanf(file, "%d", &numPlayers);

    Player players[numPlayers];
    int i;
    for (i = 0; i < numPlayers; i++) {
        fscanf(file, "%s %d", players[i].name, &players[i].points);
    }

    fclose(file);

    selectionSortDescending(players, numPlayers);

    int loopingMenu = 1;
    int Leadselection = 0; 
    while (loopingMenu) {
        clearScreen();

        printf("Leaderboard:\n");
        printf("Rank  pemain Name        Points\n");
        int i;
        for (i = 0; i < numPlayers; i++) {
            printf("%-5d %-18s %d\n", i + 1, players[i].name, players[i].points);
        }

        printf("\nOpsi:\n");
         printf("%smencari pemain%s\n", Leadselection == 0 ? "\033[0;32m" : "", Leadselection == 0 ? " <-\033[0m" : "");
        printf("%skembali ke menu%s\n", Leadselection == 1 ? "\033[0;32m" : "", Leadselection == 1 ? " <-\033[0m" : "");

        char key = getKeyboard(); 
        int result = NavKey(key, Leadselection, 2); 
        if (result == -1) { 
            if (Leadselection == 0) {
                clearScreen();
                enableCursor();
                char searchName[100];
                printf("\nMasukkan nama pemain yang dicari: ");
                scanf("%s", searchName);
                searchPlayer(players, numPlayers, searchName);
                sleep(5);
            } else if (Leadselection == 1) {
                loopingMenu = 0;
            }
            } else {
                 Leadselection = result; 
                }
    }

    
    
}

void loadingScreen() {
    puts("LOADING");
    int i,j;
    for (i = 0; i <= 10; i++) {
        printf("\r[");
        
        for (j = 0; j < i; j++) {
            printf("#");
        }
        
        for (j = i; j < 10; j++) {
            printf(" ");
        }
        
        printf("]");
        
        fflush(stdout);
        

        usleep(50000);  
    }
}

int game(int botDifficulty);

int main() {
    disableCursor();
    int valueWhileLoop = 1; 
    int mainMenuSelection = 0; 

    while (valueWhileLoop) {
        clearScreen();
        mainMenu(mainMenuSelection);
        char key = getKeyboard(); 
        int result = NavKey(key, mainMenuSelection, 3); 
        if (result == -1) {
            valueWhileLoop = 0; 
            break;
        }
        else{
        mainMenuSelection = result;
        }
    }
    switch (mainMenuSelection) {
        case 0: {
            int modeSelection = 0; 
            int loopingModeMenu = 1;  
            clearScreen();
            loadingScreen();
            clearScreen();
            while (loopingModeMenu) {
                clearScreen();
                gameModeMenu(modeSelection);
                char key = getKeyboard(); 
                int result = NavKey(key, modeSelection, 3); 
                if (result == -1) {
                    loopingModeMenu = 0; 
                }else{
                modeSelection = result;
                }
            }
                switch (modeSelection) {
                    case 0: {
                        clearScreen();
                        loadingScreen();
                        int diffSelection = 0; 
                        int loopingSelectBotDiff = 1;  
                        while (loopingSelectBotDiff) {
                            clearScreen();
                            difficultyMenu(diffSelection);
                            char key = getKeyboard(); 
                            int result = NavKey(key, diffSelection, 3); 
                            if (result == -1) {
                                loopingSelectBotDiff = 0; 
                            } else{
                            diffSelection = result;
                            }
                        }
                            switch(diffSelection){
                                case 0:
                                    clearScreen();
                                    loadingScreen();
                                    clearScreen();
                                    game(-1);
                                    break;
                                case 1:
                                    clearScreen();
                                    loadingScreen();
                                    clearScreen();
                                    enableCursor();
                                    game(1);
                                    break;
                                case 2:
                                    clearScreen();
                                    loadingScreen();
                                    clearScreen();
                                    loopingModeMenu = 1;
                                    break;
                                default:
                                puts("system failure");       
                                break;                         
                            }
                        break;
                    }
                    case 1: {
                        clearScreen();
                        loadingScreen();
                        clearScreen();
                        game(0);
                        break;
                    }
                    case 2: {
                        clearScreen();
                        loadingScreen();
                        clearScreen();
                        valueWhileLoop = 1;
                        printf("valueWhileLoop is set to = %d", valueWhileLoop);
                        sleep(3);
                        break;
                    }
                    default:
                        printf("System failure.\n");
                        break;
                }
                break;
            }
        case 1: {
            int loopingCaseLead = 1;  
            while (loopingCaseLead) {
                clearScreen();
                menuLeaderboard();
                loopingCaseLead = 0;
            }
        }
        case 2: {
            clearScreen();
            printf("Terima kasih telah memainkan game kami :)\n");
            break;
        }
        default:
            printf("Invalid selection.\n");
            break;
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