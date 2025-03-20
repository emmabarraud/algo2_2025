#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <locale.h>  /* Para caracteres especiales */

#define SIZE 4  
#define CELL_MAX (SIZE * SIZE - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i = 0; i < length; i++) printf("................");
    printf("\n");
}

void print_board(char board[SIZE][SIZE]) {
    int cell = 0;

    print_sep(SIZE);
    for (int fila = 0; fila < SIZE; ++fila) {
        for (int columna = 0; columna < SIZE; ++columna) {
            printf("\t | %d: %c ", cell, board[fila][columna]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(SIZE);
    }
}

char get_winner(char board[SIZE][SIZE]) {
    char winner = '-';
    
    for (int i = 0; i < SIZE; i++) {
        bool row_win = true, col_win = true;
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != board[i][0] || board[i][0] == '-') row_win = false; //avanza fijandose si los elementos de la misma fila, intercammbiando columnas son iguales al elemento en la primer columna, fila i, o si esta vacio, y le asigna falso a la variable
            if (board[j][i] != board[0][i] || board[0][i] == '-') col_win = false; //avanza fijandose si los elementos de la misma columna, intercammbiando filas son iguales al elemento en la primer fila, columna i, o si esta vacio, y le asigna falso a la variable
        }
        if (row_win) return board[i][0]; //fila gana si encuentra que todas los elementos de la fila i, son iguales y no hay ninguno vacio
        if (col_win) return board[0][i]; //columna gana "" para columna igual
    }
    
    bool diagizq_win = true, diagder_win = true;
    for (int i = 1; i < SIZE; i++) {
        if (board[i][i] != board[0][0] || board[0][0] == '-') diagizq_win = false;
        if (board[i][SIZE - i - 1] != board[0][SIZE - 1] || board[0][SIZE - 1] == '-') diagder_win = false; 
    }
    if (diagizq_win) return board[0][0]; //celda de la primer columna primer fila 
    if (diagder_win) return board[0][SIZE - 1]; //celda de la ultima columna primer fila
    
    return winner;
}

bool has_free_cell(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    setlocale(LC_ALL, "es_ES.UTF-8");
    printf("TicTacToe %dx%d\n", SIZE, SIZE);

    char board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
    
    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / SIZE;
            int column = cell % SIZE;
            if (board[row][column] == '-') {
                board[row][column] = turn;
                turn = (turn == 'X') ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
