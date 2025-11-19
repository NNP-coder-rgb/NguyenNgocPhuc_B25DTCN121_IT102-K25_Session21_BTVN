#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Studient{
    char fullName[30];
    int age;
    float grade;
}Studient;

void printListStudient(Studient List[], int n);

int main(){
    Studient List[100];
    int SoLuongSinhVien = 5;
    List[0] = (struct Studient){"Nguyen Ngoc Phuc", 20, 8.8};
    List[1] = (struct Studient){"Nguyen Huy Binh", 21, 8.3};
    List[2] = (struct Studient){"Nguyen Tien Dat", 19, 8.6};
    List[3] = (struct Studient){"Nguyen Tien Hung", 22, 8.8};
    List[4] = (struct Studient){"Nguyen Phuc Minh Duy", 20, 9.0};

    printListStudient(List, SoLuongSinhVien);
    return 0;
}

void printListStudient(Studient List[], int n){
    for(int i = 0; i < 60; i++){
        printf("=");
    }
    printf("\n|                   LIST POINT OF STUDIENT                 |\n");
    for(int i = 0; i < 60; i++){
        printf("=");
    }
    printf("\n|%-30s|%-6s|%-20s|\n","Ho Va Ten","Tuoi","Diem Trung Binh");
    for(int i = 0; i < 60;  i++){
        printf("-");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("|%-30s|%-6d|%-20.1f|\n",List[i].fullName,List[i].age,List[i].grade);
        for(int i = 0; i < 60; i++){
            printf("-");
        }
        printf("\n");
    }
}