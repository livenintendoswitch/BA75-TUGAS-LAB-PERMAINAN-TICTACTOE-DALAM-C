//import library sesuai kebutuhan
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int game(){
//masukin gamenya disini
}

//menu difficulty
int difficultyMenu() {
    int choice;
    system("cls");//buat windows
    system("clear");//buat linux
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
    int valueWhileLoop = 1, choice;

    while(valueWhileLoop){
    //user interface
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
    puts("1) main");
    puts("2) keluar dari program");
    printf("apa yang anda ingin lakukan sekarang? : ");
    scanf("%d", &choice);
    switch(choice){
        case 1: 
            difficultyMenu();
            break;
        case 2: 
            system("cls");//buat windows
            system("clear");//buat linux
            puts("keluar...");
            puts("terima kasih telah memainkan game kami!");
            sleep(2);
            valueWhileLoop = 0;
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
    return 0;
}