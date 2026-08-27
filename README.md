# CAN-Based-Vehicle-Safety-Monitoring-System
CAN-Vehicle-Safety-Monitoring
[27/08, 08:04] Anji😇😇: CAN-Based Vehicle Safety & Monitoring System using LPC2129
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
Block Diagram
[27/08, 08:05] Anji😇😇: Block Diagram
Block Diagram

🏗 System Architecture
🔹 Main Node
Reads Engine Temperature
Controls LCD Dashboard
Sends Indicator Commands
🟢 SAFE
vechicle_dashboard_main_node	
🟡 WARM
Warm_condition
🔴 HOT / OVERHEATED
Hot_condition
[27/08, 08:07] Anji😇😇: ⬅ LEFT INDICATOR
Left_indicator Left_indicator_1

➡ RIGHT INDICATOR
Right_indicator Right_Indicator_1


🚗 Receives Reverse Alerts 🚗


🟢 PATH CLEAR
Reverse mode Path is clear	
⚠ OBJECT NEARBY
Object nearby
🚨 OBJECT DETECTED
[27/08, 08:08] Anji😇😇: Indicator Node
Controls Left/Right Indicators
Receives CAN Commands
🔹 Reverse Alert Node
Reads Ultrasonic Sensor Data
Sends Obstacle Alerts to Main Node
⚙ Hardware Requirements
Component	Description
LPC2129	ARM7 Microcontroller
MCP2551	CAN Transceiver
HC-SR05	Ultrasonic Sensor
DS18B20	Temperature Sensor
20x4 LCD	Display Unit
LEDs	Indicator Simulation
Buzzer	Warning Alert
Switches	External Interrupts
USB-UART	Programming Interface
💻 Software Requirements
Embedded C
Keil uVision
Flash Magic
Proteus Simulation
📂 Repository Structure
CAN-Based-Vehicle-Safety-Monitoring-System
│
├── Main_Node
├── Indicator_Node
├── Reverse_Alert_Node
│
├── Drivers
│   ├── LCD
│   ├── CAN
│   ├── Ultrasonic
│   ├── DS18B20
│   └── Delay
│
├── Proteus_Simulation
├── Circuit_Diagrams
├── Images
├── Documentation
│
├── README.md
└── LICENSE
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
Balaji Sai Kumar Mangena
Embedded Systems Enthusiast

Passionate about Embedded Systems, Firmware Development,
and Automotive Embedded Technologies.