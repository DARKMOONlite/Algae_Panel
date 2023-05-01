# Arduino Control System

## How does it work?
The arduino based solution is built on top of a baremetal `Freertos` implementation. this means that individual components of the code are split into `tasks` and then are called up like a c++ coroutine based on their `priority`. This results in an easily expandible code base where new features can be added by adding new tasks to the scheduler.

## How to add new tasks?
1. Create a function declaration inside [rtos_tasks.h](/src/rtos_tasks.h), the function must return void and take a void pointer. the following is an example
```c++
    void TaskDrinkMilk(void *pvParameters)
```
2. create the connected function definition inside [rtos_tasks.cpp](/src/rtos_tasks.cpp). the following is a template for you to use.
```c++
void TaskDrinkMilk(void *pvParameters){
//run setup here this is done once
  GlassOfMilk tallglass(1,2);
  

  while(1){
    // add stuff here to add it to the task
    

    // if you need to access shared resources such as a serial connection. it is best to create a semapone ensure you can take it before accessing relavent information.
    if(xSemaphoreTake(xSerialSemaphore,(TickType_t) 5)==pdTRUE){

      
      xSemaphoreGive(xSerialSemaphore); // This returns the semaphore
    }
    vTaskDelay(1); // block the task for x number of ticks. increase to block this task running again within that period.
  }}

```

## Understanding FreeRTOS 
please look at the following pages to freeRTOS documentation

- [Task Creation](https://www.freertos.org/a00019.html)
- [Task Control](https://www.freertos.org/a00112.html)
- [Arduino RTOS Repository](https://github.com/feilipu/Arduino_FreeRTOS_Library?utm_source=platformio&utm_medium=piohome)