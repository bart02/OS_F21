#include <stdio.h>
#include <linux/input.h>
#include <dirent.h>

int last_keys[6];

void add_key(int key) {
    for (int i = 5; i > 0; i--) {
        last_keys[i] = last_keys[i-1];
    }
    last_keys[0] = key;
}

int main (void)
{
    struct input_event event;

    for (int i = 0; i < 6; i++) {
        last_keys[i] = -1;
    }

    FILE* file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "rb");
    if (file == NULL)
    {
        printf("No such file");
        return -1;
    }

    while (fread((void*) &event, sizeof(struct input_event), 1, file)) {
        if (event.type == EV_KEY){
            if (event.value == 1) {
                add_key(event.code);
                //printf("%d %d %d", last_keys[0], last_keys[1], last_keys[2]);
            } else {
                continue;
            }
            if (last_keys[0] == 18 && last_keys[1] == 25) printf("I passed the Exam!\n");
            if (last_keys[0] == 25 && last_keys[1] == 30 && last_keys[2] == 46) printf("Get some cappuccino!\n");
            if (last_keys[0] == 46 && last_keys[1] == 25) printf("It is my computer!\n");
            fflush(stdout);
        }
        
    }

    return 0;
}
