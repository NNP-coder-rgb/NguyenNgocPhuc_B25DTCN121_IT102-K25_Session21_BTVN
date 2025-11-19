#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Book {
    char id[20];          
    char title[100];       
    char author[50];       
    float price;           
    char category[50];     
} Book;

Book books[100];
int bookCount = 0;

void clearScreen();
void pauseScreen();
void showMenu();
void inputBooks();
void displayBooks();
void addBookAtPosition();
void deleteBookById();
void updateBookById();
void sortBooksByPrice();
void searchBookByTitle();
int findBookById(char id[]);

int main() {
    int choice;
    
    while(1) {
        showMenu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                inputBooks();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                addBookAtPosition();
                break;
            case 4:
                deleteBookById();
                break;
            case 5:
                updateBookById();
                break;
            case 6:
                sortBooksByPrice();
                break;
            case 7:
                searchBookByTitle();
                break;
            case 8:
                printf("\n=== CAM ON BAN DA SU DUNG CHUONG TRINH ===\n");
                return 0;
            default:
                printf("\nLua chon khong hop le!\n");
                pauseScreen();
        }
    }
    
    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    printf("\nNhan Enter de tiep tuc...");
    getchar();
}

void showMenu() {
    clearScreen();
    printf("\n");
    for(int i = 0; i < 60; i++) printf("=");
    printf("\n");
    printf("                     HE THONG QUAN LY SACH\n");
    for(int i = 0; i < 60; i++) printf("=");
    printf("\n");
    printf("  1. Nhap so luong va thong tin sach\n");
    printf("  2. Hien thi thong tin sach\n");
    printf("  3. Them sach vao vi tri\n");
    printf("  4. Xoa sach theo ma sach\n");
    printf("  5. Cap nhat thong tin sach theo ma sach\n");
    printf("  6. Sap xep sach theo gia (tang/giam)\n");
    printf("  7. Tim kiem sach theo ten sach\n");
    printf("  8. Thoat\n");
    for(int i = 0; i < 60; i++) printf("=");
    printf("\n");
}

void inputBooks() {
    clearScreen();
    printf("\n=== NHAP SO LUONG VA THONG TIN SACH ===\n\n");
    
    int n;
    printf("Nhap so luong sach muon them: ");
    scanf("%d", &n);
    getchar();
    
    for(int i = 0; i < n; i++) {
        printf("\n--- Sach thu %d ---\n", bookCount + 1);
        
        printf("Ma sach: ");
        fgets(books[bookCount].id, 20, stdin);
        books[bookCount].id[strcspn(books[bookCount].id, "\n")] = '\0';
        
        printf("Ten sach: ");
        fgets(books[bookCount].title, 100, stdin);
        books[bookCount].title[strcspn(books[bookCount].title, "\n")] = '\0';
        
        printf("Tac gia: ");
        fgets(books[bookCount].author, 50, stdin);
        books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';
        
        printf("Gia tien: ");
        scanf("%f", &books[bookCount].price);
        getchar();
        
        printf("The loai: ");
        fgets(books[bookCount].category, 50, stdin);
        books[bookCount].category[strcspn(books[bookCount].category, "\n")] = '\0';
        
        bookCount++;
    }
    
    printf("\nThem %d sach thanh cong!\n", n);
    pauseScreen();
}

void displayBooks() {
    clearScreen();
    printf("\n=== DANH SACH SACH ===\n\n");
    
    if(bookCount == 0) {
        printf("Chua co sach nao!\n");
        pauseScreen();
        return;
    }
    
    for(int i = 0; i < 120; i++) printf("=");
    printf("\n");
    printf("|%-5s|%-12s|%-35s|%-20s|%-15s|%-20s|\n", 
           "STT", "Ma sach", "Ten sach", "Tac gia", "Gia", "The loai");
    for(int i = 0; i < 120; i++) printf("-");
    printf("\n");
    
    for(int i = 0; i < bookCount; i++) {
        printf("|%-5d|%-12s|%-35s|%-20s|%-15.0f|%-20s|\n",
               i + 1, books[i].id, books[i].title,
               books[i].author, books[i].price, books[i].category);
        for(int j = 0; j < 120; j++) printf("-");
        printf("\n");
    }
    
    printf("\nTong so sach: %d\n", bookCount);
    pauseScreen();
}

void addBookAtPosition() {
    clearScreen();
    printf("\n=== THEM SACH VAO VI TRI ===\n\n");
    
    if(bookCount >= 100) {
        printf("Danh sach da day!\n");
        pauseScreen();
        return;
    }
    
    int position;
    printf("Nhap vi tri muon them (1-%d): ", bookCount + 1);
    scanf("%d", &position);
    getchar();
    
    if(position < 1 || position > bookCount + 1) {
        printf("\nVi tri khong hop le!\n");
        pauseScreen();
        return;
    }
    
    
    for(int i = bookCount; i >= position; i--) {
        books[i] = books[i - 1];
    }
    
  
    printf("\n--- Nhap thong tin sach moi ---\n");
    
    printf("Ma sach: ");
    fgets(books[position - 1].id, 20, stdin);
    books[position - 1].id[strcspn(books[position - 1].id, "\n")] = '\0';
    
    printf("Ten sach: ");
    fgets(books[position - 1].title, 100, stdin);
    books[position - 1].title[strcspn(books[position - 1].title, "\n")] = '\0';
    
    printf("Tac gia: ");
    fgets(books[position - 1].author, 50, stdin);
    books[position - 1].author[strcspn(books[position - 1].author, "\n")] = '\0';
    
    printf("Gia tien: ");
    scanf("%f", &books[position - 1].price);
    getchar();
    
    printf("The loai: ");
    fgets(books[position - 1].category, 50, stdin);
    books[position - 1].category[strcspn(books[position - 1].category, "\n")] = '\0';
    
    bookCount++;
    
    printf("\nThem sach vao vi tri %d thanh cong!\n", position);
    pauseScreen();
}

