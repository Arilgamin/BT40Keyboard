#include "Matrix.h"
#include "../../include/pins.h"
#include <Arduino.h>

static bool keys[ROWS][COLS];

void matrixBegin() {

    for (int r = 0; r < ROWS; r++) {
        pinMode(rowPins[r], OUTPUT);
        digitalWrite(rowPins[r], HIGH);
    }

    for (int c = 0; c < COLS; c++) {
        pinMode(colPins[c], INPUT_PULLUP);
    }
}

void matrixScan() {

    for (int r = 0; r < ROWS; r++) {

        digitalWrite(rowPins[r], LOW);

        delayMicroseconds(5);

        for (int c = 0; c < COLS; c++) {

            keys[r][c] = (digitalRead(colPins[c]) == LOW);

        }

        digitalWrite(rowPins[r], HIGH);
    }
}

bool keyPressed(uint8_t row, uint8_t col) {

    return keys[row][col];

}
