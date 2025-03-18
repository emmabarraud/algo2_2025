#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <locale.h> // busque en google como hacer para leer caracteres especiales como ñ
#include <assert.h>  /* assert() */

#define CELL_MAX (4 * 4 - 1)

void print_sep(int length) { //separador de filas
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[4][4]) {
    int cell = 0;

    print_sep(4);
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]); //separador de columnas
            ++cell;
        }
        printf("\t | \n");
        print_sep(4);
    }
}

char get_winner(char board[4][4]){
    char winner = '-';
    for (int i = 0; i < 4; i++) { //recorre para verificar filas y columnas
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][0] != '-') { //filas
            winner = board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[0][i] != '-') { //columnas
            winner = board[0][i];
        }
    }
//no hace falta recorrer ya que solo hay dos diagonales
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[0][0] != '-') { //diagonales board[0][0] != '-' es que no este vacio
        winner = board[0][0];
    }
    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[3][0] == board[2][1] && board[0][2] != '-') {
        winner = board[0][3];
    }
    return winner; //si nadie gana de ninguna forma, devuelve winner que es '-'
}

bool has_free_cell(char board[4][4])
{
    bool free_cell = false;
    for (int i = 0; i < 4; i++) { //filas
        for (int j = 0; j < 4; j++) { //columnas
            if (board[i][j] == '-') {
                free_cell = true;
            }
        }
    }
    return free_cell;
}

int main(void){
    setlocale(LC_ALL, "es_ES.UTF-8"); // busque en google como hacer para leer caracteres especiales como ñ
    printf("TicTacToe Incompleto 4x4\n");

    char board[4][4] = {
        { '-', '-', '-' , '-' },
        { '-', '-', '-' , '-' },
        { '-', '-', '-' , '-' },
        { '-', '-', '-' , '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 4;
            int colum = cell % 4;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
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
