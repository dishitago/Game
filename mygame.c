#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int main() {
    // random seed
    srand(time(0));

    int player = WIDTH / 2; // player starts in middle
    int blockX = rand() % WIDTH;
    int blockY = 0;
    int score = 0;
    char key;

    while(1) {
        system("cls"); // clear screen

        // print the game
        for(int y = 0; y < HEIGHT; y++) {
            for(int x = 0; x < WIDTH; x++) {
                if(y == HEIGHT - 1 && x == player)
                    printf("^"); // player
                else if(x == blockX && y == blockY)
                    printf("#"); // falling block
                else
                    printf("."); // empty space
            }
            printf("\n");
        }

        printf("Score: %d\n", score);

        // check if player hit the block
        if(blockY == HEIGHT - 1 && blockX == player) {
            printf("Game Over!\n");
            break;
        }

        // read player input
        if(_kbhit()) {
            key = _getch();
            if(key == 'a' && player > 0) player--; // move left
            if(key == 'd' && player < WIDTH - 1) player++; // move right
        }

        // move the block down
        blockY++;
        if(blockY >= HEIGHT) {
            blockY = 0; // reset to top
            blockX = rand() % WIDTH; // random position
            score++; // increase score
        }

        Sleep(200); // wait a bit
    }

    return 0;
}
