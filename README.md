# STM32 FreeRTOS Manual Port (STM32F411)

This project demonstrates **manual FreeRTOS integration on STM32F4 (Cortex-M4)** using **STM32CubeIDE**, without CubeMX RTOS middleware.

Target MCU: **STM32F411**

---

# Project Structure

```id="x1"
bp_vera_path
│
├── Src
├── Inc
├── Startup
└── rtos
     ├── include
     ├── portable
     │     ├── GCC/ARM_CM4F
     │     └── MemMang
     ├── FreeRTOSConfig.h
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

```id="x2"
tasks.c
queue.c
list.c
timers.c
event_groups.c
stream_buffer.c
```

Port layer:

```id="x3"
portable/GCC/ARM_CM4F/port.c
```

Memory manager:

```id="x4"
portable/MemMang/heap_4.c
```

Include directories:

```id="x5"
rtos/include
rtos/portable/GCC/ARM_CM4F
rtos/portable/MemMang
```

---

# Method 2 — Link External FreeRTOS Folder (Advanced)

Instead of copying the kernel, an external folder can be linked.

Example location:

```id="x6"
/home/user/Documents/rtos
```

Steps:

1. Right click project → **New → Folder**
2. Select
   **Advanced → Link to alternate location**
3. Choose the external `rtos` directory.
4. Add include paths:

```id="x7"
/home/user/Documents/rtos/include
/home/user/Documents/rtos/portable/GCC/ARM_CM4F
/home/user/Documents/rtos/portable/MemMang
```

Ensure the following files are compiled:

```id="x8"
tasks.c
queue.c
list.c
timers.c
event_groups.c
stream_buffer.c
port.c
heap_4.c
```

---

# Build

```id="x9"
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
• Kernel sources and configuration are kept inside the `rtos` directory.
• External linking allows multiple projects to share the same FreeRTOS source.

