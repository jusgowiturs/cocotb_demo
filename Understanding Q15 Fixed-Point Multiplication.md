
### Understanding Q15 Fixed-Point Multiplication

In **Q15 format**, numbers are represented using **16 bits**, where:

- **1 bit** is for the sign (two's complement)
- **15 bits** are for the fractional part

So, the numerical range of Q15 is approximately:
\[
-1.0 \leq x < 1.0
\]
where:
\[
x_\text{real} = \frac{x_\text{integer}}{2^{15}}
\]

---

### Step 1: Multiplying Two Q15 Numbers

Suppose we multiply two Q15 numbers, `a` and `b`:

\[
a = A / 2^{15}, \quad b = B / 2^{15}
\]

Their product in real terms is:
\[
a \times b = \frac{A}{2^{15}} \times \frac{B}{2^{15}} = \frac{A \times B}{2^{30}}
\]

But the hardware integer multiplication produces a **32-bit result (Q30)**:
\[
A \times B = \text{Q30 format (since 15 + 15 = 30 fractional bits)}
\]

---

### Step 2: Scaling Back to Q15

To return the result to **Q15 format**, we must remove 15 fractional bits:

\[
\text{Q15 result} = (A \times B) \gg 15
\]

This is a **right arithmetic shift by 15 bits**, effectively dividing by \( 2^{15} \):
\[
\frac{A \times B}{2^{30}} \times 2^{15} = \frac{A \times B}{2^{15}}
\]

Thus, the result is again scaled as a Q15 number.

---

### Step 3: Example

Let’s take:
\[
a = 0.5, \quad b = 0.5
\]

In Q15:
\[
a = 0.5 \times 2^{15} = 16384, \quad b = 16384
\]

Multiply as integers:
\[
A \times B = 16384 \times 16384 = 268{,}435{,}456
\]

Shift right by 15:
\[
(268{,}435{,}456) \gg 15 = 8192
\]

Convert back to real:
\[
8192 / 2^{15} = 0.25
\]

✅ The result is correct: \( 0.5 \times 0.5 = 0.25 \).

---

### Step 4: Key Points

- Q15 multiplication → Q30 result (double precision).
- To restore Q15 format → shift right by 15 bits.
- Watch for **overflow** (results exceeding ±1.0 range).
- Often implemented in DSPs as:
  ```c
  result = (int16_t)(( (int32_t)a * (int32_t)b ) >> 15);
