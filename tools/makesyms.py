import sys, os, subprocess


p = subprocess.Popen(["readelf", "-S", "NK4E.us.elf"], stdout=subprocess.PIPE)
elfSections = p.communicate()[0].decode('ascii').replace("[ ", "[_").split("\n")

sections = {}

for section in elfSections:
    if "WA" in section:
        tokens = section.split()
        num = int(tokens[0].replace("[", " ").replace("]", " ").replace("_", " "))
        name = tokens[1]
        vram = int(tokens[3], 16)
        rom = int(tokens[4], 16)
        size = int(tokens[5], 16)
        sections[num] = [name, vram, rom, size, []]
        # print(num, sections[num])

p = subprocess.Popen(["readelf", "-s", "--wide", "NK4E.us.elf"], stdout=subprocess.PIPE)
symbols = p.communicate()[0].decode('ascii').split("\n")

for sym in symbols:
    if "NOTYPE" in sym:
        if "ABS" not in sym and "UND" not in sym:
            tokens = sym.split()
            if len(tokens) != 8: continue
            name = tokens[-1]
            num = int(tokens[-2])
            if num not in sections: continue
            size = int(tokens[2])
            vram = int(tokens[1], 16)
            sections[num][-1].append([name, size, vram])

sTemplate = '''[[section]]
name = "%s"
rom = 0x%08X
vram = 0x%08X
size = 0x%X

symbols = ['''

bssTemplate = '''[[section]]
name = "%s"
vram = 0x%08X
size = 0x%X

symbols = ['''

for sec in sections:
    s = sections[sec]
    print(sTemplate % (s[0], s[2], s[1], s[3]))

    for sym in s[-1]:
        print('    { name = "%s", vram = 0x%08X, size = 0x%X },' % (sym[0], sym[2], sym[1]))

    print("]")
    print()

