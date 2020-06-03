#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

void main() {

    setlocale(LC_ALL,"");
    int num_cat = 1;
    int cat_compras[99];
    int cat_itens = 0;
    double quant[99];
    char cat_nome[99][25];
    char desc_item[99][15];
    char uni_med[99][3];
    char a_parc[2];
    double real[99];
    double v_total = 0;
    double v_total_desc = 0;
    int t_itens = 0;
    double desconto = 0;
    double value_min[99];
    double cat_total[99];
    int aux_desc = 0;
    double perc_desc = 0;
    int qtd_parc = 0;
    double v_parc = 0;

    printf("Digite a quantidade de categorias que deseja: ");
    scanf("%d", &num_cat);
    int a = 1;
    int cont = 1;

    for (a ; a <= num_cat; a++) {
        printf("\nQual o nome da categoria que deseja? \n");
        scanf("%s", cat_nome[a]);
        printf("\nDigite a quantidade de %s que deseja: ", cat_nome[a]);
        scanf("%d", &cat_compras[a]);
        cat_itens = cat_itens + cat_compras[a];

        for (int b =1 ; b <= cat_compras[a]; b++) {
            printf("\n%d� Quais itens de %s deseja?\n",cont,cat_nome[a]);
            scanf("%s", desc_item[cont]);
            printf("\nDigite a unidade de medida: UN(unidade) / KG (quilograma) / PCT (pacote)\n");
            scanf("%s", &uni_med[cont]);
            printf("\nQuantidade de %s que deseja: \n", desc_item[cont]);
            scanf("%lf", &quant[cont]);
            printf("\nDigite o pre�o de acordo com UN/KG/PCT(R$)\n" );
            scanf("%lf", &real[cont]);
            cat_total[a] = cat_total[a] + (quant[cont]*real[cont]);
            t_itens = t_itens + 1;
            v_total = (real[cont]*quant[cont]) + v_total;
            cont = cont+1;
            system("cls");
        }
    system("cls");
    }
    a=1;
    cont = 1;
    printf("Digite a porcentagem de desconto:\n");
    scanf("%d", &desconto);
    desconto = perc_desc / 100;
    desconto = v_total * desconto;
    v_total_desc = v_total - desconto;
    printf("O valor total ficou: %.2f\n",v_total_desc);
    aux_desc = v_total_desc / 100;
    int aux = 0;
    //while(aux == 0){
        printf("Digite a forma de pagamento: A (� vista) | P (parcelado)\n");
        scanf("%s", a_parc);

        if (a_parc[0] == 'A'){
            aux = 1;
            printf("Erick Assunção Pereira Eufrasio\n");
            printf("erick852000@gmail.com\n\n");
            for (a ; a <= num_cat; a++){
                printf("%s  %d\n", cat_nome[a], cat_compras[a]);
                for (int b = 1; b <= cat_compras[a]; b++) {
                    printf("%s: R$ %.2f  (%.1f %s)  \n", desc_item[cont],real[cont]*quant[cont],quant[cont],uni_med[cont]);
                    cont = cont+1;
                }
                printf("  TOTAL %s = R$ %.2f\n",cat_nome[a],cat_total[a]);
                printf("\n");
            }
            printf("TOTAL DE ITENS: %d\n",t_itens);
            printf("VALOR TOTAL: R$ %.2f\n",v_total);
            printf("DESCONTO: %.1f%\n",perc_desc);
            printf("VALOR DO DESCONTO: R$ %.2f\n", desconto);
            printf("VALOR A PAGAR: R$ %.2f\n",v_total_desc);

        }else if(a_parc[0] == 'P'){
            aux = 1;
            printf("O valor m�nimo da parcela � de R$ 100,00\n");
            printf("Esse valor pode ser parcelado em at� %d vezes. Digite a quantidade de parcelas desejadas:\n",aux_desc);
            scanf("%d", &qtd_parc);
            v_parc = v_total_desc / qtd_parc;
            system("cls");
            printf("Erick Assunção Pereira Eufrasio\n");
            printf("erick852000@gmail.com\n\n");
            for (a ; a <= num_cat; a++){
                printf("%s  %d\n", cat_nome[a], cat_compras[a]);
                for (int b = 1; b <= cat_compras[a]; b++) {
                    printf(" %s: R$ %.2f  (%.1f %s)  \n", desc_item[cont],real[cont]*quant[cont],quant[cont],uni_med[cont]);
                    cont = cont+1;
                }
                printf("  TOTAL %s = R$ %.2f\n",cat_nome[a],cat_total[a]);
                printf("\n");
            }
            printf("TOTAL DE ITENS: %d\n",t_itens);
            printf("VALOR TOTAL: R$ %.2f\n",v_total);
            printf("DESCONTO: %.1f%\n",perc_desc);
            printf("VALOR DO DESCONTO: R$ %.2f\n", desconto);
            printf("VALOR A PAGAR: R$ %.2f\n",v_total_desc);
            printf("PARCELAS: %d\n",qtd_parc);
            printf("VALOR DA PARCELA: R$ %.2f\n",v_parc);
        }
    //}
}
