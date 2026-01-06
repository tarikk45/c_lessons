#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Dimensions of the Puzzle
#define ROWS 10
#define COLS 30

// Player structure stores the current coordinates of the player on the map.
typedef struct{
    int x;
    int y;
}Player;

// Scoreboard structure stores the game statistics.
typedef struct{
    int score; 
    int sCount; // Collected silver count
    int gCount; // Collected gold count
    int dCount; // Collected dolar count
    int flag;
}ScoreBoard;

char** allocateMap(int rows);
void loadMap(char **map, int rows, const char *file, Player *p);
void printMap(char **map, int rows);
void freeMap(char **map, int rows);
void handleMove(Player *player, char **map, ScoreBoard *sb, int nx, int ny);
void printControls();
int hasExit(char **map, int rows);

void moveUp(Player *p, char **m, ScoreBoard *s)    { handleMove(p, m, s, p->x - 1, p->y); }
void moveDown(Player *p, char **m, ScoreBoard *s)  { handleMove(p, m, s, p->x + 1, p->y); }
void moveLeft(Player *p, char **m, ScoreBoard *s)  { handleMove(p, m, s, p->x, p->y - 1); }
void moveRight(Player *p, char **m, ScoreBoard *s) { handleMove(p, m, s, p->x, p->y + 1); } 


int main(){
    srand(time(NULL));
    Player player;
    ScoreBoard sb = {0,0,0,0,0};
    time_t start_time = time(NULL);

    // Dynamic memory allocation and map loading from file.
    char **map = allocateMap(ROWS);
    loadMap(map,ROWS,"map.txt",&player);

    // This enables dynamic selection of the appropriate movement behavior based on user input (w, a, s, d).
    void (*moves[4])(Player*, char**, ScoreBoard*) = {moveUp, moveLeft, moveDown, moveRight};

    char input;
    while(1){
        printf("\n");
        printMap(map,ROWS);
        printControls();
        printf("\nScore: %d | Time: %ld sec\n", sb.score, time(NULL) - start_time);
        printf("Move (w/a/s/d/e): ");
        scanf(" %c",&input);
        if(input == 'e'){
            printf("\nExiting from the game");
            break;
        }
        int index = -1;
        if(input == 'w'){
            index = 0;
        }
        else if(input == 'a'){
            index = 1;
        }
        else if(input == 's'){
            index = 2;
        }
        else if(input == 'd'){
            index = 3;
        }
        if(index != -1){
            moves[index](&player,map,&sb);
        }
    }
        // Final score calculation applying the time penalty
        int duration = (int)(time(NULL) - start_time);
        int final_score = sb.score - duration;
        printf("\n==== SCORE BOARD ====\n");
        printf("Silver collected: %d\nGold collected: %d\nDollar collected: %d\n", sb.sCount, sb.gCount, sb.dCount);
        printf("Time: %d sec\nFinal Score: %d\n", duration, final_score);

        freeMap(map, ROWS);
    
    return 0;
}

char** allocateMap(int rows){ // This function dynamically allocates the map for a 2d character array
    char **map = (char**) malloc(rows * sizeof(char*));
    for(int i = 0 ; i < rows ; i++){
        map[i] = (char*) malloc(COLS * sizeof(char));
    }
    return map;
}
// This function loads the map data from txt file and finds out the Player starting position and updates the Player struct
void loadMap(char **map, int rows, const char *filename, Player *p){
    FILE *file = fopen("map.txt","r");
    if(file == NULL){
        printf("The document cannot be found\n");
        exit(1);
    }
    else{
        for(int j = 0 ; j < rows ; j++){
            for(int k = 0 ; k < COLS ; k++){
                fscanf(file," %c",&map[j][k]);
                if(map[j][k] == 'P'){
                    p->x = j;
                    p->y = k;
                }
            }
        }
        fclose(file);
    }
}
// This function will print our map in the main function when we call it
void printMap(char **map, int rows){
    for(int l = 0 ; l < rows ; l++){
        for(int m = 0 ; m < COLS ; m++){
            printf("%c",map[l][m]);
        }
        printf("\n");
    }
}

void printControls(){
    printf("\nControls: w = up s = down a = left d = right e = exit");
}
// This function checks if there are collectible item remain in the map
int hasExit(char **map, int rows){
    int itemsLeft = 0;
    for(int o = 0 ; o < rows ; o++){
        for(int p = 0 ; p < COLS ; p++){
            if(map[o][p] == 's' || map[o][p] == 'g' || map[o][p] == '$'){
                return 1;
            }
        }
    }
    return 0;
}

void handleMove(Player *player, char **map, ScoreBoard *sb, int nx, int ny){
    if(map[nx][ny] == '#'){ // Checking wall collisions
        return;
    }
    char target = map[nx][ny];
    int point = 0;
    // Item collection logic and scoring according to the item and the item position replaced with a wall.
    if(target == 's'){
        sb->score += 10;
        sb->sCount++;
        map[player->x][player->y] = '#';
    }
    else if(target == 'g'){
        sb->score += 20;
        sb->gCount++;
        map[player->x][player->y] = '#';
    }
    else if(target == '$'){
        sb->score += 30;
        sb->dCount++;
        map[player->x][player->y] = '#';
    }
    else{
        map[player->x][player->y] = '.';
    }
    // Updating player position on the map
    player->x = nx;
    player->y = ny;
    map[player->x][player->y] = 'P';
}
// This function releases dynamically allocated memory for the map
void freeMap(char **map,int rows){
    for(int n = 0 ; n < rows ; n++){
        free(map[n]);
    }
    free(map);
}