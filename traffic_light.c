#include <stdio.h>
#include <stdlib.h>
#include "ucos-ii/ucos_ii.h" // Include uCOS-II header file
#include "gui_library.h" // Include GUI library header file

// Define task priorities
#define TASK_PRIORITY_MESSAGE_BOX 5
#define TASK_PRIORITY_TRAFFIC_LIGHT_CONTROL 6

// Define task stack sizes
#define TASK_STACK_SIZE_MESSAGE_BOX 512
#define TASK_STACK_SIZE_TRAFFIC_LIGHT_CONTROL 512

// Define traffic light states
typedef enum {
    GREEN,
    YELLOW,
    RED
} TrafficLightState;

// Global variables for vehicle count and time interval
int vehicleCountNorth, vehicleCountSouth, vehicleCountEast, vehicleCountWest;
int timeInterval;

// Task prototypes
void Task_MessageBox(void *data);
void Task_TrafficLightControl(void *data);

int main(void) {
    // Initialize uCOS-II kernel
    OSInit();

    // Create tasks
    OSTaskCreate(Task_MessageBox, NULL, TASK_STACK_SIZE_MESSAGE_BOX, TASK_PRIORITY_MESSAGE_BOX);
    OSTaskCreate(Task_TrafficLightControl, NULL, TASK_STACK_SIZE_TRAFFIC_LIGHT_CONTROL, TASK_PRIORITY_TRAFFIC_LIGHT_CONTROL);

    // Start uCOS-II kernel
    OSStart();

    return 0;
}

// Task to update message box with vehicle count
void Task_MessageBox(void *data) {
    while (1) {
        // Update message box with vehicle count
        UpdateMessageBox(vehicleCountNorth, vehicleCountSouth, vehicleCountEast, vehicleCountWest);

        // Delay for a certain period
        OSTimeDly(1000); // Delay for 1 second
    }
}

// Task to control traffic lights based on time interval
void Task_TrafficLightControl(void *data) {
    while (1) {
        // Control traffic lights based on time interval
        ControlTrafficLights(timeInterval);

        // Delay for the specified time interval
        OSTimeDly(timeInterval * 1000); // Delay for the specified time interval in milliseconds
    }
}