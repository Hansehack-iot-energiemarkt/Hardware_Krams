# Hardware_Krams
GitLoch für alles was mit C und/oder realer Hardware zu tun hat.

# GPIO
| PIN   | Use      | Pullup needed | Value
|:------|:--------:|:---:|:---------------:
|20 SDA | I2C-DATA | yes | 2.2kOhm - 10kOhm
|21 SCL | I2C-COCK | yes | 2.2kOhm - 10kOhm
|A0     | Analog   |  /  | /

# Register

| Reg-Name      | Address Start | Address End | Unusable Bits
|:-------------:|:-------------:|:-----------:|:------------:
| DATA          | 0x000C        | 0x000F      | /
| LENGTH        | 0x0008        | 0x000B      | 0x0008 LSBit 0 and 1
| ADDR          | 0x0004        | 0x0007      | 0x0004 LSBit 0 and 1
| DCC0 (Debug)  | 0x0010        | 0x0013      | /

# Read/write

## Read
1. Check INTFLAG.RXC
2. If set
3. Read DATA-Reg

## Write
1. Check INTFLAG.DRE
2. If set
3. Write into DATA-Reg
