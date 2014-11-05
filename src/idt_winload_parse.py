from pykd import *
import sys
 
idtr = reg( "idtr" )
print "idtr = 0x%x" % idtr
i = 256
for i in range(0,256):
    buf = loadBytes(idtr+16*i, 16)
    if buf[2]!=0: #idtEntry.Selector
        #print "IDT selector %x" % buf[2]
        isr = 0
        isr = isr + (buf[11] << (8*7))
        isr = isr + (buf[10] << (8*6))
        isr = isr + (buf[9] << (8*5))
        isr = isr + (buf[8] << (8*4))
        isr = isr + (buf[7] << (8*3))
        isr = isr + (buf[6] << (8*2))
        isr = isr + (buf[1] << (8*1))
        isr = isr + (buf[0] << (8*0))
        print "isr %x address = " % i,findSymbol(isr)