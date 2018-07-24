## Getting Started With The mbed-os Example for the HYPERBUS Flash Block Device

This is the mbed-os example for the HYPERBUSFBlockDevice driver.
See the [hyperbusf-driver](https://github.com/GreenWaves-Technologies/hyperbusf-driver) repository for more information.

This guide outlines the steps to get a HYPERBUS NOR flash part working on an mbed OS platform.

Please install [mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

## Hardware Requirements

This example can be used on an mbedos platform with a HYPERBUS NOR part connected to the HYPERBUS pins (on the Arduino header, for example).

This document uses the GAP8 as an example. Simply change the relevant options (e.g. -m GAP8) to be appropriate for your target.

## Create the Example Application

From the command-line, import the example:

```
mbed import https://github.com/GreenWaves-Technologies/mbed-os-example-hyperbusflash-driver
```

You should see:

```
        [mbed] Adding library "hyperbusf-driver" from "https://github.com/GreenWaves-Technologies/hyperbusf-driver" at rev #bfaecfe83ead
        [mbed] Adding library "mbed-os" from "https://github.com/GreenWaves-Technologies/mbed-os" at rev #b0f31ea774ac
```
Move into the newly created directory:

```
cd mbed-os-example-hyperbusflash-driver
```

If the mbed-os library was not automatically added (see trace above), do the following to import mbed-os:

```
mbed new .
```


## Build the Example

Invoke `mbed compile`, and specify the name of your platform and your favorite toolchain (`GCC_RISCV`, `GCC_ARM`, `ARM`, `IAR`). For example, for the GCC_RISCV toolchain:

```
mbed compile -m GAP8 -t GCC_RISCV
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

```
Elf2Bin: mbed-os-example-hyperbusflash-driver
+-----------------+-------+-------+------+
| Module          | .text | .data | .bss |
+-----------------+-------+-------+------+
| BUILD/GAP8      | 22524 |   380 | 1186 |
| [fill]          |     2 |     4 |   18 |
| [lib]/c.a       |  9542 |  2096 |   60 |
| [lib]/gcc.a     |  1798 |     0 |    0 |
| mbed-os/targets |   288 |     4 |   28 |
| Subtotals       | 34154 |  2484 | 1292 |
+-----------------+-------+-------+------+
Total Static RAM memory (data + bss): 3776 bytes
Total Flash memory (text + data): 36638 bytes
```


## <a name="run-the-example-binary-on-the-GAP8"></a> Run the Example Binary on the GAP8

1. Connect your device (with sensor board) to the computer over USB.
1. Execute the script (make sure you have already install the [gap_sdk](https://github.com/GreenWaves-Technologies/gap_sdk)) :

```
source ./USER_PATH/gap_sdk/sourceme.sh
run_mbed ./BUILD/GAP8/GCC_RISCV/mbed-os-example-hyperbusflash-driver.elf
```

After connecting a serial console and resetting the target, the following trace should be seen:

```
        hyperbusf test
        hyperbusf size: 67108864
        hyperbusf read size: 2
        hyperbusf program size: 2
        hyperbusf erase size: 262144
        Hello World!
```

# Troubleshooting

1. Make sure `mbed-cli` is working correctly and its version is newer than `1.0.0`.

 ```
 mbed --version
 ```

 If not, update it:

 ```
 pip install mbed-cli --upgrade
 ```
