# Linux Tablet Mode Controller

This service detects when the laptop is in tablet or laptop mode and changes display settings accordingly.

This has only been tested and proven working on a Lenovo Ideapad Flex 5 with Linux Mint installed.

I am looking to make the service more flexible to easily setup on other devices.

## Setup

Copy the binary file into `/usr/local/bin` for the script.

Copy the rule file into `/etc/udev/rules.d` to ensure that the event file for the laptop hinge is always readable by the user.

Copy the systemd service file into `/etc/systemd/user` to allow the script to run as a service.

Run the service as the user:

```bash
systemctl --user daemon-reload
systemctl --user start tablet-mode.service
```

Test it is working, if check the service with:

```bash
systemctl --user status tablet-mode.service
```

If it is working, enable it to run on startup

```bash
systemctl --user enable table-mode.service
```
