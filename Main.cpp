#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
using namespace std;

class SeaBattle {
public:
    SeaBattle() {
        for (int i = 0; i < 10 * 10; ++i)
            field.push_back('*');
    }

    void ClearField() {
        for (int i = 0; i < 10 * 10; ++i)
            field[i] = '*';
    }
    void CoutField() {
        CharCord = 'A'; IntCord = 1;

        cout << "\n\n ";
        for (int i = 0; i < 10; ++i) { cout << " " << IntCord; IntCord += 1; } cout << "\n";

        for (int i = 0; i < 10 * 10; ++i) {
            if (i % 10 == 0 && i != 0) { cout << "\n"; }
            if (i % 10 == 0) { cout << CharCord << " "; CharCord += 1; }
            cout << field[i] << " ";
        }
    }
    void WriteFieldToFile(string fileName = "file.txt") {
        fstream file(fileName, ios::app);
        CharCord = 'A'; IntCord = 1;

        file << "\n\n ";
        for (int i = 0; i < 10; ++i) { file << " " << IntCord; IntCord += 1; } file << "\n";

        for (int i = 0; i < 10 * 10; ++i) {
            if (i % 10 == 0 && i != 0) { file << "\n"; }
            if (i % 10 == 0) { file << CharCord << " "; CharCord += 1; }
            file << field[i] << " ";
        }
        file.close();
    }

