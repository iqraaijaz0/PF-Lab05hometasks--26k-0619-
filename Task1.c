#include <stdio.h>

int main() {
    int status = 0; 
    int op, device, mode;
    int bit = 0;

    printf("Enter initial system status (0-15): ");
    scanf("%d", &status);

    printf("\n--- PART 1: SELECT OPERATION ---\n");
    printf("1. Activate Device\n2. Deactivate Device\n3. Check Status\n4. Toggle Device\n");
    printf("Select operation (1-4): ");
    scanf("%d", &op);

    printf("Select Device (1: Door Lock, 2: Alarm, 3: CCTV, 4: Motion): ");
    scanf("%d", &device);

    switch(device) {
        case 1: bit = 1 << 0; break; 
        case 2: bit = 1 << 1; break; 
        case 3: bit = 1 << 2; break; 
        case 4: bit = 1 << 3; break; 
        default: printf("Invalid Device!\n"); return 0;
    }

    switch(op) {
        case 1:
            status = status | bit;
            break;
        case 2:
            status = status & (~bit);
            break;
        case 3:
            if (status & bit) {
                printf("Device is ACTIVE\n");
            } else {
                printf("Device is INACTIVE\n");
            }
            break;
        case 4:
            status = status ^ bit;
            break;
        default:
            printf("Invalid Operation!\n");
            return 0;
    }

    printf("\n--- PART 2: SELECT SECURITY MODE ---\n");
    printf("1. Home Mode\n2. Away Mode\n3. Night Mode\n");
    printf("Select mode (1-3): ");
    scanf("%d", &mode);

    switch(mode) {
        case 1:
            status = status | (1 << 0) | (1 << 2);
            break;
        case 2:
            status = status | (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
            break;
        case 3:
            status = status | (1 << 0) | (1 << 1) | (1 << 3);
            break;
        default:
            printf("Invalid Mode!\n");
    }

    int b3 = (status >> 3) & 1;
    int b2 = (status >> 2) & 1;
    int b1 = (status >> 1) & 1;
    int b0 = (status >> 0) & 1;

    printf("\n------ FINAL STATUS ------\n");
    printf("Binary Status: %d%d%d%d\n", b3, b2, b1, b0);

    printf("Door Lock: %s\n", (status & (1 << 0)) ? "Active" : "Inactive");
    printf("Alarm System: %s\n", (status & (1 << 1)) ? "Active" : "Inactive");
    printf("CCTV Camera: %s\n", (status & (1 << 2)) ? "Active" : "Inactive");
    printf("Motion Sensor: %s\n", (status & (1 << 3)) ? "Active" : "Inactive");

    if ((status & 15) == 15) {
        printf("System Status: FULLY ARMED\n");
    } else {
        printf("System Status: NOT FULLY ARMED\n");
    }

    return 0;
}
