#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Car{
    char model[20];
    int year;
    long price;
}Car;

void printListCar(Car list[], int n){
    for(int i = 0 ; i < 59; i++){
        printf("=");
    }
    printf("\n|                      LIST CAR IN YEAR                   |\n");
    for(int i = 0; i < 59; i++){
        printf("=");
    }
    printf("\n|%-20s|%-15s|%-20s|\n","Ten mau xe","Nam san xuat","Gia ban(Trieu VND)");
    for(int i = 0; i <59; i++){
        printf("-");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("|%-20s|%-15d|%-20d|\n",list[i].model,list[i].year,list[i].price);
        // printf("\n");
        for(int i = 0; i < 59; i++){
            printf("-");
        }
        printf("\n");
    }
}

int main(){
    Car myCar[100];
    int n;
    printf("Nhap so luong xe ban muon nhap: ");
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++){
        printf("Nhap ten mau xe: ");
        fgets(myCar[i].model,20,stdin);
        myCar[i].model[strcspn(myCar[i].model,"\n")] = '\0';

        printf("Nhap vao nam san xuat xe: ");
        scanf("%d",&myCar[i].year);

        printf("Nhap vao gia ban cua xe(Trieu VND): ");
        scanf("%ld",&myCar[i].price);

        getchar();
    }
    printListCar(myCar,n);
    return 0;
}