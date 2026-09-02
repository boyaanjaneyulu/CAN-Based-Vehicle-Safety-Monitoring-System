CAN-Based Vehicle Safety & Monitoring System using LPC2129
📌 Project Overview
This project implements a CAN-Based Vehicle Safety & Monitoring System using the LPC2129 ARM7 Microcontroller.

The system is designed for automotive applications where multiple nodes communicate using the Controller Area Network (CAN) Protocol for real-time monitoring and safety operations.

The project includes:

Engine Temperature Monitoring
Reverse Obstacle Detection
CAN-Based Multi-Node Communication
Vehicle Indicator Control
LCD Dashboard UI
Real-Time Warning Alerts

🎯 Project Aim
To design and develop an automotive safety and monitoring system using the CAN Protocol, where a central node monitors engine temperature, controls vehicle indicators, and processes reverse sensor data to provide real-time safety alerts.

🖼 Block Diagram

<img width="1536" height="1024" alt="WhatsApp Image 2026-09-01 at 19 43 50" src="https://github.com/user-attachments/assets/1980316c-cdef-4f27-bb17-ea050e467297" />


🏗 System Architecture
🔹 Main Node
Reads Engine Temperature
Controls LCD Dashboard
Sends Indicator Commands
                     🟢 SAFE
<img width="1200" height="1600" alt="WhatsApp Image 2026-09-01 at 19 47 07" src="https://github.com/user-attachments/assets/c5478660-68c8-4ee7-8569-55d9c471d10d" />


                           🟡 WARM
<img width="552" height="250" alt="WhatsApp Image 2026-09-02 at 22 04 55" src="https://github.com/user-attachments/assets/e93d8e3d-a32b-4075-8ebe-612f37c15296" />



                          🔴 HOT / OVERHEATED
<img width="1600" height="1200" alt="WhatsApp Image 2026-09-01 at 19 47 07 (1)" src="https://github.com/user-attachments/assets/179ab580-b4d7-43a7-af9a-728ba18c5527" />
<img width="1200" height="1600" alt="WhatsApp Image 2026-09-01 at 19 47 07 (2)" src="https://github.com/user-attachments/assets/ce37fbf8-bd40-4d24-adef-a50e7b944e32" />


⬅ LEFT INDICATOR
<img width="1600" height="720" alt="WhatsApp Image 2026-09-01 at 19 47 07 (3)" src="https://github.com/user-attachments/assets/23eafac1-9f53-4cc2-9641-9d0994248928" />
<img width="1600" height="720" alt="WhatsApp Image 2026-09-01 at 19 47 08" src="https://github.com/user-attachments/assets/4bf53441-6530-4452-839f-abae6e3331af" />

<img width="1080" height="1244" alt="WhatsApp Image 2026-09-01 at 19 47 20" src="https://github.com/user-attachments/assets/3916f9a0-9c36-4c57-a9fc-244add0fc3e1" />


🚗 Receives Reverse Alerts 🚗
<img width="932" height="1599" alt="WhatsApp Image 2026-09-02 at 22 10 23" src="https://github.com/user-attachments/assets/4c9d4a1c-c7cb-460b-ae62-36c1c8b718f7" />

🔹 Indicator Node
   Controls Left/Right Indicators
   Receives CAN Commands
🔹 Reverse Alert Node
   Reads Ultrasonic Sensor Data
   Sends Obstacle Alerts to Main Node

<img width="1080" height="1332" alt="WhatsApp Image 2026-09-02 at 22 22 09" src="https://github.com/user-attachments/assets/991f3de4-d359-4235-acdd-1af03dfcbf5d" />


<img width="893" height="1600" alt="WhatsApp Image 2026-09-02 at 22 21 58" src="https://github.com/user-attachments/assets/7fc24205-2b61-4fb1-8d8b-aaa3cf6aa8ec" />


✅ Advantages

Real-Time Vehicle Monitoring
Reliable CAN-Based Communication
Improved Vehicle Safety System
Modular Multi-Node Architecture
Low Latency Data Transmission
Efficient Temperature Monitoring
Reverse Collision Warning Support
Easy Integration with Automotive Systems
Scalable for Future Vehicle Features
User-Friendly LCD Dashboard Interface

👨‍💻 Author

Boya Anjaneyulu 
Embedded Systems Enthusiast

Passionate about Embedded Systems, Firmware Development,
and Automotive Embedded Technologies.
