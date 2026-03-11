
#include "stm32f4xx.h"   // CMSIS device header
#include "FreeRTOS.h"
#include "task.h"

/* ---------- LED Task ---------- */
void LedTask(void *pvParameters)
{
    while (1)
    {
        GPIOC->ODR ^= (1U << 13);        // Toggle PA5
        vTaskDelay(pdMS_TO_TICKS(500)); // 500 ms delay
    }
}

int main(void)
{
    /* 1. Enable GPIOA clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    /* 2. Configure PA5 as output */
    GPIOC->MODER &= ~(3U << (13 * 2));
    GPIOC->MODER |=  (1U << (13 * 2));
    GPIOC->PUPDR &= ~(3U << (13 * 2));

    /* 3. Create FreeRTOS task */
    xTaskCreate(
        LedTask,     // pxTaskCode
        "LED",       // pcName
        256,         // usStackDepth (words)
        NULL,        // pvParameters
        1,           // uxPriority
        NULL         // pxCreatedTask
    );

    /* 4. Start scheduler */
    vTaskStartScheduler();

    while (1); // never reached
}
