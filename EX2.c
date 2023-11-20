#include <stdio.h>


char validaSexo() {
    char sexo;
    do {
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo);  
        sexo = toupper(sexo); 
        if (sexo != 'M' && sexo != 'F') {
            printf("Sexo inválido. Digite M para masculino ou F para feminino.\n");
        } else {
            break;
        }
    } while (1);

    return sexo;
}

float validaSalario() {
    float salario;
    do {
        printf("Digite o salário (em reais): ");
        scanf("%f", &salario);
        if (salario <= 1.00) {
            printf("Salário inválido. Deve ser maior que R$1,00. Digite novamente.\n");
        } else {
            break;
        }
    } while (1);

    return salario;
}

void classificaSalario(float salario, float salario_minimo) {
    if (salario > salario_minimo) {
        printf("Acima do salário mínimo");
    } else if (salario < salario_minimo) {
        printf("Abaixo do salário mínimo");
    } else {
        printf("Igual ao salário mínimo");
    }
}

void mostraClassifica(char sexo, float salario, float salario_minimo) {
    printf("\nSexo: %s\n", (sexo == 'M') ? "Masculino" : "Feminino");
    printf("Salário: R$ %.2f\n", salario);
    printf("Classificação em relação ao salário mínimo: ");
    classificaSalario(salario, salario_minimo);
    printf("\n---------------------------------\n");
}

int main() {
    float salario_minimo = 1400.00;
    int num_assalariados, abaixo_salario_minimo = 0, acima_salario_minimo = 0;

    printf("Digite o número de assalariados a serem pesquisados: ");
    scanf("%d", &num_assalariados);

    for (int i = 0; i < num_assalariados; ++i) {
        char sexo = validaSexo();
        float salario = validaSalario();

        if (salario < salario_minimo) {
            abaixo_salario_minimo++;
        } else if (salario > salario_minimo) {
            acima_salario_minimo++;
        }

        mostraClassifica(sexo, salario, salario_minimo);
    }

    printf("\nResumo:\n");
    printf("Assalariados abaixo do salário mínimo: %d\n", abaixo_salario_minimo);
    printf("Assalariados acima do salário mínimo: %d\n", acima_salario_minimo);

    return 0;
}