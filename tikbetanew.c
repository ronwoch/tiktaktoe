#include <stdio.h>

/* Tik Tak Toe Final Release Candidate 2.
 * Written by Ronald Wochner
 */


char grid[3][3] = {{'b','b','b'},
                  {'b','b','b'},
                  {'b','b','b'}};

int input(char turn) {
    int row;
    int col;
    char buf[2];
    char buf2[2];
    size_t nbytes;
    size_t nbytes2;
    int i;
 
    for (i = 0; i <= 2; ++i) {
        buf[i] = 0;
        buf2[i] = 0;
    }

    while (2>1) {

    printf("Please enter your move as ROW(enter) then COLumn(enter) player %c:\n", turn);
    nbytes = fread(buf, sizeof(buf),1,stdin);
    nbytes2 = fread(buf2, sizeof(buf2),1,stdin);
    row=atoi(buf);
    col=atoi(buf2);
    

        if (row < 0 || row >2 || col < 0 || col > 2) {
            printf("Error, row or col are out of range: %d, %d\n", row, col);
            continue;
        }
        if (grid[row][col] != 'b') {
            printf("Error, that move has been made by: %c\n", grid [row][col]);
            continue;
        }
   grid[row][col]=turn;
    printf("Row = %d\n", row);
    printf("Col = %d\n", col);
    printf("The move stored in %d %d is %c: \n", row,col,grid[row][col]);
    break;
    }
 
}

int  winner(void) {
    char filler;

    if (grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2]) {
        filler = grid[0][0];
        if (filler == 'b') return 0;
        printf("Player %c is the winner!\n", filler);
        return 1;
    }
    if (grid[1][0] == grid[1][1] && grid[1][0] == grid[1][2]) {
        filler = grid[1][0];
        if (filler == 'b') return 0;
        printf("Player %c is the winner!\n", filler);
        return 1;
    }
    if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) {
        filler = grid[2][0];
        if (filler == 'b') return 0;
        printf("Player %c is the winner!\n", filler);
        return 1;
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        filler = grid[0][0];
        if (filler == 'b') return 0;
        printf("Player %c is the winner!\n", filler);
        return 1;
    }
    if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) {
        filler = grid[2][0];
        if (filler == 'b') return 0;
        printf("Player %c is the winner!\n", filler);
        return 1;
    }
    if (grid[0][0] == grid[1][0] && grid[0][0] == grid[2][0]) {
        filler = grid[0][0];
        if (filler == 'b') return 0;
        printf("Player %c is the winner!\n", filler);
        return 1;
    }
    if (grid[0][1] == grid[1][1] && grid[0][1] == grid[2][1]) {
        filler = grid[0][1];
        if (filler == 'b') return 0;
        printf("Player %c is the winner!\n", filler);
        return 1;
    }
    if (grid[0][2] == grid[1][2] && grid[0][2] == grid[2][2]) {
        filler = grid[0][2];
        if (filler == 'b') return 0;
        printf("Player %c is the winner!\n", filler);
        return 1;
    }
    else return 0;

}


    
void select_display(char position, char player) {
    switch (position) {

    case 'l':
        switch (player) {
        case 'x':
        printf("      x |");
        break;
        case 'o':
        printf("      o |");
        break;
        case 'b':
        printf("        |");
        break;
        }
    break;

    case 'c':
        switch (player) {
        case 'x':
        printf(" x |");
        break;
        case 'o':
        printf(" o |");
        break;
        case 'b':
        printf("   |");
        break;
        }
    break;

    case 'r':
        switch (player) {
        case 'x':
        printf(" x \n");
        break;
        case 'o':
        printf(" o \n");
        break;
        case 'b':
        printf("   \n");
        break;
        }
    break;
    }
}

void print_horizon(void) {
    printf(" |         ---+---+---\n");
}

void new_line(void) {
    printf("\n");   
}

void print_display(void) {
    printf("COL         0 | 1 | 2 \n");
    print_horizon();
    new_line();
    printf("R| 0 |");
    select_display('l', grid[0][0]);
    select_display('c', grid[0][1]);
    select_display('r', grid[0][2]);
    print_horizon();
    printf("O| 1 |");
    select_display('l', grid[1][0]);
    select_display('c', grid[1][1]);
    select_display('r', grid[1][2]);
    print_horizon();
    printf("W| 2 |");
    select_display('l', grid[2][0]);
    select_display('c', grid[2][1]);
    select_display('r', grid[2][2]);
    new_line();
} 

int main(void) {

    int i=1;
    char turn='b';
    int winend;

    printf("Welcome to Tik Tak Toe, by Ron Wochner. \n");
    printf("Simply enter the number of the row you want, hit enter, then do the same for your desired column. \n");
    printf("Have fun! \n");
    print_display();
    while (i<10) {
        if (i%2==0) {
            turn='x';
            input(turn);
            print_display();
            winend = winner();
            if (winend == 1) break; 
            ++i;
        }
        if (i%2 !=0) {
            turn='o';
            input(turn);
            print_display();
            winend = winner();
            if (winend == 1) break; 
            ++i;
        }
    }

    return 0;
}
