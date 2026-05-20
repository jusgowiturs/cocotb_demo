#!/bin/sh

CONFIG_FILE=".config"

if [ ! -f "$CONFIG_FILE" ]; then
    echo "Error: $CONFIG_FILE not found!"
    exit 1
fi

OPTIONS="
CONFIG_MMC
CONFIG_MMC_BLOCK
CONFIG_MMC_SDHCI
CONFIG_EXT4_FS
CONFIG_FAT_FS
CONFIG_BLK_DEV
"

# Set all MMC / FS / block options to y
for opt in $OPTIONS; do
    if grep -q "^$opt=y" "$CONFIG_FILE"; then
        echo "$opt : OK"
    else
        echo "$opt : setting to y"

        # Remove existing entry if present
        sed -i "/^$opt=/d" "$CONFIG_FILE" 2>/dev/null
        sed -i "/^# $opt is not set/d" "$CONFIG_FILE" 2>/dev/null

        # Add correct setting
        echo "$opt=y" >> "$CONFIG_FILE"
    fi
done

# Explicitly clear initramfs source
sed -i '/^CONFIG_INITRAMFS_SOURCE=/d' .config
echo 'CONFIG_INITRAMFS_SOURCE=""' >> .config

echo "-----Finished-----"
