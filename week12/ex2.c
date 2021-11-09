#include <stdio.h>
#include <linux/input.h>
#include <dirent.h>

int main (void)
{
    struct input_event event;

    FILE* file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "rb");
    if (file == NULL)
    {
        printf("No such file");
        return -1;
    }

    while (fread((void*) &event, sizeof(struct input_event), 1, file)) {
        if (event.type == EV_KEY){
            if (event.value == 1) {
                printf("PRESSED");
            }
            else if (event.value == 0) {
                printf("RELEASED");
            } else {
                continue;
            }
            printf(" 0x%04x (%d)\n", event.code, event.code);
            fflush(stdout);
        }
        
    }

    return 0;
}
