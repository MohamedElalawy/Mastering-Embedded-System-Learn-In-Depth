# Code size with Optimization level O3:
![Screenshot 2025-04-23 225432](https://github.com/user-attachments/assets/6a27d145-7a36-44d2-9ef4-c6a672ac5a38)
# Code size with volatile:
![image](https://github.com/user-attachments/assets/7bd11bf9-c0df-42bb-a633-d086531d001c)
# Volatile Type Qualifier:
- **Purpose**: The `volatile` qualifier tells the compiler that the variable can change at any time, often due to external factors like hardware registers or interrupt service routines.
- **Optimization Impact**: The compiler cannot optimize accesses to `volatile` variables, meaning it will "always read from memory" instead of using cached values.
