#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    FILE *fp;
    struct Student s;
    int choice, roll, found;

    while(1) {
        printf("\n1.Add\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                fp = fopen("students.dat", "ab");

                printf("Roll: ");
                scanf("%d", &s.roll);

                printf("Name: ");
                scanf("%s", s.name);

                printf("Marks: ");
                scanf("%f", &s.marks);

                fwrite(&s, sizeof(s), 1, fp);
                fclose(fp);
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);

                fp = fopen("students.dat", "rb");
                found = 0;

                while(fread(&s, sizeof(s), 1, fp)) {
                    if(s.roll == roll) {
                        printf("Roll: %d\nName: %s\nMarks: %.2f\n",
                               s.roll, s.name, s.marks);
                        found = 1;
                    }
                }

                if(!found)
                    printf("Record not found!");

                fclose(fp);
                break;

            case 3:
                fp = fopen("students.dat", "rb");

                while(fread(&s, sizeof(s), 1, fp)) {
                    printf("\n%d %s %.2f",
                           s.roll, s.name, s.marks);
                }

                fclose(fp);
                break;

            case 4:
                exit(0);
        }
    }
}
