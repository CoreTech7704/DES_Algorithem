# DES_Algorithem
Here’s a clear, concise, and well-formatted `README.md` file for your DES algorithm project, based on the content you provided:


# 🔐 Data Encryption Standard (DES) – Project README

## 📖 Overview

The Data Encryption Standard (DES) is a symmetric block cipher used for encrypting data. It was one of the most widely used encryption techniques before being replaced by the more secure Advanced Encryption Standard (AES).

- **Symmetric**: Same key is used for encryption and decryption.
- **Block Cipher**: Processes data in 64-bit blocks.
- **Key Size**: 64-bit key (56 effective bits after removing parity bits).
- **Rounds**: 16 rounds of encryption using 48-bit subkeys.


 🔁 DES Encryption Process

 1. Initial Permutation (IP)
The 64-bit plaintext is permuted based on a predefined IP table.

 2. Key Generation
- Input: 64-bit key.
- Remove parity bits → 56-bit effective key.
- Split into two 28-bit halves.
- Perform left circular shifts.
- Generate 16 round keys (48-bit each).

 3. 16 Rounds of Encryption (Feistel Structure)
Each round includes:
- Split input into **Left (L)** and **Right (R)**.
- Expand R from 32 → 48 bits.
- XOR with round key.
- Substitute using **S-boxes** to get 32-bit output.
- Permute with **P-box**.
- XOR with L and swap halves.

 4. Final Permutation (FP)
After 16 rounds, L and R are combined and passed through FP to generate the 64-bit ciphertext.


## 🔄 Decryption
The decryption process is the **reverse of encryption**, using the same keys in **reverse order** (K16 to K1).


 💡 Example

 🔢 Plaintext:
`"HELLO123"` → ASCII → Binary:

```
H: 01001000
E: 01000101
L: 01001100
L: 01001100
O: 01001111
1: 00110001
2: 00110010
3: 00110011
```

🔹 Combined 64-bit plaintext:

`01001000 01000101 01001100 01001100 01001111 00110001 00110010 00110011`


 🔐 Sample Key (Hex):  
`133457799BBCDFF1`

🔹 After processing (parity drop, shifting, etc.), subkeys are generated for 16 rounds.


🔄 Round Example:

- L0 and R0 split from IP output.
- R0 expanded to 48 bits.
- XOR with subkey K1.
- Substitution using S-boxes.
- Permutation using P-box.
- Swap L and R for next round.


🧾 Final Output:

Example Ciphertext (in Hex):

```
29C3 50F3 47D8 70CA
```


⚙️ Project Structure (if applicable)

```
├── des.c              # Main C file with DES implementation
├── README.md          # You are here
```


📌 Notes
- DES is not secure against modern brute-force attacks.
- Used historically in financial and defense sectors.
- Replaced by AES for stronger security.
