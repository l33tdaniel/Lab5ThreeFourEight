#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMonthsWithDates(){
    FILE* file;
        char buffer[100];
        const char* months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        file = fopen("input.txt", "r");
        if (file == NULL) {
            printf("The file is not opened. The program will now exit.\n");
            exit(1); // Use a non-zero value to indicate an error
        }

        int lineNumber = 0;
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            if (lineNumber < 12) {
                float value;
                sscanf(buffer, "%f", &value);
                printf("%-10s %10.2f\n", months[lineNumber], value);
            } else {
                printf("No corresponding month for line: %s\n", buffer);
            }
            lineNumber++;
        }
    fclose(file);
}
void salesSummary() {
    FILE* file;
    char buffer[100];
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("The file is not opened. The program will now exit.\n");
        exit(1); // Use a non-zero value to indicate an error
    } else {
        double minimum;
        double maximum;
        int maxMonth = 0;
        int minMonth = 0;

        double doubleArray[12];
        int count = 0;

        while (count < 12 && fgets(buffer, sizeof(buffer), file) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';

            // Convert the string to a double and store it in the array
            double value = strtof(buffer, NULL);
            if (value != 0.0f) {
                doubleArray[count] = value;
                count++;
            }
        }

       double total;
        for(int i = 0; i < 12; i++){
            if(i==0){
                maximum = doubleArray[i];
                minimum = doubleArray[i];
            }
            if(doubleArray[i] > maximum){
                maximum = doubleArray[i];
                maxMonth = i;
            }
            if(doubleArray[i] < minimum){
                minimum = doubleArray[i];
                minMonth = i;
            }
            total += doubleArray[i];
            printf("%-15s %.2f\n", months[i], doubleArray[i]);

        }
        printf("\nSales Summary:\n");
        printf("%-15s %.2f      %s\n", "Minimum", minimum, months[minMonth]);
        printf("%-15s %.2f      %s\n", "Maximum", maximum, months[maxMonth]);
        printf("%s%.2f%s", "Average: ", total/12, "\n");
        printf("\n");
    }
    fclose(file);
}

void sixMonthMovingReport() {

    FILE* file;
    char buffer[100];
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("The file is not opened. The program will now exit.\n");
        exit(1); // Use a non-zero value to indicate an error
    } else {
        double minimum;
        double maximum;
        int maxMonth = 0;
        int minMonth = 0;

        double doubleArray[12];
        int count = 0;
        printf("Six Month Moving Average Report:\n");
        while (count < 12 && fgets(buffer, sizeof(buffer), file) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';

            // Convert the string to a double and store it in the array
            double value = strtof(buffer, NULL);
            if (value != 0.0f) {
                doubleArray[count] = value;
                count++;
            }
        }
    for(int i = 0; i < 7; i++){
        double total = 0;
        for (int j = i; j < i+6; j++) {
            total += doubleArray[j];
        }
        printf("%-15s-        %-15s %.2f\n", months[i], months[i+5], total/6);
    }
    }
    // still must be done ALSO ADD THE AVERAGE TO SALES SUMMARY
}


void salesReportHighestLowest(){
FILE* file;
    char buffer[100];
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("The file is not opened. The program will now exit.\n");
        exit(1); // Use a non-zero value to indicate an error
    } else {
        printf("\n\nSales Report (Highest to Lowest):\n");
        printf("    Month         Sales\n");

        // Assuming you have 12 double values in the file, one per line
        double doubleArray[12];
        int count = 0;

        while (count < 12 && fgets(buffer, sizeof(buffer), file) != NULL) {
            // Remove the newline character from the end of the string
            buffer[strcspn(buffer, "\n")] = '\0';

            // Convert the string to a double and store it in the array
            double value = strtof(buffer, NULL);
            if (value != 0.0f) {
                doubleArray[count] = value;
                count++;
            }
        }
        
        double doubleCopy[12];
        for(int i = 0; i < 12; i++){
            doubleCopy[i] = doubleArray[i];
        }

        // sorting something from greatest to least
        int assignedMonth[12];
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 12; j++){
                if (doubleArray[i] > doubleArray[j]){
                    double temp = doubleArray[i];
                    doubleArray[i] = doubleArray[j];
                    doubleArray[j] = temp;
                }
            }
        }

        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 12; j++){
                if(doubleArray[i] == doubleCopy[j]){
                    assignedMonth[i] = j;
                }
            }
        }
        // Print the values in the double array
        for (int i = 0; i < count; i++) {
            printf("%-15s %.2f\n", months[assignedMonth[i]], doubleArray[i]);
        }

        fclose(file);
    }
}

int main() {
    printMonthsWithDates();
    salesSummary();
    sixMonthMovingReport();
    salesReportHighestLowest();
    return 0;
}