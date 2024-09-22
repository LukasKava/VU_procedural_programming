#include <stdio.h>
#include <stdlib.h>
 
//QUERY that filters out students who are in the 2 or 3 course

typedef struct Student {
    char name[30];
    char surname[30];
    int course;                 // year of study
    double average;             // average grade
    
    int load;                   // number of courses
    char courses[10][30];       // course names
    int grades[10];             // course grades    
    
    char languages[100];        // spoken languages
    
} Student;
 
 
int main(int argc, char *argv[]) {
    FILE *db = NULL;
    // open database file for reading, provide a parameter or use default "db.bin"
    if (argc > 1)
        db = fopen(argv[1], "rb");
    else
        db = fopen("db.bin", "rb");
        
    if (db){                            
        Student students[1000];         // all the data goes here
		int	indexArr[1000];				//Holding an index of each student which passed the array
        int size = 0;                   // how many students in database
        
        // reading data from file
        fread(&size, sizeof(int), 1, db);
        
        for (int i = 0; i < size; i++){         
            fread(&students[i], sizeof(Student), 1, db);            
        }   
        printf("%d records loaded succesfully\n", size);
        
        
        // MODIFY CODE BELOW
        
        int counterDemo = 0; // for counting students
        
        for (int i = 0; i < size; ++i){ // process all the student records in database
            Student s = students[i]; // store data for each student in s

            if(s.course == 2 || s.course == 3){ // *** first filter, conditions on the student
				indexArr[counterDemo] = i;
                printf("%d %s %s %d %f %d ", i + 1,  s.name, s.surname, s.course, s.average, s.load); // print student data
                int anotherDemo = 0; // for counting courses/grades
                for (int i = 0; i < s.load; ++i){ // process each course taken by the student
                    if(1){ // *** second filter, conditions on the course/grade
                        ++anotherDemo; // counting courses

                        printf("| %s %d | ", s.courses[i], s.grades[i]);
                    }
                }
                printf("%s\n", s.languages);
                        
                // if (anotherDemo == s.load) {//
                    ++counterDemo; // counting students
				//}
            }
        }
		printf("\033[0;32mQUERY4 [Students who are in the 2 or 3 course]:\033[0m\n");
        printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		for (int i = 0; i < counterDemo; i++) {
			printf("%d %s %s course year: %d load: %d average: %f courses and grades ", i + 1, students[indexArr[i]].name, students[indexArr[i]].surname, students[indexArr[i]].course, students[indexArr[i]].load, students[indexArr[i]].average);
			for (int j = 0; j < students[indexArr[i]].load; j++){ // process each course taken by the student
				printf("| %s %d ", students[indexArr[i]].courses[j], students[indexArr[i]].grades[j]);
			}
			printf("|\n");
		}
		printf("\n");
        fclose(db); 
    } else {
        printf("File db.bin not found, check current folder\n");
    }
    
    return 0;
}