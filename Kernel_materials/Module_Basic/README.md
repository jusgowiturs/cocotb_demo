 tree .
.
├── Makefile
├── README.md
└── simple_kernel_module.c

1 directory, 3 files

 make all
make -C /home/jusgowiturs/arm-kernel/linux-6.6 M=/mnt/d/BS_ES/EL_FPGA/coco_tb/cocotb_demo/Kernel_materials/Module_Basic ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules
make[1]: Entering directory '/home/jusgowiturs/arm-kernel/linux-6.6'
  CC [M]  /mnt/d/BS_ES/EL_FPGA/coco_tb/cocotb_demo/Kernel_materials/Module_Basic/simple_kernel_module.o
make[3]: Warning: File '/mnt/d/BS_ES/EL_FPGA/coco_tb/cocotb_demo/Kernel_materials/Module_Basic/modules.order' has modification time 0.45 s in the future
  MODPOST /mnt/d/BS_ES/EL_FPGA/coco_tb/cocotb_demo/Kernel_materials/Module_Basic/Module.symvers
make[3]: warning:  Clock skew detected.  Your build may be incomplete.
make[3]: Warning: File '/mnt/d/BS_ES/EL_FPGA/coco_tb/cocotb_demo/Kernel_materials/Module_Basic/simple_kernel_module.o' has modification time 0.13 s in the future
  CC [M]  /mnt/d/BS_ES/EL_FPGA/coco_tb/cocotb_demo/Kernel_materials/Module_Basic/simple_kernel_module.mod.o
  LD [M]  /mnt/d/BS_ES/EL_FPGA/coco_tb/cocotb_demo/Kernel_materials/Module_Basic/simple_kernel_module.ko
make[3]: warning:  Clock skew detected.  Your build may be incomplete.
make[1]: Leaving directory '/home/jusgowiturs/arm-kernel/linux-6.6'

.
├── Makefile
├── Module.symvers
├── README.md
├── modules.order
├── simple_kernel_module.c
├── simple_kernel_module.ko
├── simple_kernel_module.mod
├── simple_kernel_module.mod.c
├── simple_kernel_module.mod.o
└── simple_kernel_module.o

1 directory, 10 files