# 🔐 Data Encryption Standard (DES) Algorithm Simulation

This project demonstrates the **DES (Data Encryption Standard)** encryption and decryption algorithm using C. It simulates the key generation, initial/final permutations, and 16-round Feistel structure of DES.

---

## 📖 Overview

DES is a **symmetric block cipher** that encrypts plaintext data in 64-bit blocks using a 64-bit key (56 effective bits). It was a widely used encryption standard before being replaced by AES.

### 🔍 Key Concepts

- **Symmetric Cipher:** Same key for encryption and decryption
- **Block Size:** 64-bit blocks
- **Key Size:** 64-bit (56 bits effective)
- **Rounds:** 16 Feistel rounds with subkeys

---

## 🔁 DES Encryption Process

1. **Initial Permutation (IP):**  
   Rearranges 64-bit plaintext using a fixed IP table.

2. **Key Generation:**
   - Drop parity bits from 64-bit key → 56-bit key
   - Split into two 28-bit halves
   - Perform left shifts
   - Generate 16 subkeys (48-bit each)

3. **16 Feistel Rounds:**
   - Split data into Left (L) and Right (R)
   - Expand R (32 → 48 bits)
   - XOR with round key
   - S-box substitution → 32-bit output
   - P-box permutation
   - XOR with L and swap halves

4. **Final Permutation (FP):**  
   Apply inverse of IP to get the ciphertext.

---

## 🔄 Decryption

Same steps as encryption but apply the **subkeys in reverse order (K16 → K1)**.

---

## 💡 Example

### 🔢 Plaintext: `"HELLO123"` → ASCII → Binary
```text
H: 01001000
E: 01000101
L: 01001100
L: 01001100
O: 01001111
1: 00110001
2: 00110010
3: 00110011
```

Combined 64-bit plaintext:
01001000 01000101 01001100 01001100 01001111 00110001 00110010 00110011

## 🔐 Sample Key (Hex): 133457799BBCDFF1
Final Output Cipher (Hex):
29C3 50F3 47D8 70CA

---

## 🧠 Project Structure
```
DES_Algorithem/
├── des.c           # Main C program implementing DES
├── README.md       # Project documentation
```

---
##📌 Notes
DES is considered insecure for modern use due to brute-force vulnerabilities.
Historically used in the financial and government sectors.
Replaced by AES for higher security standards.

📄 License
This project is licensed under the MIT License.
Feel free to use and modify it for educational purposes.

🙋‍♂️ Author
Sarvam Patel
Computer Engineering Student | Developer | Open to Internships
🔗 GitHub: https://github.com/CoreTech7704
🔗 LinkedIn: https://www.linkedin.com/in/sarvam-patel-89a414300/
