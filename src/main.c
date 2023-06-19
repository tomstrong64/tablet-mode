#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/input.h>
#include <stdlib.h>

int main()
{
    int fd;
    const char *device = "/dev/input/event10";

    fd = open(device, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    struct input_event event;
    ssize_t bytesRead;

    while ((bytesRead = read(fd, &event, sizeof(event))) > 0)
    {
        if (event.type == EV_MSC && event.code == EV_MSC)
        {
            if (event.value == 0x42)
            {
                printf("Tablet mode\n");
                system("gsettings set org.cinnamon.settings-daemon.peripherals.touchscreen orientation-lock false");
                continue;
            }

            if (event.value == 0x43)
            {
                printf("Laptop mode\n");
                system("gsettings set org.cinnamon.settings-daemon.peripherals.touchscreen orientation-lock true");
                system("xrandr -o normal");
                continue;
            }

            printf("Unknown mode\n");
        }
    }

    close(fd);
    return 0;
}
