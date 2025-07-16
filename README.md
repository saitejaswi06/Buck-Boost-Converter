# Buck-Boost-Converter

# ⚡ 150W Buck-Boost Converter | 100V → 50V/230V | 20 kHz Switching Frequency  

> A high-efficiency, dual-mode buck-boost DC-DC converter supporting both **step-up (Boost)** and **step-down (Buck)** operations. Designed, simulated, and implemented for UPS and renewable energy systems.

---

## 📌 **Project Overview**

- **Input Voltage:** 100 V DC  
- **Output Voltage:** 50 V (Buck Mode) or 230 V (Boost Mode)  
- **Rated Power:** 150 W  
- **Switching Frequency:** ~20 kHz PWM (controlled by Arduino UNO)  
- **Topology:** Buck-Boost Converter using IRF740 MOSFET & TLP250 gate driver  
- **Use Case:** Power conversion for UPS battery charging and inverter supply during outages.

---

## ⚙️ **Technical Highlights**

### ✅ Simulation & Design
- Verified boost and buck operation using **MATLAB simulations** and **analytical calculations**.
- Simulated component ratings to ensure voltage/current safety margins before fabrication.

### ✅ Component Selection
| Component | Specification |
|----------|----------------|
| MOSFET   | IRF740, 400 V, 10 A |
| Diode    | MUR860, 600 V, 8 A |
| Inductor | 4 mH, custom-wound, ferrite EE55 |
| Capacitor| 20 uF, 250 V electrolytic |
| Gate Driver | TLP250 (5 V → 15 V isolated drive) |
| PWM Control | Arduino Uno (20 kHz PWM using Timer1) |

---

## 🔬 **Control Logic (PWM Duty Cycle)**

| Mode   | Output Voltage | Duty Cycle |
|--------|----------------|------------|
| Boost  | 230 V          | ~69.7%     |
| Buck   | 50 V           | ~33.3%     |

- **PWM Generation:**  
  - Used Arduino Uno's Timer1 in Fast PWM mode (~20 kHz).
  - Generated PWM signals on pins 9 and 10.

---

## 🛠️ **PCB & Circuit Design**

- Designed the schematic and PCB in **Proteus**.
- Verified critical voltages and current ratings through simulation before fabrication.
- Optimized PCB layout for minimal noise and heat dissipation.

---

## 🔩 **Key Design Calculations**

- **Inductor Design:**  
  - EE55 ferrite core, 90 turns of AWG20 copper wire.  
  - Inductance: 4 mH, saturation current: ~2 A.
- **Capacitance:**  
  - Calculated ~10 uF; used 20 uF for reduced ripple.
- **Snubber Circuit:**  
  - 100 kΩ resistor + 0.1 uF capacitor to suppress switching noise.

---

## ⚡ **Gate Driver Circuit (TLP250)**

- Converts 5 V PWM logic to isolated 15 V gate drive for high-side switching.
- Included:
  - **Gate Resistor (100 Ω):** controls switching speed & EMI.
  - **Pull-Down Resistor (10 kΩ):** discharges gate when off.
  - **Bypass Capacitor:** stabilizes Vcc supply.

---

## 🔧 **Inductor Fabrication Steps**
- **Core:** EE55 Ferrite (MnZn material).
- **Calculated Turns:** ~90 turns of AWG20 wire.
- **Measured Saturation Current:** ~1.5–2 A.
- Hand-wound, verified using LCR meter.

---

## 🔋 **Applications**

- **UPS Systems:**  
  - Buck mode: charge a 48 V battery from 100 V DC.  
  - Boost mode: step-up battery voltage to 230 V for powering AC loads.
  
- **Renewable Energy:**  
  - Stabilizing variable DC inputs from solar or battery sources.

---

## ✅ **Conclusion**

This project successfully implements a 150 W buck-boost converter with:
- Efficient voltage regulation across load variations.
- Robust gate driving and protection circuitry.
- Practical real-world applications in energy systems.

---


---

## 🔗 **Future Work**
- Closed-loop feedback with voltage & current sensing.
- Higher frequency operation using dedicated PWM ICs.
- Efficiency analysis under real load conditions.
