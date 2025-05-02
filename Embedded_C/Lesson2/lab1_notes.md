![Screenshot 2025-04-29 190925](https://github.com/user-attachments/assets/dada4025-cbc7-4147-bdc7-98ec8fc5e320)



![Screenshot 2025-04-29 193958](https://github.com/user-attachments/assets/05733ce0-1bf7-40a6-b244-a2065a827c07)

![Screenshot 2025-04-29 194028](https://github.com/user-attachments/assets/abc2d4fc-5398-4bed-830b-a01f87daa8be)
![Screenshot 2025-04-29 194315](https://github.com/user-attachments/assets/a1d56291-80e5-47d4-82e2-c8db50ed4ad9)
![Screenshot 2025-04-29 202446](https://github.com/user-attachments/assets/0af59414-6dec-45c8-bc10-228d83a83a8f)
![Screenshot 2025-04-30 183513](https://github.com/user-attachments/assets/860d79eb-5ff2-48ea-bbcf-d8a8d9698741)
![Screenshot 2025-04-30 183941](https://github.com/user-attachments/assets/a9ac376c-ac57-478d-a87b-762a1a40bf54)
![Screenshot 2025-04-30 203559](https://github.com/user-attachments/assets/c4a68179-1cd4-4934-82d9-0b94d7e138c2)
![Screenshot 2025-04-30 224209](https://github.com/user-attachments/assets/b45d1139-42c5-40ea-858f-e5d0c3f44dd3)
![Screenshot 2025-04-30 224344](https://github.com/user-attachments/assets/0add99e6-0d71-4153-b709-d1d2338b991f)
![Screenshot 2025-04-30 232905](https://github.com/user-attachments/assets/83878df4-b673-4de7-8cec-c7d9d8c79c4a)
![Screenshot 2025-04-30 233026](https://github.com/user-attachments/assets/dcac34ca-7b75-415d-9b3f-dc3824f5ae97)
![Screenshot 2025-04-30 233528](https://github.com/user-attachments/assets/f0346aee-3b17-498d-bcbe-fec07376d950)
![Screenshot 2025-05-01 122914](https://github.com/user-attachments/assets/d68ac101-7311-47fe-9a74-e897c19a03ff)

![Screenshot 2025-05-01 124249](https://github.com/user-attachments/assets/57fc1276-367c-4d14-a27b-92b716a60100)
![Screenshot 2025-05-01 124842](https://github.com/user-attachments/assets/a2eee582-d3a6-4a37-9be7-47584e3d9027)
![Screenshot 2025-05-01 125836](https://github.com/user-attachments/assets/042984a6-6579-48c0-966f-b46038d7c3cc)
![Screenshot 2025-05-01 131021](https://github.com/user-attachments/assets/3a2b8e64-7128-45cb-9b95-5ede60086260)

---
![image](https://github.com/user-attachments/assets/3c79c0f0-170a-4029-9f88-c82960cc7c2c)



# QEMU Command Explanation

The following command launches QEMU to emulate an ARM-based system for debugging bare-metal programs:

```bash
qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel lab1.bin
```

## Options Breakdown

| Option          | Description |
|-----------------|-------------|
| `qemu-system-arm` | QEMU executable for ARM system emulation. |
| `-M versatilepb`  | Emulates the **ARM Versatile Platform Baseboard** (a common development board). |
| `-m 128M`        | Allocates **128MB of RAM** to the emulated machine. |
| `-nographic`     | Disables graphical output; redirects all I/O to the terminal. |
| `-s`             | Enables a **GDB server** on default port `1234` for debugging. |
| `-S`             | **Pauses the CPU** at startup (requires GDB to resume execution). |
| `-kernel lab1.bin` | Loads the bare-metal ARM binary `lab1.bin` as the kernel. |

---

![image](https://github.com/user-attachments/assets/2cc718cb-eff7-4159-8ddb-03081c5293f2)

