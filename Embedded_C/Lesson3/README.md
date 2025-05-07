
<h3>🎥 Click the image below to watch proteus video:</h3>

<p align="center">
  <a href="https://drive.google.com/file/d/1m8SZkSOcJnzv1Kl4L9eIhOVl_aDJ_bMD/view?usp=drive_link" target="_blank">
    <img src="https://github.com/user-attachments/assets/2e26c3e1-8544-46ba-9b6a-d560814f1877" alt="Video 1" width="600"/>
  </a>
</p>

---

<h3>🎥 Click the image below to watch real HW video:</h3>

<p align="center">
  <a href="https://drive.google.com/file/d/1D98k3GSbeYJrsqTPkAw_QrGZxDlK3O9j/view?usp=drive_link" target="_blank">
    <img src="https://github.com/user-attachments/assets/c06b8edf-db0e-41cc-8615-2560e153de55" alt="Video 2" width="600"/>
  </a>
</p>

---
##  Why the Onboard LED on PC13 in STM32F103C8T6 is Inverted

###  Wiring of the Onboard LED

On the Blue Pill (STM32F103C8T6) board, the onboard LED connected to **pin PC13** is wired **between Vcc (3.3V)** and **PC13** via a resistor:

- **Anode** → Vcc (3.3V)
- **Cathode** → PC13 (GPIO pin)

This means:
- When **PC13 is set to HIGH (3.3V)** → both sides of the LED are at 3.3V → **no current flow → LED OFF**
- When **PC13 is set to LOW (0V)** → current flows from Vcc → through LED → to PC13 → **LED turns ON**

###  This Results in Inverted Logic

| GPIO Output | Voltage on PC13 | LED State |
|-------------|------------------|-----------|
| HIGH (3.3V) | Same as Vcc      | OFF       |
| LOW (0V)    | GND              | ON        |

### 🔌 External LED Behavior (Standard Wiring)

When connecting an **external LED**:
- **Anode** → PC13
- **Cathode** → GND

In this setup:
- **PC13 HIGH** → LED turns **ON**
- **PC13 LOW** → LED turns **OFF**

