# Conceptual Questions

1. What is an operating system? Can you give some responsibilities of an operating system? 
An operating system is software that acts as an abstraction from the hardware for user programs.
An operating system is responsible for memory managment, scheduling, and direct hardware interaction.

2. How does the scheduling (execution of tasks) differ between real-time operating systems 
and regular operating systems?
Scheduling on a regular operating system is designed to provide a good user experience without worrying too much about precise timing.
RTOS' are designed to respond quickly to real time events, meaning that they are much more particular about the timings for switching between tasks.

3. Identify and explain two ways in which we can share data between tasks.  
A stream buffer, which sends a "stream" of data directly from one task to another.
A notification, which sends a signal from one task to another.
---

# Design Exercise

Imagine you are developing a small weather station that must take sensor readings and transmit it to a radio over UART. The weather station must have the following components:

**Sensors**  
- Temperature, humidity, and wind speed sensors.  
- Data must be read periodically.  

**Communication module**  
- Sends sensor data over UART (or simulated wireless).  
- Data is serialized into a stream.  

**User interface button + LED**  
- Button press signals the system to take an immediate measurement.  
- LED blinks when data is successfully sent.  

---

## Task Architecture

Design a task architecture in FreeRTOS to handle these features. You should define the following three tasks:

- **Sensor Task**
    - Responsible for reading sensor data  
- **Communication Task**
    - Responsible for sending data to the UART module  
- **LED Task**
    - Responsible for blinking the LED after data is successfully sent  

Think about the FreeRTOS communication components we covered in the lecture (stream buffers, notifications). How can we leverage them to create a coherent application? 

**Create a list of communication components, noting the source and destination tasks, that can be used to synchronize the three tasks**

You do not need to provide any C code or even pseudocode. This exercise is meant to be highly conceptual, so don’t worry about the specific implementation of your task architecture.  

---

## Your Answer
Stream buffer from the Sensor Task to the Communication Task
Notification from the Button ISR to Sensor Task
Notification from the Communication Task to the LED Task that the data was successfully sent
