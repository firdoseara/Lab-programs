#include <stdio.h>

// Enumerated type for marital status
typedef enum {
    SINGLE,
    MARRIED,
    WIDOWED,
    DIVORCED
} MaritalStatus;

// Union to store information based on marital status
typedef union {
    struct {
        char marriageDate[20];
    } marriedInfo;

    struct {
        char deathOfSpouse[20];
    } widowedInfo;

    struct {
        char divorceDate[20];
    } divorcedInfo;
} MarriageDetails;

// Structure to represent a person
typedef struct {
    char name[50];
    int age;
    MaritalStatus status;
    MarriageDetails details; // Union to store additional information based on marital status
} Person;

int main() {
    // Example usage
    Person person;

    // Assigning values to person
    printf("Enter name: ");
    scanf("%s", person.name);

    printf("Enter age: ");
    scanf("%d", &person.age);

    printf("Enter marital status (0 for single, 1 for married, 2 for widowed, 3 for divorced): ");
    scanf("%d", &person.status);

    // Handling based on marital status
    switch (person.status) {
        case SINGLE:
            // No additional information for single individuals
            break;

        case MARRIED:
            printf("Enter marriage date: ");
            scanf("%s", person.details.marriedInfo.marriageDate);
            break;

        case WIDOWED:
            printf("Enter date of spouse's death: ");
            scanf("%s", person.details.widowedInfo.deathOfSpouse);
            break;

        case DIVORCED:
            printf("Enter divorce date: ");
            scanf("%s", person.details.divorcedInfo.divorceDate);
            break;

        default:
            printf("Invalid marital status\n");
            return 1;
    }

    // Displaying information
    printf("\nPerson Information:\n");
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);

    // Displaying additional information based on marital status
    switch (person.status) {
        case MARRIED:
            printf("Marriage Date: %s\n", person.details.marriedInfo.marriageDate);
            break;

        case WIDOWED:
            printf("Death of Spouse Date: %s\n", person.details.widowedInfo.deathOfSpouse);
            break;

        case DIVORCED:
            printf("Divorce Date: %s\n", person.details.divorcedInfo.divorceDate);
            break;
    }

    return 0;
}
