#include <stdio.h>
#include <string.h>

typedef struct Book {
    char title[100];   
    char author[50];   
    float price;       
} Book;


void inputBook(Book *b) {
    printf("Nhap ten sach: ");
    fgets(b->title, sizeof(b->title), stdin);
    b->title[strcspn(b->title, "\n")] = 0; 
    
    printf("Nhap tac gia: ");
    fgets(b->author, sizeof(b->author), stdin);
    b->author[strcspn(b->author, "\n")] = 0;
    
    printf("Nhap gia: ");
    scanf("%f", &b->price);
    getchar(); 
}

void printAllBooks(Book books[], int n) {
    printf("\n=====================================================================================\n");
    printf("|                           DANH SACH TAT CA CAC CUON SACH                          |\n");
    printf("=====================================================================================\n");
    printf("|%-5s|%-35s|%-25s|%-15s|\n", "STT", "Ten sach", "Tac gia", "Gia (VND)");
    printf("-------------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        printf("|%-5d|%-35s|%-25s|%-15.2f|\n", 
               i + 1, books[i].title, books[i].author, books[i].price);
            for(int i = 0; i < 85;i++){
                printf("-");
            }
            printf("\n");
    }
}

int main() {
    Book books[3];
    
    printf("========================================================\n");
    printf("|              CHUONG TRINH QUAN LY SACH               |\n");
    printf("========================================================\n\n");
    
    for(int i = 0; i < 3; i++) {
        inputBook(&books[i]);
    }
    printf("\n\n");
    printAllBooks(books, 3);
    return 0;
}