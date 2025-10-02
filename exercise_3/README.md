# Conceptual Questions

1. What is an operating system? Can you give some responsibilities of an operating system? 
- Operating System - A software that serves as an intermediate layer between the user's programs and the computer's hardware, handling interactions between both 
- Responsibilities:
    - Allocating resources for running a video game
    - Delegating memory for programs that are running
    - Finding the address of something stored in the hard drive
2. How does the scheduling (execution of tasks) differ between real-time operating systems 
and regular operating systems?  
- There is a slight delay between the execution of tasks in real-time operating systems, while it is essentially instantaneous in real-time operating systems.

3. Identify and explain two ways in which we can share data between tasks.  
- Streamed Buffer - A "pipe" that enables communication between two tasks
- Mutex - A feature that allows an arbritary number of tasks to access and modify a shared resource while preventing a conflict between the actions of the tasks

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

- Sensor Task:
    - Shares data with the communication task through a streamed buffer
    - Waits on notification from the button ISR for an immediate read within a certain timeout (otherwise do regular read)

- Communication Task:
    - Receives notification from sensor task to begin transmitting data to the UART module
    - Receives sensor data from the sensor task through a streamed buffer
    - Transmits confirmation to LED task through a notification after data is sent successfully to UART module from an immediate reading 

- LED/Button Task:
    - Transmits to Sensor task through a notification to let it know to collect measurements immediately when the button is pressed
    - Transmits to Communication task through a streamed buffer to share that the button was pressed and the next communication from the sensor task will be an immediate reading
    - Receives confirmation of data collection from Communication task through a notification, blinking the LED