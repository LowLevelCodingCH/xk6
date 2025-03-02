echo qemu

qemu-img convert -O qcow2 Binaries/Nx/xos.iso Binaries/Nx/xos.qcow2

qemu-system-i386 -m 256M -soundhw pcspk -serial stdio -drive file=Binaries/Nx/xos.qcow2,format=qcow2
