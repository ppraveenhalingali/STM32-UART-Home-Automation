# 🏠 UART Controlled Home Automation using STM32

A UART-based Home Automation System developed using the **STM32F103C8T6 (Blue Pill)** microcontroller. This project demonstrates real-time control of home appliances through serial communication by receiving commands over UART and controlling GPIO outputs. The firmware was developed using **Keil µVision** and validated through **Proteus simulation**.

---

## 📖 Project Overview

Home automation systems improve convenience and energy efficiency by allowing users to control electrical appliances electronically. This project uses the UART communication protocol to receive commands from a serial terminal and control connected devices.

The STM32 microcontroller continuously listens for UART commands. Based on the received command, it switches the corresponding appliance ON or OFF by controlling GPIO pins.

This project demonstrates practical implementation of UART communication, GPIO interfacing, and embedded firmware development using STM32.

---

## 🎯 Objectives

- Learn UART communication using STM32.
- Interface GPIO peripherals with STM32.
- Control home appliances using serial commands.
- Develop embedded firmware using Embedded C.
- Simulate the complete system using Proteus.

---

## ✨ Features

- UART Serial Communication
- Real-Time Device Control
- GPIO-Based Appliance Switching
- Embedded C Firmware
- Keil µVision Development
- Proteus Simulation
- Simple and Expandable Design

---

## 🛠 Hardware Requirements

- STM32F103C8T6 (Blue Pill)
- USB-to-UART Converter (FTDI/CP2102)
- LEDs or Relay Module
- Breadboard
- Connecting Wires
- Power Supply

---

## 💻 Software Requirements

- Keil µVision 5
- Proteus Professional
- Embedded C
- Serial Terminal (PuTTY / Tera Term / Hercules)

---

## 📂 Repository Structure

```
UART-Controlled-Home-Automation-using-STM32/

│── main.c
│── UART_Controlled_Home_Automation.hex
│── UART_Controlled_Home_Automation.pdsprj
│── Project_Output.png
└── README.md
```

---

## ⚙ Working Principle

1. Initialize the STM32 microcontroller.
2. Configure UART for serial communication.
3. Configure GPIO pins as outputs.
4. Wait for incoming UART commands.
5. Receive command through UART.
6. Compare the received command.
7. Switch the corresponding GPIO output.
8. Continue monitoring for new commands.

---

## 🔄 System Flow

```
              Start
                │
                ▼
     Initialize STM32 System
                │
                ▼
         Configure UART
                │
                ▼
         Configure GPIO
                │
                ▼
      Wait for UART Command
                │
                ▼
        Receive Command
                │
                ▼
      Is Command Valid?
          │          │
         No         Yes
          │          │
 Ignore Command   Execute Action
                     │
                     ▼
          Control LED / Relay
                     │
                     ▼
         Wait for Next Command
```

---

## 📡 UART Configuration

| Parameter | Value |
|-----------|-------|
| Communication | UART |
| Mode | Asynchronous |
| Baud Rate | 9600 bps *(or update as per your code)* |
| Data Bits | 8 |
| Stop Bits | 1 |
| Parity | None |

---

## 📨 Example Commands

| Command | Action |
|----------|--------|
| `1` | Turn Device ON |
| `0` | Turn Device OFF |

> Update these commands if your project uses different characters.

---

## ▶️ How to Run

### 1. Open the Project

Open the project in **Keil µVision**.

### 2. Build the Project

Compile the source code to generate the HEX file.

### 3. Open Proteus

Load the **UART_Controlled_Home_Automation.hex** file into the STM32 microcontroller in the Proteus simulation.

### 4. Start Simulation

Run the simulation.

### 5. Open Virtual Terminal

Use the Proteus Virtual Terminal (or a serial terminal in hardware implementation) to send UART commands.

### 6. Observe Output

The connected LEDs or relays will turn ON or OFF according to the received commands.

---

## 📷 Project Output

Add your project screenshot here.

```
Project_Output.png
```

---

## 📚 Applications

- Smart Home Automation
- Embedded Systems Learning
- UART Communication Demonstration
- Home Appliance Control
- Industrial Automation Prototypes

---

## 📈 Learning Outcomes

This project helped me understand:

- UART Communication Protocol
- STM32 Peripheral Programming
- GPIO Interfacing
- Embedded C Programming
- Keil µVision Development
- Proteus Simulation
- Firmware Debugging

---

## 🔮 Future Enhancements

- Bluetooth Control (HC-05)
- Wi-Fi Control using ESP8266/ESP32
- Mobile Application Integration
- IoT-Based Home Automation
- Voice Assistant Integration
- Sensor-Based Automatic Control
- LCD/OLED Status Display

---

## 👨‍💻 Author

**Praveen H**

Electronics and Communication Engineering

### Areas of Interest

- Embedded Systems
- STM32
- Firmware Development
- Internet of Things (IoT)
- Embedded AI

GitHub: https://github.com/ppraveenhalingali

---

## ⭐ Support

If you found this project useful, please consider giving it a ⭐ **Star** on GitHub.

---

## 📜 License

This project is developed for educational and learning purposes.
