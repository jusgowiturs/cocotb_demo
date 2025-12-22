@echo off
echo This script will format and allocate all space on the disk.
echo WARNING: This will erase all data on the disk selected.
echo.

:: Create a temporary list of diskpart commands to list all disks
echo list disk > list_disks.txt

:: Run DiskPart to list disks and output to the console
echo Listing all disks...
diskpart /s list_disks.txt

:: Wait for user input before continuing to give time to view disk list
pause

:: Prompt user to select the disk (change Disk number here, e.g., Disk 1)
echo.
set /p disknum="Enter the disk number to format (e.g., 1): "

:: Create a temporary list of diskpart commands to format the selected disk
echo select disk %disknum% > diskpart_commands.txt
echo clean >> diskpart_commands.txt
echo create partition primary >> diskpart_commands.txt
echo select partition 1 >> diskpart_commands.txt
echo format fs=ntfs quick >> diskpart_commands.txt
echo assign letter=E >> diskpart_commands.txt
echo exit >> diskpart_commands.txt

:: Run DiskPart with the format and allocation commands
diskpart /s diskpart_commands.txt

:: Clean up the temporary files
del list_disks.txt
del diskpart_commands.txt

echo Disk formatting complete. The disk has been formatted and allocated.
pause
