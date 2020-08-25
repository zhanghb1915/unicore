mknod /dev/mmcblk0p1 b 179 1
mount /dev/mmcblk0p1 /mnt
ifconfig eth0 up
ifconfig eth0 192.168.0.10
echo /sbin/mdev > /proc/sys/kernel/hotplug