    void DrawRandShipOnTheField(char boat, int count) {
    rand:
        Direction = rand() % 10 - 5; // Direction >= 0 = down // Direction <= 0 = right
        IntCord = rand() % 9 + 1;
        CharCord = rand() % 9 + 1;

        bool CanPlaceBoat = true;
        char TEMP = '1';

        for (int j = 0; j < 5; j++) {
            if (Direction >= 0) {
                for (int i = 0; i < count; i++) {
                    if ((IntCord + CharCord * 10 - 10 + i * 10) % 10 == 0 && IntCord != 1) {
                        if (field[IntCord + CharCord * 10 - 1 + i * 10] != TEMP && // E 5
                            field[IntCord + CharCord * 10 - 2 + i * 10] != TEMP && // E 4

                            field[IntCord + CharCord * 10 - 11 + i * 10] != TEMP && // D 5 // Cord
                            field[IntCord + CharCord * 10 - 12 + i * 10] != TEMP && // D 4

                            field[IntCord + CharCord * 10 - 21 + i * 10] != TEMP && // C 5
                            field[IntCord + CharCord * 10 - 22 + i * 10] != TEMP && // C 4

                            IntCord + CharCord * 10 - 11 + i * 10 <= 99)
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                    else if (IntCord == 1) {
                        if (field[IntCord + CharCord * 10 - 0 + i * 10] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 1 + i * 10] != TEMP && // E 5

                            field[IntCord + CharCord * 10 - 10 + i * 10] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 11 + i * 10] != TEMP && // D 5 // Cord

                            field[IntCord + CharCord * 10 - 20 + i * 10] != TEMP && // C 6
                            field[IntCord + CharCord * 10 - 21 + i * 10] != TEMP && // C 5

                            IntCord + CharCord * 10 - 11 + i * 10 <= 99)
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                    else {
                        if (field[IntCord + CharCord * 10 - 0 + i * 10] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 1 + i * 10] != TEMP && // E 5
                            field[IntCord + CharCord * 10 - 2 + i * 10] != TEMP && // E 4

                            field[IntCord + CharCord * 10 - 10 + i * 10] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 11 + i * 10] != TEMP && // D 5 // Cord
                            field[IntCord + CharCord * 10 - 12 + i * 10] != TEMP && // D 4

                            field[IntCord + CharCord * 10 - 20 + i * 10] != TEMP && // C 6
                            field[IntCord + CharCord * 10 - 21 + i * 10] != TEMP && // C 5
                            field[IntCord + CharCord * 10 - 22 + i * 10] != TEMP && // C 4

                            IntCord + CharCord * 10 - 11 + i * 10 <= 99)
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                }
            }
            else if (Direction <= 0) {
                for (int i = 0; i < count; i++) {
                    if (IntCord + count >= 11 && IntCord != 1) {
                        if (field[IntCord + CharCord * 10 - 1 + i] != TEMP && // E 5
                            field[IntCord + CharCord * 10 - 2 + i] != TEMP && // E 4

                            field[IntCord + CharCord * 10 - 11 + i] != TEMP && // D 5 // Cord
                            field[IntCord + CharCord * 10 - 12 + i] != TEMP && // D 4

                            field[IntCord + CharCord * 10 - 21 + i] != TEMP && // C 5
                            field[IntCord + CharCord * 10 - 22 + i] != TEMP && // C 4

                            IntCord + count <= 11)
                        {
                            continue;
                        }
                        else
                        {

                            CanPlaceBoat = false;
                        }
                    }
                    else if (IntCord == 1) {
                        if (field[IntCord + CharCord * 10 - 0 + i] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 1 + i] != TEMP && // E 5

                            field[IntCord + CharCord * 10 - 10 + i] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 11 + i] != TEMP && // D 5 // Cord

                            field[IntCord + CharCord * 10 - 20 + i] != TEMP && // C 6
                            field[IntCord + CharCord * 10 - 21 + i] != TEMP) // C 5
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                    else {
                        if (field[IntCord + CharCord * 10 - 0 + i] != TEMP && // E 6
                            field[IntCord + CharCord * 10 - 1 + i] != TEMP && // E 5
                            field[IntCord + CharCord * 10 - 2 + i] != TEMP && // E 4

                            field[IntCord + CharCord * 10 - 10 + i] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 11 + i] != TEMP && // D 5 // Cord
                            field[IntCord + CharCord * 10 - 12 + i] != TEMP && // D 4

                            field[IntCord + CharCord * 10 - 20 + i] != TEMP && // C 6
                            field[IntCord + CharCord * 10 - 21 + i] != TEMP && // C 5
                            field[IntCord + CharCord * 10 - 22 + i] != TEMP && // C 4

                            IntCord + count <= 10)
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                }
            }
            TEMP++;
        }

        if (CanPlaceBoat) {
            if (Direction >= 0)
                for (int index = 0; index < count; index++)
                    field[IntCord + CharCord * 10 - 11 + index * 10] = boat;
            else if (Direction <= 0)
                for (int index = 0; index < count; index++)
                    field[IntCord + CharCord * 10 - 11 + index] = boat;
        }
        else {
            goto rand;
        }
    }
    void DrawShipOnTheField(char boat, int count, bool& Successful, int Direction = 0) {
        Direction = this->Direction; // Direction >= 0 = down // Direction <= 0 = right
        bool CanPlaceBoat = true;
        char TEMP = '1';

        for (int j = 0; j < 5; j++) {
            if (Direction >= 0) {
                for (int i = 0; i < count; i++) {
                    if ((IntCord + CharCord * 10 - 10 + i * 10) % 10 == 0 && IntCord != 1) {
                        if (field[IntCord + CharCord * 10 - 1 + i * 10] != TEMP && // E 5
                            field[IntCord + CharCord * 10 - 2 + i * 10] != TEMP && // E 4

                            field[IntCord + CharCord * 10 - 11 + i * 10] != TEMP && // D 5 // Cord
                            field[IntCord + CharCord * 10 - 12 + i * 10] != TEMP && // D 4

                            field[IntCord + CharCord * 10 - 21 + i * 10] != TEMP && // C 5
                            field[IntCord + CharCord * 10 - 22 + i * 10] != TEMP && // C 4

                            IntCord + CharCord * 10 - 11 + i * 10 <= 99)
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                    else if (IntCord == 1) {
                        if (field[IntCord + CharCord * 10 - 0 + i * 10] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 1 + i * 10] != TEMP && // E 5

                            field[IntCord + CharCord * 10 - 10 + i * 10] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 11 + i * 10] != TEMP && // D 5 // Cord

                            field[IntCord + CharCord * 10 - 20 + i * 10] != TEMP && // C 6
                            field[IntCord + CharCord * 10 - 21 + i * 10] != TEMP && // C 5

                            IntCord + CharCord * 10 - 11 + i * 10 <= 99)
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                    else {
                        if (field[IntCord + CharCord * 10 - 0 + i * 10] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 1 + i * 10] != TEMP && // E 5
                            field[IntCord + CharCord * 10 - 2 + i * 10] != TEMP && // E 4

                            field[IntCord + CharCord * 10 - 10 + i * 10] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 11 + i * 10] != TEMP && // D 5 // Cord
                            field[IntCord + CharCord * 10 - 12 + i * 10] != TEMP && // D 4

                            field[IntCord + CharCord * 10 - 20 + i * 10] != TEMP && // C 6
                            field[IntCord + CharCord * 10 - 21 + i * 10] != TEMP && // C 5
                            field[IntCord + CharCord * 10 - 22 + i * 10] != TEMP && // C 4

                            IntCord + CharCord * 10 - 11 + i * 10 <= 99)
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                }
            }
            else if (Direction <= 0) {
                for (int i = 0; i < count; i++) {
                    if (IntCord + count >= 11 && IntCord != 1) {
                        if (field[IntCord + CharCord * 10 - 1 + i] != TEMP && // E 5
                            field[IntCord + CharCord * 10 - 2 + i] != TEMP && // E 4

                            field[IntCord + CharCord * 10 - 11 + i] != TEMP && // D 5 // Cord
                            field[IntCord + CharCord * 10 - 12 + i] != TEMP && // D 4

                            field[IntCord + CharCord * 10 - 21 + i] != TEMP && // C 5
                            field[IntCord + CharCord * 10 - 22 + i] != TEMP && // C 4

                            IntCord + count <= 11)
                        {
                            continue;
                        }
                        else
                        {

                            CanPlaceBoat = false;
                        }
                    }
                    else if (IntCord == 1) {
                        if (field[IntCord + CharCord * 10 - 0 + i] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 1 + i] != TEMP && // E 5

                            field[IntCord + CharCord * 10 - 10 + i] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 11 + i] != TEMP && // D 5 // Cord

                            field[IntCord + CharCord * 10 - 20 + i] != TEMP && // C 6
                            field[IntCord + CharCord * 10 - 21 + i] != TEMP) // C 5
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                    else {
                        if (field[IntCord + CharCord * 10 - 0 + i] != TEMP && // E 6
                            field[IntCord + CharCord * 10 - 1 + i] != TEMP && // E 5
                            field[IntCord + CharCord * 10 - 2 + i] != TEMP && // E 4

                            field[IntCord + CharCord * 10 - 10 + i] != TEMP && // D 6
                            field[IntCord + CharCord * 10 - 11 + i] != TEMP && // D 5 // Cord
                            field[IntCord + CharCord * 10 - 12 + i] != TEMP && // D 4

                            field[IntCord + CharCord * 10 - 20 + i] != TEMP && // C 6
                            field[IntCord + CharCord * 10 - 21 + i] != TEMP && // C 5
                            field[IntCord + CharCord * 10 - 22 + i] != TEMP && // C 4

                            IntCord + count <= 10)
                        {
                            continue;
                        }
                        else
                        {
                            CanPlaceBoat = false;
                        }
                    }
                }
            }
            TEMP++;
        }

        if (CanPlaceBoat) {
            if (Direction >= 0)
                for (int index = 0; index < count; index++)
                    field[IntCord + CharCord * 10 - 11 + index * 10] = boat;
            else if (Direction <= 0)
                for (int index = 0; index < count; index++)
                    field[IntCord + CharCord * 10 - 11 + index] = boat;
            Successful = true;
        }
        else {
            cout << "\n\nCant place you ship, try again\n\n";
        }
    }

    void PlaceRandShipOnTheField() {
        for (int i = 0; i < 1; i++)
            DrawRandShipOnTheField('4', 4);
        for (int i = 0; i < 2; i++)
            DrawRandShipOnTheField('3', 3);
        for (int i = 0; i < 3; i++)
            DrawRandShipOnTheField('2', 2);
        for (int i = 0; i < 4; i++)
            DrawRandShipOnTheField('1', 1);
    }

    void Place1ShipOnTheField(bool& Successful) {
        cout << "\n\nWrite Char.Cord to Place 1 deck ship: "; cin >> CharCord; CharCord -= 64; if (CharCord > 10 || CharCord < 1) { cout << "Error"; return; }
        cout << "Write Num.Cord to Place 1 deck ship: "; cin >> IntCord; if (IntCord > 10 || IntCord < 1) { cout << "Error"; return; }
        cout << "Select Direction ( 1 = down; -1 = right): "; cin >> Direction;
        system("clear");
        DrawShipOnTheField('1', 1, Successful);
    }
    void Place2ShipOnTheField(bool& Successful) {
        cout << "\n\nWrite Char.Cord to Place 2 deck ship: "; cin >> CharCord; CharCord -= 64; if (CharCord > 10 || CharCord < 1) { cout << "Error"; return; }
        cout << "Write Num.Cord to Place 2 deck ship: "; cin >> IntCord; if (IntCord > 10 || IntCord < 1) { cout << "Error"; return; }
        cout << "Select Direction ( 1 = down; -1 = right): "; cin >> Direction;
        system("clear");
        DrawShipOnTheField('2', 2, Successful);
    }
    void Place3ShipOnTheField(bool& Successful) {
        cout << "\n\nWrite Char.Cord to Place 3 deck ship: "; cin >> CharCord; CharCord -= 64; if (CharCord > 10 || CharCord < 1) { cout << "Error"; return; }
        cout << "Write Num.Cord to Place 3 deck ship: "; cin >> IntCord; if (IntCord > 10 || IntCord < 1) { cout << "Error"; return; }
        cout << "Select Direction ( 1 = down; -1 = right): "; cin >> Direction;
        system("clear");
        DrawShipOnTheField('3', 3, Successful);
    }
    void Place4ShipOnTheField(bool& Successful) {
        cout << "\n\nWrite Char.Cord to Place 4 deck ship: "; cin >> CharCord; CharCord -= 64; if (CharCord > 10 || CharCord < 1) { cout << "Error"; return; }
        cout << "Write Num.Cord to Place 4 deck ship: "; cin >> IntCord; if (IntCord > 10 || IntCord < 1) { cout << "Error"; return; }
        cout << "Select Direction ( 1 = down; -1 = right): "; cin >> Direction;
        system("clear");
        DrawShipOnTheField('4', 4, Successful);
    }

