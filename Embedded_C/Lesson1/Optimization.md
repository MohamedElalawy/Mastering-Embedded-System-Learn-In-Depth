# Code size with Optimization level O3:
![Screenshot 2025-04-23 225432](https://github.com/user-attachments/assets/6a27d145-7a36-44d2-9ef4-c6a672ac5a38)
# Code size with volatile:
![image](https://github.com/user-attachments/assets/7bd11bf9-c0df-42bb-a633-d086531d001c)
# Volatile Type Qualifier:
- **Purpose**: The `volatile` qualifier tells the compiler that the variable can change at any time, often due to external factors like hardware registers or interrupt service routines.
- **Optimization Impact**: The compiler cannot optimize accesses to `volatile` variables, meaning it will "always read from memory" instead of using cached values.

### Common Use Cases:  
1. **Memory-Mapped Peripheral Registers**  
   - Hardware registers often change values independently of the CPU (e.g., status flags).  
   - Without `volatile`, the compiler might optimize away repeated reads, leading to incorrect behavior.  

2. **Global Variables Modified by an Interrupt Service Routine (ISR)**  
   - If an ISR updates a global variable, the main program must re-read it from memory each time.  
   - Example:  
     ```c
     volatile uint8_t sensor_data;  // Modified by an ISR
     ```

3. **Global Variables Accessed by Multiple Tasks in a Multi-Threaded Application**  
   - Prevents the compiler from caching values when shared across threads (though proper synchronization is still needed).  

### Why `volatile` Matters:  
- Ensures the compiler **always reads/writes directly to memory** instead of using cached values.  
- Not a substitute for proper synchronization (e.g., mutexes in multi-threading).  
