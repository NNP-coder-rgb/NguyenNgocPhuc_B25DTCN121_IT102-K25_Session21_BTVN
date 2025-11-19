#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Address{
    char street[100];
    char city[50];
    int zip;
}Address;

typedef struct Person{
    char fullName[50];
    int age;
    Address address;
}Person;

void printListPeson(Person list[], int n);

int main(){
    Person list[100];
    int n;
    printf("Nhap vao so sinh vien: ");
    scanf("%d",&n);
    getchar();

    for(int i = 0; i < n; i++){
        printf("Nhap vao ho ten sinh vien: ");
        fgets(list[i].fullName,50,stdin);
        list[i].fullName[strcspn(list[i].fullName,"\n")] = '\0';

        printf("Nhap vao tuoi: ");
        scanf("%d",&list[i].age);
        getchar();

        printf("Nhap vao ten duong: ");
        fgets(list[i].address.street,100,stdin);
        list[i].address.street[strcspn(list[i].address.street,"\n")] = '\0';

        printf("Nhap vao ten thanh pho: ");
        fgets(list[i].address.city,50,stdin);
        list[i].address.city[strcspn(list[i].address.city,"\n")] = '\0';

        printf("Nhap vao ma zip: ");
        scanf("%d",&list[i].address.zip);
        getchar();
    }
    printListPeson(list,n);
    return 0;
}

void printListPeson(Person list[], int n){
    for(int i = 0; i < 89; i++){
        printf("=");
    }
    printf("\n|                                      LIST PERSON                                      |\n");
    for(int i = 0; i < 89; i++){
        printf("=");
    }
    printf("\n|%-30s|%-5s|%-50s|\n","Ho Va Ten","Tuoi","Que Quan");
    for(int i = 0; i < 89; i++){
        printf("-");
    }
    printf("\n");
    for(int i= 0;i < n; i++){
        printf("|%-30s|%-5d|%-17s - %-15s - ZIP: %-7d|\n",list[i].fullName,list[i].age,list[i].address.street,list[i].address.city,list[i].address.zip);
        for(int i = 0; i < 89; i++){
            printf("-");
        }
        printf("\n");
    }
}