private:
    vector<char>field;
    char CharCord = -1;
    int Direction = -1;
    int IntCord = -1;
};

void DeleteFile(string fileName = "file.txt") {
    ofstream file(fileName, ios::out);
    file << ""; file.close();
}

int main() {
    srand(unsigned(time(NULL)));
    SeaBattle Robot, Player;
    bool Successful = false;
    int testMode = 0;
    Robot.PlaceRandShipOnTheField();
    cout << "Write 1 to skip, write 0 to place Ships: ";      cin >> testMode;
    if (testMode == 1)
        goto end;

    if (testMode == 0) {
        for (int i = 0; i < 1; i++) {
            Successful = false;
            while (!Successful) { Player.CoutField(); Player.Place4ShipOnTheField(Successful); }
        }
        for (int i = 0; i < 2; i++) {
            Successful = false;
            while (!Successful) { Player.CoutField(); Player.Place3ShipOnTheField(Successful); }
        }
        for (int i = 0; i < 3; i++) {
            Successful = false;
            while (!Successful) { Player.CoutField(); Player.Place2ShipOnTheField(Successful); }
        }
        for (int i = 0; i < 4; i++) {
            Successful = false;
            while (!Successful) { Player.CoutField(); Player.Place1ShipOnTheField(Successful); }
        }
    end:
        string FileName; cout << "\nEnter file name: "; cin >> FileName;

        DeleteFile(FileName);
        Player.WriteFieldToFile(FileName);
        Robot.WriteFieldToFile(FileName);

        Player.CoutField();
        Robot.CoutField();
    }
    return 0;
}

/*
Написати початкову частину програми «Морський бій».
Зробити квадратне поле 10х10.
Передбачити можливість введення розташування кораблів користувачем
і автоматичної розстановки кораблів випадковим чином,
але так, щоб кораблі не торкались один одного.
Поле з кораблями виведіть на екран і запишіть у файл.
*/
