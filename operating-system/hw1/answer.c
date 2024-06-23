#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROC_NUM 200
#define MAX_CMD_LEN 100
#define MAX_LINE_LEN 100

int main(int argc, char *argv[]) {
    int k, mafiaCnt = 0, mafiaPIDs[MAX_PROC_NUM];
    pid_t startPID = atoi(argv[1]);
    char command[MAX_CMD_LEN], line[MAX_LINE_LEN];

    if (startPID <= 0)
        return -1;

    snprintf(command, sizeof(command), "for ((pid=%d; pid<=%d; pid++)); do kill -10 $pid; done", startPID, startPID+199);

    FILE *cmdOutput = popen(command, "r");
    if (cmdOutput == NULL)
        return -1;

    pclose(cmdOutput);

    sleep(1);

    FILE *confessionFile = fopen("confession.txt", "r");
    if (confessionFile == NULL) return -1;

    for (k = 0; k < MAX_PROC_NUM; k++) {
        fgets(line, sizeof(line), confessionFile);
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        if (strcmp(line, "!!!") == 0)
            mafiaPIDs[mafiaCnt++] = startPID + k;
    }

    fclose(confessionFile);


    printf("mafia = %d\n", mafiaCnt);
    printf("citizen = %d\n", MAX_PROC_NUM - mafiaCnt);
    printf("=== mafia list ===\n\n");
    for (k=0; k < mafiaCnt; k++)
        printf("%d\n", mafiaPIDs[k]);

    return 0;
}