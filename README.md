# STM32 FreeRTOS Manual Port (STM32F411)

This project demonstrates **manual FreeRTOS integration on STM32F4 (Cortex-M4)** using **STM32CubeIDE**, without CubeMX RTOS middleware.

Target MCU: **STM32F411**

---

# Project Structure

```
bp_vera_path
│
├── Src
├── Inc
├── Startup
└── rtos
     ├── include
     │    ├── FreeRTOS.h
     │    ├── task.h
     │    ├── queue.h
     │    ├── semphr.h
     │    ├── timers.h
     │    └── ...
     ├── portable
     │    ├── GCC/ARM_CM4F
     │    │    ├── port.c
     │    │    └── portmacro.h
     │    └── Memmanage
     │         └── heap_4.c
     ├── FreeRTOSConfig.h
     ├── croutine.c
     ├── tasks.c
     ├── queue.c
     ├── list.c
     ├── timers.c
     ├── event_groups.c
     └── stream_buffer.c
```

`FreeRTOSConfig.h` is placed inside the **rtos folder** along with kernel sources.

---

# Method 1 — Copy FreeRTOS into Project

Copy the FreeRTOS kernel into the project directory.

Required kernel files:

```
tasks.c
queue.c
list.c
timers.c
event_groups.c
stream_buffer.c
croutine.c
```

Port layer:

```
portable/GCC/ARM_CM4F/port.c
```

Memory manager:

```
portable/Memmanage/heap_4.c
```

Include directories:

```
rtos/include
rtos/portable/GCC/ARM_CM4F
rtos/portable/Memmanage
```

---

# Method 2 — Link External FreeRTOS Folder

Instead of copying the kernel, an external folder can be linked.

Example location:

```
/home/user/Documents/rtos
```

Steps:

1. Right click project → **New → Folder**
2. Select **Advanced → Link to alternate location**
3. Choose the external `rtos` directory
4. Add include paths:

```
/home/user/Documents/rtos/include
/home/user/Documents/rtos/portable/GCC/ARM_CM4F
/home/user/Documents/rtos/portable/Memmanage
```

Ensure the following files are compiled:

```
tasks.c
queue.c
list.c
timers.c
event_groups.c
stream_buffer.c
croutine.c
port.c
heap_4.c
```

---

# Build

```
Project → Clean
Project → Build
```

---

# Environment

| Component | Value         |
| --------- | ------------- |
| MCU       | STM32F411     |
| Core      | ARM Cortex-M4 |
| IDE       | STM32CubeIDE  |
| Toolchain | ARM GCC       |
| RTOS      | FreeRTOS      |

---

# Notes

• Demonstrates **manual FreeRTOS porting**.

• Kernel sources and configuration are kept inside the `rtos` directory

• External linking allows multiple projects to share the same FreeRTOS source.

• I have used STM32F411CEU6 Board, While using other boards do not forget to include   the neccessary (eg. STM32Cube_FW_F4 Drivers) paths for your board.

• Edit the FreeRTOSConfig.h file for your usage/different board.

• IMPORTANT - Right click rtos folder and select properties and then check it for Exclude from build.



