//import library sesuai kebutuhan
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void clearScreen();
void loadingScreen(void);
int gamemode();
int difficultyMenu();
int game(int difficulty);
//USER INTERFACE versi simple buat ngejar deadline
void clearScreen(){
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #else
    system("clear");
    #endif
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
int difficultyMenu(){
    int choice;
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
    puts("1. mudah");
    puts("2. susah");
    puts("3. balik ke menu mode");
    printf("ketik nomor di pilihan: ");
       scanf("%d", &choice);
    switch (choice){
    case 1:
        clearScreen();
        loadingScreen();
        clearScreen();
        game(-1);
        break;
    case 2:
        clearScreen();
        loadingScreen();
        clearScreen();
        game(1);
        break;
    case 3:
        return 0;
        break;
    default:
        puts("pilihan tidak ada");
    }

}
//menu difficulty
int gamemode() {
    int choice, valueWhileLoop = 1;
    while(valueWhileLoop){
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
        puts("1. lawan BOT");
        puts("2. local multiplayer");
        puts("3. kembali ke menu utama");
        printf("ketik nomor di pilihan: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            clearScreen();
            loadingScreen();
            clearScreen();
            difficultyMenu();
            break;
        case 2:
            clearScreen();
            loadingScreen();
            game(0);
            break;
        case 3:
        clearScreen();
        loadingScreen();
        clearScreen();
            return 0;
            break;
        default:
            puts("pilihan tidak ada");
        }
    }
}



int main() {
    int valueWhileLoop = 1, choice;
    while(valueWhileLoop){
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
        puts("1. mulai permainan");
        puts("2. leaderboard");
        puts("3. keluar dari game");    
        printf("ketik nomor di pilihan: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            clearScreen();
            loadingScreen();
            gamemode();
            break;
        case 2:
            clearScreen();
            puts("UNDERCONTRUCTION :( SORRY");
            sleep(2);
            break;
        case 3:
        clearScreen();
            puts("terima kasih telah memainkan game kami :)");
            valueWhileLoop = 0;
            sleep(2);
            break;
        default:
            puts("pilihan tidak ada");
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
            clearScreen();
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
        sleep(2);
        main();
    } else {
        printf("Game draw!\n");
        sleep(2);
        main();
    }
    return 0;
}