#include <stdio.h>
#include <string.h>

typedef struct Product{
    char name[50];     
    float price;       
    int quantity;      
} Product;

Product inputProduct() {
    Product p;
    
    printf("Nhap ten san pham: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;  
    
    printf("Nhap gia: ");
    scanf("%f", &p.price);
    
    printf("Nhap so luong: ");
    scanf("%d", &p.quantity);
    getchar();  
    
    return p;  
}

void printProduct(Product p, int index) {
    printf("\n--- San pham thu %d ---\n", index + 1);
    printf("Ten san pham: %s\n", p.name);
    printf("Gia: %.2f VND\n", p.price);
    printf("So luong: %d\n", p.quantity);
    printf("Tong gia tri: %.2f VND\n", p.price * p.quantity);
}

float calculateTotalValue(Product products[], int n) {
    float total = 0;
    
    for(int i = 0; i < n; i++) {
        total += products[i].price * products[i].quantity;
    }
    
    return total;
}

void printAllProducts(Product products[], int n) {
    printf("\n========================================================================================\n");
    printf("|                               DANH SACH TAT CA SAN PHAM                              |\n");
    printf("========================================================================================\n");
    printf("|%-5s|%-30s|%-15s|%-12s|%-20s|\n", "STT", "Ten san pham", "Gia (VND)", "So luong", "Tong gia tri (VND)");
    printf("----------------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        float totalValue = products[i].price * products[i].quantity;
        printf("|%-5d|%-30s|%-15.2f|%-12d|%-20.2f|\n", 
               i + 1, products[i].name, products[i].price, 
               products[i].quantity, totalValue);
               for(int i = 0; i < 88; i++){
                printf("-");
               }
               printf("\n");
    }
}

int main() {
    Product products[3];
    
    printf("========================================\n");
    printf("|        NHAP THONG TIN SAN PHAM       |\n");
    printf("========================================\n\n");
    
    for(int i = 0; i < 3; i++) {
        products[i] = inputProduct(); 
    }
    
    printf("\n\n");
    printAllProducts(products, 3);
    
    float totalValue = calculateTotalValue(products, 3);
    printf("========================================\n");
    printf("TONG GIA TRI: %.2f VND      \n", totalValue);
    
    return 0;
}