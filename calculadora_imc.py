
# instruções:
# -GUI: python imc_calculadora.py
# -CLI: python imc_calculadora.py --cli

import sys
import tkinter as tk
from tkinter import ttk, messagebox



def calcular_imc(peso_kg, altura_m):
    """
    Calcula o Índice de Massa Corporal (IMC) em Python puro.

    Args:
        peso_kg (float): O peso da pessoa em quilogramas.
        altura_m (float): A altura da pessoa em metros.

    Returns:
        float: O valor do IMC calculado.
    """
    if altura_m <= 0:
        return 0
    return peso_kg / (altura_m * altura_m)

def interpretar_imc(imc):
    """
    Retorna a classificação do IMC em português.

    Args:
        imc (float): O valor do IMC.

    Returns:
        str: A classificação textual do IMC.
    """
    if imc < 18.5:
        return "Abaixo do peso"
    elif 18.5 <= imc < 25:
        return "Peso normal"
    elif 25 <= imc < 30:
        return "Sobrepeso"
    elif 30 <= imc < 35:
        return "Obesidade Grau I"
    elif 35 <= imc < 40:
        return "Obesidade Grau II"
    else:
        return "Obesidade Grau III (mórbida)"


#Parte da GUI

def iniciar_gui():
    """
    Constrói e executa a aplicação com interface gráfica (GUI) usando Tkinter.
    """
    def calcular_e_mostrar_imc_gui():
        """Função chamada pelo clique do botão na GUI."""
        try:
            peso = float(entry_peso.get())
            altura_cm = float(entry_altura.get())

            if peso <= 0 or altura_cm <= 0:
                messagebox.showerror("Erro de Entrada", "Peso e altura devem ser valores positivos.")
                return

            altura_m = altura_cm / 100.0
            
            imc = calcular_imc(peso, altura_m)
            classificacao = interpretar_imc(imc)

            resultado_str = f"Seu IMC é: {imc:.2f}\nClassificação: {classificacao}"
            label_resultado.config(text=resultado_str)

        except ValueError:
            messagebox.showerror("Erro de Entrada", "Por favor, insira apenas números válidos.")
        except Exception as e:
            messagebox.showerror("Erro Inesperado", f"Ocorreu um erro: {e}")

    root = tk.Tk()
    root.title("Calculadora de IMC Portátil")
    root.geometry("350x250")
    root.resizable(False, False)

    style = ttk.Style(root)
    style.configure("TLabel", font=("Helvetica", 12))
    style.configure("TButton", font=("Helvetica", 12, "bold"))
    style.configure("TEntry", font=("Helvetica", 12))

    frame = ttk.Frame(root, padding="20")
    frame.pack(fill="both", expand=True)

    label_peso = ttk.Label(frame, text="Peso (kg):")
    entry_peso = ttk.Entry(frame, width=15)
    label_altura = ttk.Label(frame, text="Altura (cm):")
    entry_altura = ttk.Entry(frame, width=15)
    button_calcular = ttk.Button(frame, text="Calcular IMC", command=calcular_e_mostrar_imc_gui)
    label_resultado = ttk.Label(frame, text="Resultado aparecerá aqui", font=("Helvetica", 11, "italic"), wraplength=300, justify="center")

    label_peso.grid(row=0, column=0, padx=5, pady=10, sticky="w")
    entry_peso.grid(row=0, column=1, padx=5, pady=10)
    label_altura.grid(row=1, column=0, padx=5, pady=10, sticky="w")
    entry_altura.grid(row=1, column=1, padx=5, pady=10)
    button_calcular.grid(row=2, column=0, columnspan=2, pady=20)
    label_resultado.grid(row=3, column=0, columnspan=2, pady=10)

    root.mainloop()


def iniciar_cli():
    """
    Executa a aplicação no modo de linha de comando (CLI).
    """
    print("--- Calculadora de IMC (Modo Terminal) ---")
    
    try:
        peso_str = input("Digite seu peso em kg (ex: 70.5): ")
        peso = float(peso_str)
        
        altura_cm_str = input("Digite sua altura em cm (ex: 175): ")
        altura_cm = float(altura_cm_str)

        if peso <= 0 or altura_cm <= 0:
            print("\nErro: Peso e altura devem ser valores positivos.")
            return
            
        altura_m = altura_cm / 100.0
        
        imc = calcular_imc(peso, altura_m)
        classificacao = interpretar_imc(imc)
        
        print("\n--- RESULTADO ---")
        print(f"Seu IMC é: {imc:.2f}")
        print(f"Classificação: {classificacao}")
        print("-----------------")

    except ValueError:
        print("\nErro: Entrada inválida. Por favor, digite apenas números.")
    except Exception as e:
        print(f"\nOcorreu um erro inesperado: {e}")



if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1].lower() == '--cli':
        iniciar_cli()
    else:
        iniciar_gui()
