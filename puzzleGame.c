#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15 // It is the dimension of the square puzzle board(15 x 15)

typedef struct{
    char word[30]; // It is the string value of the word
    int x1, y1; // It is the starting coordinates of the words
    int x2, y2; // It is the ending coordinates of the words
    int found; // It is a boolean flag to checks if the user found it (0 for false, 1 for true)
}WordItem;

typedef struct{
    char map[SIZE][SIZE]; // It is the 2d board of the random letters consist of rows and columns
    WordItem words[10]; // It is an array that stores up to 10 WordItem structures.
    int wordCount; //It is the actual number of words that loaded into the game.
}Puzzle;

Puzzle fill_random_map(Puzzle p);
void print_puzzle(Puzzle p);
Puzzle place_single_word(Puzzle p , WordItem w);
Puzzle place_all_words(Puzzle p);
int search_in_direction(Puzzle p , char guess[] , int r , int c , int dr , int dc);
Puzzle find_word_direction(Puzzle p , char guess[] , int r , int c);
Puzzle uppercase_found_word(Puzzle p , char guess[] , int r , int c , int dr , int dc);
Puzzle mark_word_as_found(Puzzle p , char guess[]);
int all_words_found(Puzzle p);
void play_game(Puzzle p);


int main(){
    srand(time(NULL)); // Everytime we run the program, We need different character in every single spot. For example, in [2][3] zone, there is 'h'. But for this function, we can get 'k' after another running
    Puzzle myGame;
    myGame.wordCount = 0;
    myGame = fill_random_map(myGame); // It initiates the board with random letters.
    myGame = place_all_words(myGame); // It load words from the file and place them on the board.
    play_game(myGame);
    return 0;
}

Puzzle fill_random_map(Puzzle p){ // This function creates random letters every single spot using for loops and rand() function
    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            p.map[i][j] = 97 + (rand() % 26); // 97 is the ASCII code of 'a' and rand() % 26 adds a random number between 0-26.
        }
    }
    return p;
}

void print_puzzle(Puzzle p){ // This function prints random letters found in each row and column of the game.
    printf("----- PUZZLE -----");
    for(int k = 0 ; k < SIZE ; k++){
        printf("\n");
        for(int l = 0 ; l < SIZE ; l++){
            printf("%c ",p.map[k][l]);
        }
    }
}

Puzzle place_single_word(Puzzle p , WordItem w){ // This function determines the direction of the word and place it in the Puzzle based on the start and end coordinates.
    int dr;
    int dc;
    // Determine row changing
    if (w.x2 > w.x1){ // 1 if it goes right
        dr = 1;
    }
    else if(w.x1 > w.x2){ // -1 if it goes left
        dr = -1;
    }
    else{ // 0 if it goes neither right nor left(only vertical movement)
        dr = 0;
    }
    // Determine column changing
    if (w.y2 > w.y1){ // 1 if it goes down
        dc = 1;
    }
    else if (w.y1 > w.y2){ // -1 if it goes up
        dc = -1;
    }
    else{ // 0 if it goes neither down nor up(only horizontal movement)
        dc = 0;
    }
    int r = w.x1;
    int c = w.y1;
    int len = strlen(w.word);
    for(int m = 0 ; m < len ; m++){ // This for loop places the letters of the word in the board.
        p.map[r][c] = w.word[m];
        r += dr;
        c += dc;
    }
    return p;
}

Puzzle place_all_words(Puzzle p){ //This function takes the words and their start and end coordinates from our text file using file operations.
    FILE *file = fopen("words.txt","r");
    if (file == NULL){
        printf("The document cannot be found\n");
        return p;
    }
    else{
        int index = 0;
        // We limited our words to 10 and ensure all 5 fields are read successfully.
        while(index < 10 && fscanf(file, "%s %d %d %d %d" , p.words[index].word , &p.words[index].x1 , &p.words[index].y1 , &p.words[index].x2 , &p.words[index].y2) == 5){
            p.words[index].found = 0; // If we find the word, this variable for the specific word will be 1. But for now, it is 0. In the following function, we will handle this.
            p = place_single_word(p,p.words[index]); // Using while loop, it sends every single word to the sinle_word function to place them in the board correctly.
            index++;
        }
        p.wordCount = index;
        fclose(file);
        return p;
    }
}

int search_in_direction(Puzzle p , char guess[] , int r , int c , int dr , int dc){ // This function checks if a specific string exist starting (r,c) with changing (dr,dc) returns 1 if found.
    int len2 = strlen(guess);
    for(int n = 0 ; n < len2 ; n++){
        int new_row = r + (n * dr);
        int new_col = c + (n * dc);
        // We make boundary check in the if condition and make sure that we dont look outside of the array
        if (new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE) {
            return 0;
        }
        // If every single character of our input doesnt equals to the data in the board, return 0.
        if(p.map[new_row][new_col] != guess[n]){
            return 0;
        }
    }
    return 1;
}

Puzzle find_word_direction(Puzzle p , char guess[] , int r , int c){ // Checks all 8 possible directions around the starting point (r,c) to see if the guessed word exists here.
    // Arrays representing 8 possible directions.
    int drs[8] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
    int dcs[8] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};
    for(int o = 0 ; o < 8 ; o++){
        if (search_in_direction(p, guess, r, c, drs[o], dcs[o])){
            // If word is found, modify map to uppercase and update word status.
            p = uppercase_found_word(p,guess,r,c,drs[o],dcs[o]);
            p = mark_word_as_found(p,guess);
            printf("Correct!\n");
            return p;

        }
    }
    printf("Not found.\n");
    return p;
}

Puzzle uppercase_found_word(Puzzle p, char guess[], int r, int c, int dr, int dc){
    int len3 = strlen(guess);
    for(int s = 0 ; s < len3 ; s++){
        int nr2 = r + (s * dr);
        int nc2 = c + (s * dc);
        p.map[nr2][nc2] -= 32; // ASCII lowercase 'a' = 97 'A' = 97 - 32 = 65
        
    }
    return p;
}

Puzzle mark_word_as_found(Puzzle p, char guess[]){ // This function helps us to determine the words that are found.
    for(int t = 0 ; t < p.wordCount ; t++){
        if(strcmp(p.words[t].word,guess) == 0){ // This if statement compares our input and internal word list.
            p.words[t].found = 1; // Make 1 if it is found.
        }
    }
    return p;
}

int all_words_found(Puzzle p){ // This function checks whether all words found in the Puzzle or not.
    for(int u = 0 ; u < p.wordCount ; u++){
        if(p.words[u].found == 0){ // Using the for loop to check all words, even if 1 word has not found yet, it returns 0.
            return 0;
        } 

    }
    return 1;
}

void play_game(Puzzle p){ // This function handles user input and win conditions.
    char guess[20];
    int r;
    int c;

    while(999){ // It is an infinite loop until 'exit' or win
        print_puzzle(p);

        if(all_words_found(p)){
            printf("\nCongrats! You have found all words.\n");
            break;
        }

        printf("\nEnter word (or exit game): ");
        scanf("%s",guess);

        if(strcmp(guess,"exit") == 0){
            printf("Game over.\n");
            break;
        }

        printf("Enter row and column: ");
        scanf("%d %d",&r,&c);
        p = find_word_direction(p,guess,r,c); // Check if the word starts at the given coordinates.
    }
}






