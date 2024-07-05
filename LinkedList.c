#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char surname[60];
    int year;
    char group[12];
};

struct Node { //узел одногосвязаного списка
    int id;
    struct Student stud;
    struct Node* next; //ссылка на следующий нод
};

struct LinkedList { //содержит указатель на первый элемент списка (нод) и длину всего списка
    struct Node* start;
    int len;
};

// Функция для инициализации пустого списка
void NameOfList(struct LinkedList* list) {
    list->start = NULL;
    list->len = 0;
}

// Функция для добавления студента в конец списка
void Add(struct Student stud, struct LinkedList* list) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = list->len + 1;
    newNode->stud = stud;
    newNode->next = NULL;

    if (list->start == NULL) {
        list->start = newNode;
    }
    else {
        struct Node* temp = list->start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->len++;
}
//функция для добаления студента в начало списка
void Addplace(struct Student stud, struct LinkedList* list) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->id = 1;
    new_node->stud = stud;
    if (list->start!=NULL){
      struct Node *temp = list->start;
      while (temp!=NULL){
        temp->id++;
        temp = temp->next;
     }
   }
   new_node->next = list->start;
   list->start=new_node;
   list->len++; 
}

//функция для добавления студента между двумя элементами
void AddBetween(struct Student stud, int id1, int id2, struct LinkedList* list) {
    if (list->start == NULL || id1 < 0 || id2 < 0) {
        printf("Operation execution error");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->stud = stud;
    int newId=1;
    struct Node* temp = list->start;
    while (temp->next!= NULL) {
        newId++;
        if (temp->id == id1 && temp->next->id == id2 && temp->next != NULL) {
            new_node ->next = temp -> next;
            temp->next = new_node;
	    new_node->id = newId;
            list->len++;
            newId++;
           struct Node*temp2=new_node->next;
           while (temp2!=NULL){
             temp2->id = newId++;
             temp2 = temp2->next;
          }
          break;
        }
        temp = temp->next;
    }
}
//функция удаления студента по номеру
void Delete(int id, struct LinkedList* list) {
    if (list->start == NULL || id < 0) {
        printf("Operation execution error");
        return;
    }
    struct Node* temp = list->start;
    if (temp->id == id) {
        list->start = temp->next;
        free(temp);
        list->len--;
        int newId=1;
        temp = list->start;
        while (temp!=NULL){
          temp->id = newId++;
          temp = temp->next;
       }
     return;
    }
    while (temp->next != NULL) {
        if (temp->next->id == id) {
            struct Node* toDelete = temp->next;
            temp->next = toDelete ->next;
            free(toDelete);
            list->len--;
            int newId=1;
            temp = list->start;
            while (temp!=NULL){
              temp->id=newId++;
              temp = temp->next;
            }
            return;
        }
        temp = temp->next;
    }

}
//функция поиска студента в списке
int Search(const char* surname, struct LinkedList* list) {
    struct Node* temp = list->start;
    if (list->start == NULL) {
        printf("List is empty.");
        return -1;
    }
    while (temp->next != NULL) {
        if (strcmp(temp->stud.surname, surname) == 0) {
            return temp->id;
        }
        temp = temp->next;
    }
    return -1;
}

// Функция для вывода списка на экран
void printList(const struct LinkedList* list) {
    if (list->start == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->start;
    printf("List:\n");
    while (temp != NULL) {
        printf("%d: %s, %d, %s\n", temp->id, temp->stud.surname, temp->stud.year, temp->stud.group);
        temp = temp->next;
    }
}

int main() {
    struct LinkedList myList;
    NameOfList(&myList);
    struct Node* head = NULL;

    while (1) {
        printf("\nOperations:\n");
        printf("1. Add student to the end of the list\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("4. Add student on the top of list\n");
        printf("5. Add student between numbers\n");
        printf("6. Delete student\n");
        printf("7. Search student by surname\n");
        printf("\n");
        printf("Enter operation number: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            struct Student newStudent;
            printf("Enter student name: ");
            scanf("%s", newStudent.surname);
            printf("Enter student year: ");
            scanf("%d", &newStudent.year);
            printf("Enter student group: ");
            scanf("%s", newStudent.group);
            Add(newStudent, &myList);
            printf("Student added in the list.\n");
        }
        else if (choice == 4) {
            struct Student newStudent;
            printf("Enter student name: ");
            scanf("%s", newStudent.surname);
            printf("Enter student year: ");
            scanf("%d", &newStudent.year);
            printf("Enter student group: ");
            scanf("%s", newStudent.group);
            Addplace(newStudent, &myList);
            printf("Student added in the list.\n");
        }
        else if (choice == 5) {
            struct Student newStudent;
            printf("Enter student name: ");
            scanf("%s", newStudent.surname);
            printf("Enter student year: ");
            scanf("%d", &newStudent.year);
            printf("Enter student group: ");
            scanf("%s", newStudent.group);
            printf("Enter id number one: ");
            int id1;
            scanf("%d", &id1);
            printf("Enter id number two: ");
            int id2;
            scanf("%d", &id2);
            AddBetween(newStudent,id1, id2, &myList);
            printf("Student added in the list.\n");
        }
        else if (choice == 6) {
            int id;
            printf("Enter id number of student: ");
            scanf("%d", &id);
            Delete(id, &myList);
            printf("Student was deleted.");
        }
        else if (choice == 7) {
            char surname[50];
            printf("Enter surname of student: ");
            scanf("%s", surname);
            int id = Search(surname, &myList);
	    if (id !=-1){
            	printf("Student was found: ");
            	printf("%d", id);
		}
            else{
                printf("Student was not find");
        }
	}
        else if (choice == 2) {
            printList(&myList);
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice. Please enter a valid operation number.\n");
        }
    }

    return 0;
}
