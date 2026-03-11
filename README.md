# FreeRTOS Porting on STM32 (STM32F411 / Cortex-M4)

This project demonstrates **manual FreeRTOS porting on STM32** using STM32CubeIDE.

Two methods can be used to include FreeRTOS in the project.

---

# Method 1 — Copy FreeRTOS into Project (Recommended)

Place the FreeRTOS kernel inside the project directory.

```
project/
│
├── Src
├── Inc
├── Startup
└── FreeRTOS
     ├── include
     ├── portable
     └── source files
```

### Steps

1. Download FreeRTOS kernel.
2. Copy these files into the project.

Kernel source files:

```
tasks.c
queue.c
list.c
timers.c
event_groups.c
stream_buffer.c
```

Port layer:

```
portable/GCC/ARM_CM4F/port.c
```

Memory manager:

```
portable/MemMang/heap_4.c
```

3. Add include paths in STM32CubeIDE:

```
FreeRTOS/include
FreeRTOS/portable/GCC/ARM_CM4F
FreeRTOS/portable/MemMang
```

4. Add `FreeRTOSConfig.h` in the `Inc` folder.

5. Build the project.

---

# Method 2 — Link External FreeRTOS Folder (Advanced)

Instead of copying FreeRTOS, you can **link an external directory**.

Example FreeRTOS location:

```
/home/user/Documents/rtos
```

### Steps

1. Right click project

```
New → Folder
```

2. Click

```
Advanced → Link to alternate location
```

3. Select the FreeRTOS directory.

Example:

```
/home/user/Documents/rtos
```

4. Add include paths:

```
/home/user/Documents/rtos/include
/home/user/Documents/rtos/portable/GCC/ARM_CM4F
/home/user/Documents/rtos/portable/MemMang
```

5. Ensure these files are compiled:

```
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

# Notes

• Method 1 is **simpler and recommended for beginners**.
• Method 2 allows **multiple projects to share the same FreeRTOS source**.
• If the external folder is moved or deleted, the project will fail to build.

---

# Target

* MCU: STM32F411 (Cortex-M4)
* Toolchain: ARM GCC
* IDE: STM32CubeIDE
* RTOS: FreeRTOS

