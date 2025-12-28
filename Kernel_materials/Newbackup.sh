#!/bin/bash
# minimal_kernel_copy.sh
# Copies only necessary files for out-of-tree ARM module builds

# Source kernel path
SRC_KERNEL=/home/jusgowiturs/arm-linux/linux-6.6
#mkdir KERNEL_SRC
# Destination minimal kernel tree
DEST_KERNEL=/mnt/d/BS_ES/EL_FPGA/src_img/no_init_emb/KERNEL_SRC

echo "Creating minimal kernel tree at $DEST_KERNEL..."

# Create required directories
mkdir -p "$DEST_KERNEL/include" "$DEST_KERNEL/scripts" "$DEST_KERNEL/arch/arm"

# Copy necessary files using rsync
rsync -av --ignore-missing-args \
  --include='Makefile' \
  --include='.config' \
  --include='Module.symvers' \
  --include='arch/arm/**' \
  --include='include/**' \
  --include='scripts/**' \
  --exclude='*' \
  "$SRC_KERNEL/" "$DEST_KERNEL/"



