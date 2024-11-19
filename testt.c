#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
        if (arr[i] == '0' + i) return -1; // Game ongoing
    }
    return 0; // Draw
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
            arr[i] = 'O'; // Bot's mark
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

void botTurn() {
    int move = getBestMove();
    arr[move] = 'O';
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

int game(int bot) {
    resetBoard();
    int player = 1, result;

    do {
        showboard();
        if (bot && player == 2) {
            printf("Bot is thinking...\n");
            sleep(1);
            botTurn();
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

int difficultyMenu() {
    int choice;
    system("cls"); // Windows
    system("clear"); // Linux
    puts("1) Awam (2 Players)");
    puts("2) PROMASTER69420 (vs Bot)");
    puts("3) Back to Main Menu");
    printf("Choose difficulty: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        game(0);
        break;
    case 2:
        game(1);
        break;
    case 3:
        return 0;
    default:
        printf("Invalid choice!\n");
        break;
    }
    return 0;
}

int main() {
    int running = 1, choice;

    while (running) {
        puts("Welcome to Tic Tac Toe!");
        puts("1) Play");
        puts("2) Quit");
        printf("What would you like to do? ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            difficultyMenu();
            break;
        case 2:
            running = 0;
            puts("Thanks for playing!");
            break;
        default:
            puts("Invalid choice!");
            break;
        }
    }
    return 0;
}