int findBookById(char id[]) {
    for(int i = 0; i < bookCount; i++) {
        if(strcmp(books[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteBookById() {
    clearScreen();
    printf("\n=== XOA SACH THEO MA SACH ===\n\n");
    
    if(bookCount == 0) {
        printf("Chua co sach nao!\n");
        pauseScreen();
        return;
    }
    
    char id[20];
    printf("Nhap ma sach can xoa: ");
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int idx = findBookById(id);
    
    if(idx == -1) {
        printf("\nKhong tim thay sach co ma '%s'!\n", id);
        pauseScreen();
        return;
    }
    
    // Hiển thị thông tin sách sẽ xóa
    printf("\n--- Thong tin sach se xoa ---\n");
    printf("Ma sach: %s\n", books[idx].id);
    printf("Ten sach: %s\n", books[idx].title);
    printf("Tac gia: %s\n", books[idx].author);
    printf("Gia: %.0f VND\n", books[idx].price);
    printf("The loai: %s\n", books[idx].category);
    
    char confirm;
    printf("\nBan co chac chan muon xoa? (y/n): ");
    scanf("%c", &confirm);
    getchar();
    
    if(confirm == 'y' || confirm == 'Y') {
       
        for(int i = idx; i < bookCount - 1; i++) {
            books[i] = books[i + 1];
        }
        bookCount--;
        
        printf("\nXoa sach thanh cong!\n");
    } else {
        printf("\nHuy thao tac xoa!\n");
    }
    
    pauseScreen();
}

void updateBookById() {
    clearScreen();
    printf("\n=== CAP NHAT THONG TIN SACH ===\n\n");
    
    if(bookCount == 0) {
        printf("Chua co sach nao!\n");
        pauseScreen();
        return;
    }
    
    char id[20];
    printf("Nhap ma sach can cap nhat: ");
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int idx = findBookById(id);
    
    if(idx == -1) {
        printf("\nKhong tim thay sach co ma '%s'!\n", id);
        pauseScreen();
        return;
    }
    
    printf("\n--- Thong tin hien tai ---\n");
    printf("Ma sach: %s\n", books[idx].id);
    printf("Ten sach: %s\n", books[idx].title);
    printf("Tac gia: %s\n", books[idx].author);
    printf("Gia: %.0f VND\n", books[idx].price);
    printf("The loai: %s\n", books[idx].category);
    
    printf("\n--- Nhap thong tin moi (Enter de giu nguyen) ---\n");
    
    char temp[100];
    
    printf("Ten sach moi: ");
    fgets(temp, 100, stdin);
    if(temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = '\0';
        strcpy(books[idx].title, temp);
    }
    
    printf("Tac gia moi: ");
    fgets(temp, 50, stdin);
    if(temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = '\0';
        strcpy(books[idx].author, temp);
    }
    
    float newPrice;
    printf("Gia moi (0 de giu nguyen): ");
    scanf("%f", &newPrice);
    if(newPrice > 0) books[idx].price = newPrice;
    getchar();
    
    printf("The loai moi: ");
    fgets(temp, 50, stdin);
    if(temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = '\0';
        strcpy(books[idx].category, temp);
    }
    
    printf("\nCap nhat thanh cong!\n");
    pauseScreen();
}

void sortBooksByPrice() {
    clearScreen();
    printf("\n=== SAP XEP SACH THEO GIA ===\n\n");
    
    if(bookCount == 0) {
        printf("Chua co sach nao!\n");
        pauseScreen();
        return;
    }
    
    int choice;
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("Lua chon: ");
    scanf("%d", &choice);
    getchar();
    

    for(int i = 0; i < bookCount - 1; i++) {
        for(int j = 0; j < bookCount - i - 1; j++) {
            int shouldSwap = 0;
            
            if(choice == 1) {
            
                if(books[j].price > books[j + 1].price) {
                    shouldSwap = 1;
                }
            } else if(choice == 2) {
                
                if(books[j].price < books[j + 1].price) {
                    shouldSwap = 1;
                }
            }
            
            if(shouldSwap) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    
    printf("\nSap xep thanh cong!\n");
    pauseScreen();
    
    displayBooks();
}

void searchBookByTitle() {
    clearScreen();
    printf("\n=== TIM KIEM SACH THEO TEN ===\n\n");
    
    if(bookCount == 0) {
        printf("Chua co sach nao!\n");
        pauseScreen();
        return;
    }
    
    char keyword[100];
    printf("Nhap tu khoa tim kiem: ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    
    int found = 0;
    
    printf("\n=== KET QUA TIM KIEM ===\n\n");
    
    for(int i = 0; i < bookCount; i++) {
        if(strstr(books[i].title, keyword) != NULL) {
            if(found == 0) {
                for(int j = 0; j < 120; j++) printf("=");
                printf("\n");
                printf("|%-5s|%-12s|%-35s|%-20s|%-15s|%-20s|\n", 
                       "STT", "Ma sach", "Ten sach", "Tac gia", "Gia", "The loai");
                for(int j = 0; j < 120; j++) printf("-");
                printf("\n");
            }
            
            printf("|%-5d|%-12s|%-35s|%-20s|%-15.0f|%-20s|\n",
                   i + 1, books[i].id, books[i].title,
                   books[i].author, books[i].price, books[i].category);
            for(int j = 0; j < 120; j++) printf("-");
            printf("\n");
            
            found++;
        }
    }
    
    if(found == 0) {
        printf("Khong tim thay sach nao!\n");
    } else {
        printf("\nTim thay %d sach!\n", found);
    }
    
    pauseScreen();
}