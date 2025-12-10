echo "Creating Folders KERNEL_SRC/include KERNEL_SRC/scripts KERNEL_SRC/arch/arm 
"
mkdir -p KERNEL_SRC/include KERNEL_SRC/scripts KERNEL_SRC/arch/arm && \
rsync -av --ignore-missing-args \
  --include='include/***' --include='scripts/***' --include='arch/arm/***' \
  --include='Makefile' --include='.config' --include='Module.symvers' \
  --include='System.map' --include='vmlinux' \
  --exclude='*' \
  ~/arm-kernel/linux-6.6/ KERNEL_SRC/
