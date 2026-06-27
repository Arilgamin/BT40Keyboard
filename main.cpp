
#include <Arduino.h>

//=========================
// MATRIX CONFIGURATION
//=========================

#define ROWS 4
#define COLS 12

const uint8_t rowPins[ROWS] = {
    0,   // R0
    1,   // R1
    2,   // R2
    3    // R3
};

const uint8_t colPins[COLS] = {
    4,   // C0
    5,   // C1
    6,   // C2
    7,   // C3
    8,   // C4
    9,   // C5
    10,  // C6
    11,  // C7
    12,  // C8
    13,  // C9
    18,  // C10
    19   // C11
};

bool keyState[ROWS][COLS];

//=========================
// SETUP
//=========================

void setup()
{
    Serial.begin(115200);

    for (int r = 0; r < ROWS; r++)
    {
        pinMode(rowPins[r], OUTPUT);
        digitalWrite(rowPins[r], HIGH);
    }

    for (int c = 0; c < COLS; c++)
    {
        pinMode(colPins[c], INPUT_PULLUP);
    }

    Serial.println();
    Serial.println("================================");
    Serial.println(" Aril40Keyboard");
    Serial.println(" ESP32-C3 SuperMini");
    Serial.println(" Matrix 4 x 12");
    Serial.println("================================");
}

//=========================
// MATRIX SCAN
//=========================

void scanMatrix()
{
    for (int r = 0; r < ROWS; r++)
    {
        digitalWrite(rowPins[r], LOW);

        delayMicroseconds(5);

        for (int c = 0; c < COLS; c++)
        {
            bool pressed = (digitalRead(colPins[c]) == LOW);

            if (pressed != keyState[r][c])
            {
                keyState[r][c] = pressed;

                Serial.print("K");
                Serial.print(r);
                Serial.print(c);

                if (pressed)
                    Serial.println(" PRESS");
                else
                    Serial.println(" RELEASE");
            }
        }

        digitalWrite(rowPins[r], HIGH);
    }
}

//=========================
// LOOP
//=========================

void loop()
{
    scanMatrix();

    delay(1);
}
