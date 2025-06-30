#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void TrocarVirgulaPorPonto(char *str) {
    while (*str) {
        if (*str == ',') {
            *str = '.';
        }
        str++;
    }
}

int main() {
    InitWindow(600, 450, "Calculadora de IMC");
    SetTargetFPS(60);

    char pesoInput[16]   = "0";
    char alturaInput[16] = "0";
    char resultado[128]  = "";

    bool pesoEdit   = false;
    bool alturaEdit = false;

    Rectangle pesoBox   = { 180, 100, 200, 30 };
    Rectangle alturaBox = { 180, 150, 200, 30 };
    Rectangle btnCalc   = { 230, 200, 120, 30 };

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Calculadora de IMC", 155, 40, 20, DARKGRAY);
            DrawText("Peso (kg):",  75, 107, 20, BLACK);
            
            DrawText("Altura (cm):", 60, 157, 20, BLACK);
            DrawText(resultado, GetScreenWidth() / 2 - MeasureText(resultado, 20) / 2, 270, 20, DARKGREEN);

            if (GuiTextBox(pesoBox, pesoInput, 16, pesoEdit)) pesoEdit = !pesoEdit;
            if (GuiTextBox(alturaBox, alturaInput, 16, alturaEdit)) alturaEdit = !alturaEdit;

            if (GuiButton(btnCalc, "Calcular")) {
                
                TrocarVirgulaPorPonto(pesoInput);

                float peso        = atof(pesoInput);
        
                float altura_cm   = atof(alturaInput);
                
                float altura_m = 0.0f;
                if (altura_cm > 0) {
                    altura_m = altura_cm / 100.0f;
                }

                if (altura_m > 0.0f && peso > 0.0f) {
                    float imc = peso / (altura_m * altura_m);

                    const char *classificacao;
                    if (imc < 18.5f)      classificacao = "Abaixo do peso";
                    else if (imc < 24.9f) classificacao = "Peso normal";
                    else if (imc < 29.9f) classificacao = "Sobrepeso";
                    else if (imc < 34.9f) classificacao = "Obesidade Grau I";
                    else if (imc < 39.9f) classificacao = "Obesidade Grau II";
                    else                  classificacao = "Obesidade Grau III";

                    snprintf(resultado, sizeof(resultado),
                             "Seu IMC: %.2f (%s)", imc, classificacao);
                } else {
                    strcpy(resultado, "Peso ou altura inválidos.");
                }
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
