#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define SIZE 100

char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

int main() {
    DIR *d = opendir("tmp");

    if (d == NULL) {
        printf("Cannot open directory\n");
        exit(1);
    }

    struct dirent *dir_iter;

    printf("File - Hard Links\n");

    while ((dir_iter = readdir(d)) != NULL) {
        // In Linux OS there are files . and .. in every directory
        // This if statement exclude them
        if (strcmp(dir_iter->d_name, ".") == 0 || strcmp(dir_iter->d_name, "..") == 0) {
            continue;
        }

        char path[SIZE];
        strcpy(path, "tmp/");
        strcat(path, dir_iter->d_name);

        struct stat fileStat;
        if (stat(path, &fileStat) == -1) {
            printf("Cannot get stat from file\n");
            exit(1);
        }

        if (fileStat.st_nlink >= 2) {
            char s[SIZE];
            sprintf(s, "find ./tmp -inum %lu", dir_iter->d_ino);

            FILE *fp = popen(s, "r");
            if (fp == NULL) {
                printf("Error during execution of the command %s\n", s);
            }

            char buffer[SIZE];
            printf("%s - ", dir_iter->d_name);

            int first = 1;
            while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
                if (!first) printf(", ");
                printf("%s", str_replace(buffer, "\n", ""));
                first = 0;
            }
            printf("\n");
        }
    }

    return(0);
}
