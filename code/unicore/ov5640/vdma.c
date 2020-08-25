void main()
{
    int vdma_S2MM_address=0x60070000;
    int *S2MM_VDMACR=(int*)(long)(vdma_S2MM_address+0x30);
    *S2MM_VDMACR=0X04;
    *S2MM_VDMACR=0X108B;
    int *S2MM_Start_Addresses=(int*)(long)(vdma_S2MM_address+0xAC);
    *S2MM_Start_Addresses=0x03000000;
    int *S2MM_FRAMDELAY_STRIDE=(int*)(long)(vdma_S2MM_address+0xA8);
    *S2MM_FRAMDELAY_STRIDE=0x1680;
    int *S2MM_HSIZE=(int*)(long)(vdma_S2MM_address+0xA4);
    *S2MM_HSIZE=0x780;
    int *S2MM_VSIZE=(int*)(long)(vdma_S2MM_address+0xA0);
    *S2MM_VSIZE=0x1E0;

    int vdma_MM2S_address=0x60070000;
    int *MM2S_VDMACR=(int*)(long)(vdma_MM2S_address+0x00);
    *MM2S_VDMACR=0x04;
    *MM2S_VDMACR=0x8B;
    int *MM2S_Start_Addresses=(int*)(long)(vdma_MM2S_address+0x5C);
    *MM2S_Start_Addresses=0x03000000;
    int *MM2S_FRAMDELAY_STRIDE=(int*)(long)(vdma_MM2S_address+0x58);
    *MM2S_FRAMDELAY_STRIDE=0x1680;
    int *MM2S_HSIZE=(int*)(long)(vdma_MM2S_address+0x54);
    *MM2S_HSIZE=0x780;
    int *MM2S_VSIZE=(int*)(long)(vdma_MM2S_address+0x50);
    *MM2S_VSIZE=0x1E0;

    int VTC_address=0x60050000;
    int *VTC_START=(int*)(long)(VTC_address+0x00);
    *VTC_START=0x01;
    while(1);
}
