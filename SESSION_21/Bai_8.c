#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Product {
    char id[20];           
    char name[100];        
    float importPrice;     
    float sellPrice;       
    int quantity;          
} Product;

Product products[100];
int productCount = 0;
float revenue = 0;

void clearScreen();
void pauseScreen();
void showMenu();
void addProducts();
void displayProducts();
void importProduct();
void updateProduct();
void sortProducts();
void searchProduct();
void sellProduct();
void showRevenue();
int findProductById(char id[]);

int main() {
    int choice;
    
    while(1) {
        showMenu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                addProducts();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                importProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                sortProducts();
                break;
            case 6:
                searchProduct();
                break;
            case 7:
                sellProduct();
                break;
            case 8:
                showRevenue();
                break;
            case 9:
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
    printf("                          MENU\n");
    for(int i = 0; i < 60; i++) printf("=");
    printf("\n");
    printf("  1. Nhap so luong va thong tin san pham\n");
    printf("  2. Hien thi danh sach san pham\n");
    printf("  3. Nhap san pham\n");
    printf("  4. Cap nhat thong tin san pham\n");
    printf("  5. Sap xep san pham theo gia (tang/giam)\n");
    printf("  6. Tim kiem san pham\n");
    printf("  7. Ban san pham\n");
    printf("  8. Doanh thu hien tai\n");
    printf("  9. Thoat\n");
    for(int i = 0; i < 60; i++) printf("=");
    printf("\n");
}

void addProducts() {
    clearScreen();
    printf("\n=== NHAP SO LUONG VA THONG TIN SAN PHAM ===\n\n");
    
    int n;
    printf("Nhap so luong san pham muon them: ");
    scanf("%d", &n);
    getchar();
    
    for(int i = 0; i < n; i++) {
        printf("\n--- San pham thu %d ---\n", productCount + 1);
        
        printf("Ma san pham: ");
        fgets(products[productCount].id, 20, stdin);
        products[productCount].id[strcspn(products[productCount].id, "\n")] = '\0';
        
        printf("Ten san pham: ");
        fgets(products[productCount].name, 100, stdin);
        products[productCount].name[strcspn(products[productCount].name, "\n")] = '\0';
        
        printf("Gia nhap: ");
        scanf("%f", &products[productCount].importPrice);
        
        printf("Gia ban: ");
        scanf("%f", &products[productCount].sellPrice);
        
        printf("So luong: ");
        scanf("%d", &products[productCount].quantity);
        getchar();
        
        productCount++;
    }
    
    printf("\nThem %d san pham thanh cong!\n", n);
    pauseScreen();
}

void displayProducts() {
    clearScreen();
    printf("\n=== DANH SACH SAN PHAM ===\n\n");
    
    if(productCount == 0) {
        printf("Chua co san pham nao!\n");
        pauseScreen();
        return;
    }
    
    for(int i = 0; i < 110; i++) printf("=");
    printf("\n");
    printf("|%-5s|%-15s|%-30s|%-15s|%-15s|%-10s|\n", 
           "STT", "Ma SP", "Ten san pham", "Gia nhap", "Gia ban", "So luong");
    for(int i = 0; i < 110; i++) printf("-");
    printf("\n");
    
    for(int i = 0; i < productCount; i++) {
        printf("|%-5d|%-15s|%-30s|%-15.0f|%-15.0f|%-10d|\n",
               i + 1, products[i].id, products[i].name,
               products[i].importPrice, products[i].sellPrice,
               products[i].quantity);
        for(int j = 0; j < 110; j++) printf("-");
        printf("\n");
    }
    
    printf("\nTong so san pham: %d\n", productCount);
    pauseScreen();
}

int findProductById(char id[]) {
    for(int i = 0; i < productCount; i++) {
        if(strcmp(products[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void importProduct() {
    clearScreen();
    printf("\n=== NHAP SAN PHAM ===\n\n");
    
    char id[20];
    int qty;
    
    printf("Ma san pham: ");
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int idx = findProductById(id);
    
    if(idx != -1) {
    
        printf("San pham da ton tai!\n");
        printf("Ten: %s\n", products[idx].name);
        printf("So luong hien tai: %d\n", products[idx].quantity);
        
        printf("\nNhap so luong can nhap them: ");
        scanf("%d", &qty);
        getchar();
        
        products[idx].quantity += qty;
        revenue -= qty * products[idx].importPrice;
        
        printf("\nNhap them %d san pham thanh cong!\n", qty);
        printf("So luong moi: %d\n", products[idx].quantity);
        printf("Doanh thu hien tai: %.0f VND\n", revenue);
    } else {
        printf("San pham chua ton tai. Nhap thong tin san pham moi:\n");
        
        strcpy(products[productCount].id, id);
        
        printf("Ten san pham: ");
        fgets(products[productCount].name, 100, stdin);
        products[productCount].name[strcspn(products[productCount].name, "\n")] = '\0';
        
        printf("Gia nhap: ");
        scanf("%f", &products[productCount].importPrice);
        
        printf("Gia ban: ");
        scanf("%f", &products[productCount].sellPrice);
        
        printf("So luong: ");
        scanf("%d", &products[productCount].quantity);
        getchar();
        
        revenue -= products[productCount].quantity * products[productCount].importPrice;
        
        printf("\nThem san pham moi thanh cong!\n");
        printf("Doanh thu hien tai: %.0f VND\n", revenue);
        
        productCount++;
    }
    
    pauseScreen();
}

void updateProduct() {
    clearScreen();
    printf("\n=== CAP NHAT THONG TIN SAN PHAM ===\n\n");
    
    if(productCount == 0) {
        printf("Chua co san pham nao!\n");
        pauseScreen();
        return;
    }
    
    char id[20];
    printf("Nhap ma san pham can cap nhat: ");
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int idx = findProductById(id);
    
    if(idx == -1) {
        printf("\nKhong tim thay san pham!\n");
        pauseScreen();
        return;
    }
    
    printf("\n--- Thong tin hien tai ---\n");
    printf("Ma SP: %s\n", products[idx].id);
    printf("Ten: %s\n", products[idx].name);
    printf("Gia nhap: %.0f\n", products[idx].importPrice);
    printf("Gia ban: %.0f\n", products[idx].sellPrice);
    printf("So luong: %d\n", products[idx].quantity);
    
    printf("\n--- Nhap thong tin moi (0 de giu nguyen) ---\n");
    
    char temp[100];
    printf("Ten moi: ");
    fgets(temp, 100, stdin);
    if(temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = '\0';
        strcpy(products[idx].name, temp);
    }
    
    float newPrice;
    printf("Gia nhap moi (0 de giu nguyen): ");
    scanf("%f", &newPrice);
    if(newPrice > 0) products[idx].importPrice = newPrice;
    
    printf("Gia ban moi (0 de giu nguyen): ");
    scanf("%f", &newPrice);
    if(newPrice > 0) products[idx].sellPrice = newPrice;
    
    int newQty;
    printf("So luong moi (-1 de giu nguyen): ");
    scanf("%d", &newQty);
    if(newQty >= 0) products[idx].quantity = newQty;
    getchar();
    
    printf("\nCap nhat thanh cong!\n");
    pauseScreen();
}

void sortProducts() {
    clearScreen();
    printf("\n=== SAP XEP SAN PHAM THEO GIA ===\n\n");
    
    if(productCount == 0) {
        printf("Chua co san pham nao!\n");
        pauseScreen();
        return;
    }
    
    int choice;
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("Lua chon: ");
    scanf("%d", &choice);
    getchar();
    
    for(int i = 0; i < productCount - 1; i++) {
        for(int j = 0; j < productCount - i - 1; j++) {
            int shouldSwap = 0;
            
            if(choice == 1) {
        
                if(products[j].sellPrice > products[j + 1].sellPrice) {
                    shouldSwap = 1;
                }
            } else {
            
                if(products[j].sellPrice < products[j + 1].sellPrice) {
                    shouldSwap = 1;
                }
            }
            
            if(shouldSwap) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    
    printf("\nSap xep thanh cong!\n");
    displayProducts();
}

void searchProduct() {
    clearScreen();
    printf("\n=== TIM KIEM SAN PHAM ===\n\n");
    
    if(productCount == 0) {
        printf("Chua co san pham nao!\n");
        pauseScreen();
        return;
    }
    
    char keyword[100];
    printf("Nhap tu khoa tim kiem (ma hoac ten): ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    
    int found = 0;
    
    printf("\n=== KET QUA TIM KIEM ===\n\n");
    
    for(int i = 0; i < productCount; i++) {
        if(strstr(products[i].id, keyword) != NULL || 
           strstr(products[i].name, keyword) != NULL) {
            if(found == 0) {
                for(int j = 0; j < 110; j++) printf("=");
                printf("\n");
                printf("|%-5s|%-15s|%-30s|%-15s|%-15s|%-10s|\n", 
                       "STT", "Ma SP", "Ten san pham", "Gia nhap", "Gia ban", "So luong");
                for(int j = 0; j < 110; j++) printf("-");
                printf("\n");
            }
            
            printf("|%-5d|%-15s|%-30s|%-15.0f|%-15.0f|%-10d|\n",
                   i + 1, products[i].id, products[i].name,
                   products[i].importPrice, products[i].sellPrice,
                   products[i].quantity);
            for(int j = 0; j < 110; j++) printf("-");
            printf("\n");
            
            found++;
        }
    }
    
    if(found == 0) {
        printf("Khong tim thay san pham nao!\n");
    } else {
        printf("\nTim thay %d san pham!\n", found);
    }
    
    pauseScreen();
}

void sellProduct() {
    clearScreen();
    printf("\n=== BAN SAN PHAM ===\n\n");
    
    if(productCount == 0) {
        printf("Chua co san pham nao!\n");
        pauseScreen();
        return;
    }
    
    char id[20];
    int qty;
    
    printf("Ma san pham: ");
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int idx = findProductById(id);
    
    if(idx == -1) {
        printf("\nKhong tim thay san pham!\n");
        pauseScreen();
        return;
    }
    
    printf("\nThong tin san pham:\n");
    printf("Ten: %s\n", products[idx].name);
    printf("Gia ban: %.0f VND\n", products[idx].sellPrice);
    printf("So luong hien co: %d\n", products[idx].quantity);
    
    if(products[idx].quantity == 0) {
        printf("\n*** HET HANG ***\n");
        pauseScreen();
        return;
    }
    
    printf("\nNhap so luong can ban: ");
    scanf("%d", &qty);
    getchar();
    
    if(qty > products[idx].quantity) {
        printf("\n*** KHONG CON DU HANG ***\n");
        printf("Chi con %d san pham!\n", products[idx].quantity);
        pauseScreen();
        return;
    }

    products[idx].quantity -= qty;
    float totalSale = qty * products[idx].sellPrice;
    revenue += totalSale;
    
    printf("\n=== HOA DON ===\n");
    printf("San pham: %s\n", products[idx].name);
    printf("So luong: %d\n", qty);
    printf("Don gia: %.0f VND\n", products[idx].sellPrice);
    printf("Thanh tien: %.0f VND\n", totalSale);
    printf("\nSo luong con lai: %d\n", products[idx].quantity);
    printf("Doanh thu hien tai: %.0f VND\n", revenue);
    
    pauseScreen();
}

void showRevenue() {
    clearScreen();
    printf("\n=== DOANH THU HIEN TAI ===\n\n");
    
    for(int i = 0; i < 50; i++) printf("=");
    printf("\n");
    
    if(revenue >= 0) {
        printf("  DOANH THU: +%.0f VND\n", revenue);
    } else {
        printf("  DOANH THU: %.0f VND (No)\n", revenue);
    }
    
    for(int i = 0; i < 50; i++) printf("=");
    printf("\n");
    
    printf("\nGhi chu:\n");
    printf("- Doanh thu am: Tien von nhap hang\n");
    printf("- Doanh thu duong: Loi nhuan tu ban hang\n");
    
    pauseScreen();
}