#include <stdio.h>
#include <dirent.h>

int main (void)
{
    DIR *dp;
    struct dirent *dir_iter;

    dp = opendir("/");

    while ((dir_iter = readdir(dp)) != NULL) {
        puts(dir_iter->d_name);
    }
    closedir(dp);

    return 0;
}
