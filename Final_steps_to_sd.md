# PYNQ-Z1 Kernel Boot Notes

## 1. Preinstalled PYNQ Image Setup
- Downloaded prebuilt PYNQ image from [PYNQ Boards](https://www.pynq.io/boards.html).  
- Extracted and wrote to SD card using **Win32 Disk Imager**.  
- Default SD card contains:
  - `boot.bin`
  - `boot.scr`
  - `boot.py`
  - `uImage` (prebuilt kernel, optional)
  - Other PYNQ filesystem files.

---

## 2. Custom Kernel / DTB Setup
- Created a folder with:
  - `zImage` → from `arch/arm/boot/`  
  - `*.dtb` → from `out` folder (e.g., `zynq-zed-week6.dtb`)  

- Goal: build **U-Boot compatible image**.

---

## 3. Option 1 — FIT Image (`image.ub`) via ITS
### 3.1 Create ITS file (`image.its`)
```dts
/dts-v1/;

{
    description = "FIT image for PYNQ-Z1 kernel";
    #address-cells = <1>;

    images {
        kernel {
            description = "Linux kernel";
            data = /incbin/("zImage");
            type = "kernel";
            arch = "arm";
            os = "linux";
            compression = "none";
            load = <0x02000000>;
            entry = <0x02000000>;
        };
        fdt {
            description = "Flattened device tree";
            data = /incbin/("zynq-zed-week6.dtb");
            type = "flat_dt";
            arch = "arm";
            compression = "none";
            load = <0x01F00000>;
        };
    };

    configurations {
        default = "conf";
        conf {
            kernel = "kernel";
            fdt = "fdt";
            bootargs = "console=ttyPS1,115200 earlycon=cdns,mmio,0xE0001000,115200n8 keep_bootcon cpufreq.off=1 clk_ignore_unused root=/dev/mmcblk0p2 rw";
        };
    };
};
```
### 3.2 Generate FIT Image
```bash
mkimage -f image.its image.ub 
mkimage -f image.its uImage # works only when uImage is used

```
- Output: image.ub (FIT image containing kernel + DTB + configuration)
- Copy image.ub to root of SD card FAT partition with boot.scr.
### 3.3 Boot FIT Image in U-Boot


## 4. Option 2 — Legacy uImage + Separate DTB
### 4.1 Generate uImage from zImage
```bash
mkimage -A arm -O linux -T kernel -C none -a 0x02000000 -e 0x02000000 -n "PYNQ Kernel" -d zImage uImage

```
- Output: uImage (legacy U-Boot kernel format)
- Works even if preinstalled boot.bin has limited FIT support.

### 4.2 Boot Legacy uImage with DTB
```bash
mmc dev 0
mmc rescan
load mmc 0:1 0x02000000 uImage
load mmc 0:1 0x01F00000 zynq-zed-week6.dtb
bootm 0x02000000 - 0x01F00000
```
- → no initrd

0x01F00000 → DTB location in RAM


## 5. Notes / Tips
- FIT images require correct U-Boot support. Use 
```
bootm 0xADDR#CONF if U-Boot complains.
```
- Ensure SD card first FAT partition contains:
  - boot.bin
  - boot.scr
  - image.ub   # or uImage
  
-   iminfo 0xADDR can verify image validity:
    -   FIT image → shows components + configurations
    -   Legacy uImage → shows kernel info
        -   #address-cells = <1> in ITS/DTS is standard for RAM address references in FIT images.
    - Keep zImage entry = load address to ensure kernel starts correctly.
## Summary

-   FIT image (image.ub) → cleaner, single file with kernel + DTB + config, preferred if U-Boot supports it.
-   Legacy uImage + DTB → fallback for prebuilt boot.bin with older U-Boot.
-   Always check SD card paths and filenames; U-Boot is case-sensitive.

