#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
    char name[50];     
    int age;           
    float grade;       
} Student;

void printListStudent(Student list[], int n);
void searchStudentByName(Student list[], int n, char searchName[]);

int main() {
    Student list[100];
    int n;
    
    printf("========================================\n");
    printf("   CHUONG TRINH QUAN LY HOC SINH\n");
    printf("========================================\n\n");
    
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    getchar();
    
    for(int i = 0; i < n; i++) {
        printf("\n=== NHAP THONG TIN HOC SINH THU %d ===\n", i + 1);
        
        printf("Nhap ten hoc sinh: ");
        fgets(list[i].name, 50, stdin);
        list[i].name[strcspn(list[i].name, "\n")] = '\0';
        
        printf("Nhap tuoi: ");
        scanf("%d", &list[i].age);
        getchar();
        
        printf("Nhap diem trung binh: ");
        scanf("%f", &list[i].grade);
        getchar();
    }
    
    printf("\n\n");
    printListStudent(list, n);
    
    char searchName[50];
    printf("\n\n=== TIM KIEM HOC SINH ===\n");
    printf("Nhap ten hoc sinh can tim: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    
    searchStudentByName(list, n, searchName);
    
    return 0;
}

void printListStudent(Student list[], int n) {
    for(int i = 0; i < 70; i++) {
        printf("=");
    }
    
    printf("\n|                         DANH SACH HOC SINH                         |\n");
    
    for(int i = 0; i < 70; i++) {
        printf("=");
    }
    
    printf("\n|%-5s|%-35s|%-10s|%-15s|\n", "STT", "Ho Va Ten", "Tuoi", "Diem TB");
    
    for(int i = 0; i < 70; i++) {
        printf("-");
    }
    printf("\n");
    
    for(int i = 0; i < n; i++) {
        printf("|%-5d|%-35s|%-10d|%-15.2f|\n", 
               i + 1, list[i].name, list[i].age, list[i].grade);
        
        for(int j = 0; j < 70; j++) {
            printf("-");
        }
        printf("\n");
    }
}

void searchStudentByName(Student list[], int n, char searchName[]) {
    int found = 0;
    
    for(int i = 0; i < 70; i++) {
        printf("=");
    }
    
    printf("\n|                    KET QUA TIM KIEM: %-30s|\n", searchName);
    
    for(int i = 0; i < 70; i++) {
        printf("=");
    }
    
    for(int i = 0; i < n; i++) {
        if(strstr(list[i].name, searchName) != NULL) {
            if(found == 0) {
                printf("\n|%-5s|%-35s|%-10s|%-15s|\n", "STT", "Ho Va Ten", "Tuoi", "Diem TB");
                
                for(int j = 0; j < 70; j++) {
                    printf("-");
                }
                printf("\n");
            }
            
            printf("|%-5d|%-35s|%-10d|%-15.2f|\n", 
                   i + 1, list[i].name, list[i].age, list[i].grade);
            
            for(int j = 0; j < 70; j++) {
                printf("-");
            }
            printf("\n");
            
            found++;
        }
    }
    
    if(found == 0) {
        printf("\nKhong tim thay hoc sinh nao co ten \"%s\"!\n", searchName);
        
    } else {
        printf("Tim thay %d hoc sinh!\n", found);
    }
}