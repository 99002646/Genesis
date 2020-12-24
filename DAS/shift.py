def convert_into_eight_bits(value):
    MSB = (value >> 8) & 0xff
    LSB = value & 0xff
    print(bin(MSB))
    print(bin(LSB))
convert_into_eight_bits(25545)