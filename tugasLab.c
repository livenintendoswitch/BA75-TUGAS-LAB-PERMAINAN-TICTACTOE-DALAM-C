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
int game(){
//masukin gamenya disini
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
int difficultyMenu() {
    int choice;
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
    puts("1) awam");
    puts("2) PROMASTER69420 (susah bro) ");
    puts("3) balik ke menu utama"); 
    printf("pilih skill lawan: ");
    scanf("%d", &choice);getchar();
    switch(choice)
    {
    case 1:
        game();
        break;
    case 2: 
        game();
        break;
    case 3: 
        system("cls");//buat windows
        system("clear");//buat linux
        puts("kembali ke menu utama");
        sleep(2);
        return 0;
        break;
    default:
        system("cls");//buat windows
        system("clear");//buat linux
        puts("jawaban tidak valid!");
        puts("loading.....");
        sleep(2);
        break;
    }
    
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
                if(selection == 0){
                systemClear();
                puts("loading.....");
                sleep(2);
                difficultyMenu();
                }
                else if(selection == 1){
                systemClear();
                puts("terima kasih telah memainkan game kami :)");
                sleep(2);
                }

    return 0;
}