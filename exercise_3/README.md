# Conceptual Questions

1. What is an operating system? Can you give some responsibilities of an operating system? 

Creates the link between User Programs and the computer hardware. Its tasks include memory as well as CPU time allocation for the User program. It also can grant access to hardware for UP.

2. How does the scheduling (execution of tasks) differ between real-time operating systems and regular operating systems?  

The execution of tasks in regular operating systems occurs at a much lower execution rate than in RTOS. This makes RTO systems very useful when real-time data reading/writing is necessary (e.g. A rocket flight software).

3. Identify and explain two ways in which we can share data between tasks.  

Data can be shared using a data buffer or Mutexes. With a data buffer, the stram of data is sent from task A to B. Mutexes on the other hand allow for the use of data by multiple tasks, granting access to that data one task at a time. I see it like a "Talking Stick", where the task with the mutex has to return it after use for the next one to grab it.
 
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

1. Button activation task. Remains in suspended state, until pressed. When pressed,will send a notification to the sensor reading tasks that activates them.
2. Sensor Tasks: Include a sensor reading task for each of the sensors. When the general activation signal is sent, tasks run a reading routine. Upon completion, there is an individual stream buffer from each task to the comms task. 
3. Communication task stores data. Upon receiving data from all sensors, it sends a notification to the LED activation task.
4. LED activation task turns on the LED light when the Communication Task successfully runs. It has a CLCK timer that will activate the light at a certain frequency for a certain amount of time.