#include <stdio.h>
#include <string.h>

// Structure definition
struct Netflix {
    int user_id;
    char name[50];
    char plan[20];
    float monthly_bill;
};

int main() {
    // Static initialization
    struct Netflix user1 = {101, "Pradeep", "Premium", 799.0};

    struct Netflix *ptr;
    ptr = &user1;

    // 🔹 Printing using object (dot operator)
    printf("--- Using Object ---\n");
    printf("User ID: %d\n", user1.user_id);
    printf("Name: %s\n", user1.name);
    printf("Plan: %s\n", user1.plan);
    printf("Monthly Bill: %.2f\n", user1.monthly_bill);

    // 🔹 Printing using pointer
    printf("\n--- Using Pointer ---\n");
    printf("User ID: %d\n", ptr->user_id);
    printf("Name: %s\n", ptr->name);
    printf("Plan: %s\n", ptr->plan);
    printf("Monthly Bill: %.2f\n", ptr->monthly_bill);

    return 0;
}