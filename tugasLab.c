//import library sesuai kebutuhan
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef _WIN32
#include <conio.h>
#endif
void systemClear(){
    #if _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
char arr[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void resetBoard() {
	int x;
    for (x = 1; x <= 9; x++) {
        arr[x] = '0' + x;
    }
}

void showboard(){
	printf("\t TIC TAC TOE\n");
	printf("       |       |      \n");
    printf("       |       |      \n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[1], arr[2], arr[3]);
    printf("-------|-------|-------\n");
    printf("       |       |      \n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[4], arr[5], arr[6]);
    printf("       |       |      \n");
    printf("       |       |      \n");
    printf("-------|-------|-------\n");
    printf("       |       |      \n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[7], arr[8], arr[9]);
    printf("       |       |      \n");
    printf("       |       |      \n");	
}

int checkForWin()
{
    if (arr[1] == arr[2] && arr[2] == arr[3])
        return 1;
    else if (arr[4] == arr[5] && arr[5] == arr[6])
        return 1;
    else if (arr[7] == arr[8] && arr[8] == arr[9])
        return 1;
    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;
    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;
    else if (arr[3] == arr[6] && arr[6] == arr[9])
        return 1;
    else if (arr[3] == arr[6] && arr[6] == arr[9])
        return 1;
    else if (arr[1] == arr[5] && arr[5] == arr[9])
        return 1;
    else if (arr[3] == arr[5] && arr[5] == arr[7])
        return 1;
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7] != '7' && arr[8] != '8' && arr[9] != '9')
        return 0;

    else
        return -1;
    }

int game(){
	resetBoard();
	int player = 0;
    int choice, i;
    char mark;
   	do{	   
    	showboard();
    	player++;
    	player = (player % 2) ? 1 : 2;
        printf("Player %d turn :", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && arr[1] == '1')
            arr[1] = mark;
        else if (choice == 2 && arr[2] == '2')
            arr[2] = mark;
        else if (choice == 3 && arr[3] == '3')
            arr[3] = mark;
        else if (choice == 4 && arr[4] == '4')
            arr[4] = mark;
        else if (choice == 5 && arr[5] == '5')
            arr[5] = mark;
        else if (choice == 6 && arr[6] == '6')
            arr[6] = mark;
        else if (choice == 7 && arr[7] == '7')
            arr[7] = mark;
        else if (choice == 8 && arr[8] == '8')
            arr[8] = mark;
        else if (choice == 9 && arr[9] == '9')
            arr[9] = mark;

        else
        {
            printf("Invalid value\n");
            player--;
            getch();
        }

        i = checkForWin();
	}while (i == -1);
	showboard();
    if (i == 1)
    {
        printf("Player %d Won\n", player);
    }
    else
    {
        printf("Game Draw\n");
    }
	
    getch();
    return 0;
}

//cek compile di os mana
int getKey() {
    #if _WIN32
    return getch();
    #else
    return getchar();
    #endif
}
//matiin cursor
void disableCursor() {
     printf("\033[?25l");
}
//main menu
int mainMenu(int selection){
    systemClear();
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
    if (selection == 0) {
        printf("\033[0;32mmulai permainan\033[0m \nkeluar dari game");
    }
    else {
         printf("mulai permainan\033[0;32m \nkeluar dari game \033[0m");
    }
}
void clearScreen() {
}
//menu difficulty
int difficultyMenu(int selection) {
    int selection = 0;
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
       if (selection == 0) {
        printf("\033[0;32mmulai permainan\033[0m \nkeluar dari game \n local multiplayer");
    }
    else {
         printf("mulai permainan\033[0;32m \nkeluar dari game \033[0m");
    }
    s
    
}

int main() {
    //declare variable disini
    int valueWhileLoop = 1, choice, selection = 0;
    char key;
    system("stty -echo");//buat linux
    while(valueWhileLoop){
    mainMenu(selection);
    disableCursor();
    key = getKey();
    if(key == 'w' || key == 'W') {
        if(selection > 0) {
            selection--;
        }
    }   else if(key == 's' || key == 'S'){
            if(selection < 1) {
                selection++;
            }
            else if(key == '\n'){
                break;
            }
        }

    }
                switch(selection){
                case 0:
                systemClear();
                puts("loading.....");
                sleep(2);
                difficultyMenu();
                break;
                case 1:
                systemClear();
                puts("terima kasih telah memainkan game kami :)");
                sleep(2);
                break;
                }

    return 0;
}