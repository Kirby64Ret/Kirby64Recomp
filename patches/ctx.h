typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef long s32;
typedef long long s64;
typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned long vu32;
typedef volatile unsigned long long vu64;
typedef volatile signed char vs8;
typedef volatile short vs16;
typedef volatile long vs32;
typedef volatile long long vs64;
typedef float f32;
typedef double f64;
typedef s32 OSPri;
typedef s32 OSId;

#define ABSVAL(x) ((x) < 0 ? -(x) : (x))

typedef float Vec3f[3];


typedef struct _Vector {
    f32 x; f32 y; f32 z;
} Vector;

typedef struct {
        short vscale[4];    /* Scale, 14.2 */
        short vtrans[4];    /* Transformation, 14.2 */
} Vp_t;
typedef union {
        Vp_t vp;
        long long int force_structure_alignment;
} Vp;

typedef union { struct { f32 f_odd; f32 f_even; } f; f64 d; } __OSfp;
typedef struct {
 u64 at, v0, v1, a0, a1, a2, a3;
 u64 t0, t1, t2, t3, t4, t5, t6, t7;
 u64 s0, s1, s2, s3, s4, s5, s6, s7;
 u64 t8, t9, gp, sp, s8, ra;
 u64 lo, hi;
 u32 sr, pc, cause, badvaddr, rcp;
 u32 fpcsr;
 __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
 __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;
typedef struct OSThread_s {
 struct OSThread_s *next;
 OSPri priority;
 struct OSThread_s **queue;
 struct OSThread_s *tlnext;
 u16 state;
 u16 flags;
 OSId id;
 int fp;
 __OSThreadContext context;
} OSThread;
typedef u32 OSEvent;
typedef u32 OSIntMask;
typedef u32 OSPageMask;
typedef u32 OSHWIntr;
typedef void * OSMesg;
typedef struct OSMesgQueue_s {
 OSThread *mtqueue;
 OSThread *fullqueue;
 s32 validCount;
 s32 first;
 s32 msgCount;
 OSMesg *msg;
} OSMesgQueue;
typedef struct {
 u32 errStatus;
        void *dramAddr;
 void *C2Addr;
 u32 sectorSize;
 u32 C1ErrNum;
 u32 C1ErrSector[4];
} __OSBlockInfo;
typedef struct {
             u32 cmdType;
             u16 transferMode;
             u16 blockNum;
             s32 sectorNum;
             u32 devAddr;
              u32 bmCtlShadow;
              u32 seqCtlShadow;
 __OSBlockInfo block[2];
} __OSTranxInfo;
typedef struct OSPiHandle_s {
        struct OSPiHandle_s *next;
                 u8 type;
                 u8 latency;
                 u8 pageSize;
                 u8 relDuration;
                 u8 pulse;
              u8 domain;
                  u32 baseAddress;
                  u32 speed;
        __OSTranxInfo transferInfo;
} OSPiHandle;
typedef struct {
        u8 type;
        u32 address;
} OSPiInfo;
typedef struct {
        u16 type;
        u8 pri;
        u8 status;
 OSMesgQueue *retQueue;
} OSIoMesgHdr;
typedef struct {
 OSIoMesgHdr hdr;
 void * dramAddr;
 u32 devAddr;
 u32 size;
 OSPiHandle *piHandle;
} OSIoMesg;
typedef struct {
        s32 active;
 OSThread *thread;
        OSMesgQueue *cmdQueue;
        OSMesgQueue *evtQueue;
        OSMesgQueue *acsQueue;
        s32 (*dma)(s32, u32, void *, u32);
        s32 (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;
typedef struct {
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;
typedef struct {
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;
typedef struct {
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;
typedef u64 OSTime;
typedef struct OSTimer_s {
 struct OSTimer_s *next;
 struct OSTimer_s *prev;
 OSTime interval;
 OSTime value;
 OSMesgQueue *mq;
 OSMesg msg;
} OSTimer;
typedef struct {
 u16 type;
 u8 status;
 u8 errno;
}OSContStatus;
typedef struct {
 u16 button;
 s8 stick_x;
 s8 stick_y;
 u8 errno;
} OSContPad;
typedef struct {
 void *address;
 u8 databuffer[32];
        u8 addressCrc;
 u8 dataCrc;
 u8 errno;
} OSContRamIo;
typedef struct {
 int status;
 OSMesgQueue *queue;
 int channel;
 u8 id[32];
 u8 label[32];
 int version;
 int dir_size;
 int inode_table;
 int minode_table;
 int dir_table;
 int inode_start_page;
 u8 banks;
 u8 activebank;
} OSPfs;
typedef struct {
 u32 file_size;
   u32 game_code;
   u16 company_code;
   char ext_name[4];
   char game_name[16];
} OSPfsState;
typedef struct {
 u16 *histo_base;
 u32 histo_size;
 u32 *text_start;
 u32 *text_end;
} OSProf;
extern u64 osClockRate;
extern OSViMode osViModeTable[];
extern OSViMode osViModeNtscLpn1;
extern OSViMode osViModeNtscLpf1;
extern OSViMode osViModeNtscLan1;
extern OSViMode osViModeNtscLaf1;
extern OSViMode osViModeNtscLpn2;
extern OSViMode osViModeNtscLpf2;
extern OSViMode osViModeNtscLan2;
extern OSViMode osViModeNtscLaf2;
extern OSViMode osViModeNtscHpn1;
extern OSViMode osViModeNtscHpf1;
extern OSViMode osViModeNtscHan1;
extern OSViMode osViModeNtscHaf1;
extern OSViMode osViModeNtscHpn2;
extern OSViMode osViModeNtscHpf2;
extern OSViMode osViModePalLpn1;
extern OSViMode osViModePalLpf1;
extern OSViMode osViModePalLan1;
extern OSViMode osViModePalLaf1;
extern OSViMode osViModePalLpn2;
extern OSViMode osViModePalLpf2;
extern OSViMode osViModePalLan2;
extern OSViMode osViModePalLaf2;
extern OSViMode osViModePalHpn1;
extern OSViMode osViModePalHpf1;
extern OSViMode osViModePalHan1;
extern OSViMode osViModePalHaf1;
extern OSViMode osViModePalHpn2;
extern OSViMode osViModePalHpf2;
extern OSViMode osViModeMpalLpn1;
extern OSViMode osViModeMpalLpf1;
extern OSViMode osViModeMpalLan1;
extern OSViMode osViModeMpalLaf1;
extern OSViMode osViModeMpalLpn2;
extern OSViMode osViModeMpalLpf2;
extern OSViMode osViModeMpalLan2;
extern OSViMode osViModeMpalLaf2;
extern OSViMode osViModeMpalHpn1;
extern OSViMode osViModeMpalHpf1;
extern OSViMode osViModeMpalHan1;
extern OSViMode osViModeMpalHaf1;
extern OSViMode osViModeMpalHpn2;
extern OSViMode osViModeMpalHpf2;
extern s32 osRomType;
extern void *osRomBase;
extern s32 osTvType;
extern s32 osResetType;
extern s32 osCicId;
extern s32 osVersion;
extern u32 osMemSize;
extern s32 osAppNMIBuffer[];
extern OSIntMask __OSGlobalIntMask;
extern OSPiHandle *__osPiTable;
extern OSPiHandle *__osDiskHandle;
extern void osCreateThread(OSThread *, OSId, void (*)(void *),
           void *, void *, OSPri);
extern void osDestroyThread(OSThread *);
extern void osYieldThread(void);
extern void osStartThread(OSThread *);
extern void osStopThread(OSThread *);
extern OSId osGetThreadId(OSThread *);
extern void osSetThreadPri(OSThread *, OSPri);
extern OSPri osGetThreadPri(OSThread *);
extern void osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern s32 osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32 osJamMesg(OSMesgQueue *, OSMesg, s32);
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern void osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);
extern OSIntMask osGetIntMask(void);
extern OSIntMask osSetIntMask(OSIntMask);
extern void osInitRdb(u8 *sendBuf, u32 sendSize);
extern void osInvalDCache(void *, s32);
extern void osInvalICache(void *, s32);
extern void osWritebackDCache(void *, s32);
extern void osWritebackDCacheAll(void);
extern void osMapTLB(s32, OSPageMask, void *, u32, u32, s32);
extern void osMapTLBRdb(void);
extern void osUnmapTLB(s32);
extern void osUnmapTLBAll(void);
extern void osSetTLBASID(s32);
extern u32 osVirtualToPhysical(void *);
extern void * osPhysicalToVirtual(u32);
extern u32 osAiGetStatus(void);
extern u32 osAiGetLength(void);
extern s32 osAiSetFrequency(u32);
extern s32 osAiSetNextBuffer(void *, u32);
extern u32 osDpGetStatus(void);
extern void osDpSetStatus(u32);
extern void osDpGetCounters(u32 *);
extern s32 osDpSetNextBuffer(void *, u64);
extern u32 osPiGetStatus(void);
extern s32 osPiGetDeviceType(void);
extern s32 osPiRawWriteIo(u32, u32);
extern s32 osPiRawReadIo(u32, u32 *);
extern s32 osPiRawStartDma(s32, u32, void *, u32);
extern s32 osPiWriteIo(u32, u32);
extern s32 osPiReadIo(u32, u32 *);
extern s32 osPiStartDma(OSIoMesg *, s32, s32, u32, void *, u32,
         OSMesgQueue *);
extern void osCreatePiManager(OSPri, OSMesgQueue *, OSMesg *, s32);
extern u32 osViGetStatus(void);
extern u32 osViGetCurrentMode(void);
extern u32 osViGetCurrentLine(void);
extern u32 osViGetCurrentField(void);
extern void *osViGetCurrentFramebuffer(void);
extern void *osViGetNextFramebuffer(void);
extern void osViSetXScale(f32);
extern void osViSetYScale(f32);
extern void osViSetSpecialFeatures(u32);
extern void osViSetMode(OSViMode *);
extern void osViSetEvent(OSMesgQueue *, OSMesg, u32);
extern void osViSwapBuffer(void *);
extern void osViBlack(u8);
extern void osViFade(u8, u16);
extern void osViRepeatLine(u8);
extern void osCreateViManager(OSPri);
extern OSTime osGetTime(void);
extern void osSetTime(OSTime);
extern int osSetTimer(OSTimer *, OSTime, OSTime,
       OSMesgQueue *, OSMesg);
extern int osStopTimer(OSTimer *);
extern s32 osContInit(OSMesgQueue *, u8 *, OSContStatus *);
extern s32 osContReset(OSMesgQueue *, OSContStatus *);
extern s32 osContStartQuery(OSMesgQueue *);
extern s32 osContStartReadData(OSMesgQueue *);
extern s32 osContSetCh(u8);
extern void osContGetQuery(OSContStatus *);
extern void osContGetReadData(OSContPad *);
extern s32 osPfsInitPak(OSMesgQueue *, OSPfs *, int);
extern s32 osPfsRepairId(OSPfs *);
extern s32 osPfsInit(OSMesgQueue *, OSPfs *, int);
extern s32 osPfsReFormat(OSPfs *, OSMesgQueue *, int);
extern s32 osPfsChecker(OSPfs *);
extern s32 osPfsAllocateFile(OSPfs *, u16, u32, u8 *, u8 *, int, s32 *);
extern s32 osPfsFindFile(OSPfs *, u16, u32, u8 *, u8 *, s32 *);
extern s32 osPfsDeleteFile(OSPfs *, u16, u32, u8 *, u8 *);
extern s32 osPfsReadWriteFile(OSPfs *, s32, u8, int, int, u8 *);
extern s32 osPfsFileState(OSPfs *, s32, OSPfsState *);
extern s32 osPfsGetLabel(OSPfs *, u8 *, int *);
extern s32 osPfsSetLabel(OSPfs *, u8 *);
extern s32 osPfsIsPlug(OSMesgQueue *, u8 *);
extern s32 osPfsFreeBlocks(OSPfs *, s32 *);
extern s32 osPfsNumFiles(OSPfs *, s32 *, s32 *);
extern s32 osEepromProbe(OSMesgQueue *);
extern s32 osEepromRead(OSMesgQueue *, u8, u8 *);
extern s32 osEepromWrite(OSMesgQueue *, u8, u8 *);
extern s32 osEepromLongRead(OSMesgQueue *, u8, u8 *, int);
extern s32 osEepromLongWrite(OSMesgQueue *, u8, u8 *, int);
extern s32 osMotorInit(OSMesgQueue *, OSPfs *, int);
extern s32 osMotorStop(OSPfs *);
extern s32 osMotorStart(OSPfs *);
extern OSPiHandle *osCartRomInit(void);
extern OSPiHandle *osLeoDiskInit(void);
extern OSPiHandle *osDriveRomInit(void);
extern s32 osEPiDeviceType(OSPiHandle *, OSPiInfo *);
extern s32 osEPiRawWriteIo(OSPiHandle *, u32 , u32);
extern s32 osEPiRawReadIo(OSPiHandle *, u32 , u32 *);
extern s32 osEPiRawStartDma(OSPiHandle *, s32 , u32 , void *, u32 );
extern s32 osEPiWriteIo(OSPiHandle *, u32 , u32 );
extern s32 osEPiReadIo(OSPiHandle *, u32 , u32 *);
extern s32 osEPiStartDma(OSPiHandle *, OSIoMesg *, s32);
extern s32 osEPiLinkHandle(OSPiHandle *);
extern void osProfileInit(OSProf *, u32 profcnt);
extern void osProfileStart(u32);
extern void osProfileFlush(void);
extern void osProfileStop(void);
extern s32 osTestHost(void);
extern void osReadHost(void *, u32);
extern void osWriteHost(void *, u32);
extern void osAckRamromRead(void);
extern void osAckRamromWrite(void);
extern void bcopy(const void *, void *, int);
extern int bcmp(const void *, const void *, int);
extern void bzero(void *, int);
extern void osInitialize(void);
extern u32 osGetCount(void);
extern void osExit(void);
extern u32 osGetMemSize(void);
extern int sprintf(char *s, const char *fmt, ...);
extern void osSyncPrintf(const char *fmt, ...);
extern void osAsyncPrintf(const char *fmt, ...);
extern int osSyncGetChars(char *buf);
extern int osAsyncGetChars(char *buf);
extern u32 __osGetCause(void);
extern void __osSetCause(u32);
extern u32 __osGetCompare(void);
extern void __osSetCompare(u32);
extern u32 __osGetConfig(void);
extern void __osSetConfig(u32);
extern void __osSetCount(u32);
extern u32 __osGetSR(void);
extern void __osSetSR(u32);
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);
extern u32 __osSetFpcCsr(u32);
extern u32 __osGetFpcCsr(void);
extern void __osSetHWIntrRoutine(OSHWIntr, s32 (*handler)(void));
extern void __osSetGlobalIntMask(OSHWIntr);
extern void __osResetGlobalIntMask(OSHWIntr);
extern s32 __osLeoInterrupt(void);
extern u32 __osGetTLBASID(void);
extern u32 __osGetTLBPageMask(s32);
extern u32 __osGetTLBHi(s32);
extern u32 __osGetTLBLo0(s32);
extern u32 __osGetTLBLo1(s32);
extern u32 __osSiGetStatus(void);
extern s32 __osSiRawWriteIo(u32, u32);
extern s32 __osSiRawReadIo(u32, u32 *);
extern s32 __osSiRawStartDma(s32, void *);
extern u32 __osSpGetStatus(void);
extern void __osSpSetStatus(u32);
extern s32 __osSpSetPc(u32);
extern s32 __osSpRawWriteIo(u32, u32);
extern s32 __osSpRawReadIo(u32, u32 *);
extern s32 __osSpRawStartDma(s32, u32, void *, u32);
extern void __osError(s16, s16, ...);
extern OSThread * __osGetCurrFaultedThread(void);
extern OSThread * __osGetNextFaultedThread(OSThread *);
extern void __osGIOInit(s32);
extern void __osGIOInterrupt(s32);
extern void __osGIORawInterrupt(s32);
extern OSThread * __osGetActiveQueue(void);
extern void __osSyncPutChars(int, int, const char *);
extern int __osSyncGetChars(char *);
extern void __osAsyncPutChars(int, int, const char *);
extern int __osAsyncGetChars(char *);
extern int __osAtomicInc(unsigned int *p);
extern int __osAtomicDec(unsigned int *p);
extern u32 __osRdbSend(u8 *buf, u32 size, u32 type);
typedef struct
{
              u32 ramarray[15];
               u32 pifstatus;
} OSPifRam;
typedef struct
{
              u8 dummy;
              u8 txsize;
              u8 rxsize;
              u8 cmd;
              u16 button;
              s8 stick_x;
              s8 stick_y;
} __OSContReadFormat;
typedef struct
{
              u8 dummy;
              u8 txsize;
              u8 rxsize;
              u8 cmd;
              u8 typeh;
              u8 typel;
              u8 status;
              u8 dummy1;
} __OSContRequesFormat;
typedef struct
{
              u8 txsize;
              u8 rxsize;
              u8 cmd;
              u8 typeh;
              u8 typel;
              u8 status;
} __OSContRequesFormatShort;
typedef struct
{
              u8 dummy;
              u8 txsize;
              u8 rxsize;
              u8 cmd;
              u16 address;
              u8 data[32];
               u8 datacrc;
} __OSContRamReadFormat;
typedef union {
              struct
    {
                  u8 bank;
                  u8 page;
    } inode_t;
              u16 ipage;
} __OSInodeUnit;
typedef struct
{
              u32 game_code;
              u16 company_code;
              __OSInodeUnit start_page;
              u8 status;
              s8 reserved;
              u16 data_sum;
              u8 ext_name[4];
               u8 game_name[16];
} __OSDir;
typedef struct
{
              __OSInodeUnit inode_page[128];
} __OSInode;
typedef struct
{
              u32 repaired;
              u32 random;
              u64 serial_mid;
               u64 serial_low;
               u16 deviceid;
               u8 banks;
               u8 version;
               u16 checksum;
               u16 inverted_checksum;
} __OSPackId;
typedef struct
{
              u8 txsize;
              u8 rxsize;
              u8 cmd;
              u8 address;
              u8 data[8];
} __OSContEepromFormat;
typedef struct
{
              __OSInode inode;
                u8 bank;
                u8 map[256];
} __OSInodeCache;
extern s32 __osEepStatus(OSMesgQueue *, OSContStatus *);
u16 __osSumcalc(u8 *ptr, int length);
s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum);
s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid);
s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp);
s32 __osGetId(OSPfs *pfs);
s32 __osCheckId(OSPfs *pfs);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
s32 __osPfsSelectBank(OSPfs *pfs, u8 bank);
s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, int file_size_in_pages, int *first_page, u8 bank, int *decleared, int *last_page);
s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 start_page, u16 *sum, u8 bank, __OSInodeUnit *last_page, int flag);
s32 __osBlockSum(OSPfs *pfs, u8 page_no, u16 *sum, u8 bank);
s32 __osContRamRead(OSMesgQueue *mq, int channel, u16 address, u8 *buffer);
s32 __osContRamWrite(OSMesgQueue *mq, int channel, u16 address, u8 *buffer, int force);
void __osContGetInitData(u8 *pattern, OSContStatus *data);
void __osPackRequestData(u8 cmd);
void __osPfsRequestData(u8 cmd);
void __osPfsGetInitData(u8* pattern, OSContStatus* data);
u8 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8 *data);
s32 __osPfsGetStatus(OSMesgQueue *queue, int channel);
extern u8 __osContLastCmd;
extern OSTimer __osEepromTimer;
extern OSMesg __osEepromTimerMsg;
extern OSMesgQueue __osEepromTimerQ;
extern OSPifRam __osEepPifRam;
extern OSPifRam __osContPifRam;
extern OSPifRam __osPfsPifRam;
extern u8 __osMaxControllers;
#define SPSTATUS_HALT 0x0001
#define SPSTATUS_BROKE 0x0002
#define SPSTATUS_DMA_BUSY 0x0004
#define SPSTATUS_DMA_FULL 0x0008
#define SPSTATUS_IO_FULL 0x0010
#define SPSTATUS_SINGLE_STEP 0x0020
#define SPSTATUS_INTERRUPT_ON_BREAK 0x0040
#define SPSTATUS_SIGNAL0_SET 0x0080
#define SPSTATUS_SIGNAL1_SET 0x0100
#define SPSTATUS_SIGNAL2_SET 0x0200
#define SPSTATUS_SIGNAL3_SET 0x0400
#define SPSTATUS_SIGNAL4_SET 0x0800
#define SPSTATUS_SIGNAL5_SET 0x1000
#define SPSTATUS_SIGNAL6_SET 0x2000
#define SPSTATUS_SIGNAL7_SET 0x4000

/* Types */
/* Types */

typedef struct
{
    /*0x00*/ u32 type;
    /*0x04*/ u32 flags;

    /*0x08*/ u64 *ucode_boot;
    /*0x0C*/ u32 ucode_boot_size;

    /*0x10*/ u64 *ucode;
    /*0x14*/ u32 ucode_size;

    /*0x18*/ u64 *ucode_data;
    /*0x1C*/ u32 ucode_data_size;

    /*0x20*/ u64 *dram_stack;
    /*0x24*/ u32 dram_stack_size;

    /*0x28*/ u64 *output_buff;
    /*0x2C*/ u64 *output_buff_size;

    /*0x30*/ u64 *data_ptr;
    /*0x34*/ u32 data_size;

    /*0x38*/ u64 *yield_data_ptr;
    /*0x3C*/ u32 yield_data_size;
} OSTask_t; // size = 0x40

typedef union {
    OSTask_t t;
    long long int force_structure_alignment;
} OSTask;

typedef u32 OSYieldResult;

/* Functions */

#define osSpTaskStart(tp)   \
    {               \
        osSpTaskLoad((tp)); \
        osSpTaskStartGo((tp));  \
    }

struct Controller {
    u16 buttonHeld;
    u16 buttonPressed;
    u16 bufferedButtonPressed;
    u16 buttonHeldLong;
    u16 bufferedButtonHeldLong;
    u16 buttonReleased;
    u16 bufferedButtonReleased;
    s8 stick_x;
    s8 stick_y;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 errno;
    u8 status;
};

extern struct Controller gControllers[4]; // 0x80048EA0


void osSpTaskLoad(OSTask *task);
void osSpTaskLoad(OSTask *task);
void osSpTaskYield(void);
OSYieldResult osSpTaskYielded(OSTask *task);
typedef struct {
    u32 words_w0;
    u32 words_w1;
} Gfx;
// same as D_800E1B50?
struct UnkStruct8004A7C4_3C_80 {
    struct UnkStruct8004A7C4_3C_80 *unk0;
    u32 unk4;
    struct UnkStruct8004A7C4_3C_80 *unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u32 unk54;
    u8 unk58;
    u8 unk59;
    u8 unk5A;
    u8 unk5B;
    u32 unk5C;
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    u32 unk78;
    u32 unk7C;
    u32 unk80;
    u32 unk84;
    f32 unk88;
    u32 unk8C;
    u32 unk90;
    u32 unk94;
    f32 unk98;
    u32 unk9C;
    f32 unkA0;
};

struct UnkStruct8004A7C4_3C_10 {
    u8 pad[0x30];
    // vec?
    Vector unk30;
};


// SOME chunk of the beginning of the struct is a union
struct UnkStruct8004A7C4_3C {
    // u32 unk0;
    // u32 unk4;
    // u32 unk8;
    Vector unk0;

    u32 unkC;

    struct UnkStruct8004A7C4_3C_10 *unk10;
    u32 unk14;
    u32 unk18;

    // pos
    Vector posVec;

    u32 unk28;
    u32 unk2C;

    // angle
    Vector angleVec;

    // TODO: how is this actually structured?
    // some code thinks unk3C is the vector while others
    // think unk40 is
    f32 unk3C;
    // scale
    Vector scaleVec;

    u32 unk4C;
    u32 unk50[4];
    u32 unk60[4];
    s32 unk70;
    s32 unk74;
    f32 unk78;
    s32 unk7C;
    struct UnkStruct8004A7C4_3C_80 *unk80;
    u32 unk84;
};

// only difference is that unk3C is a vector now
struct UnkStruct8004A7C4_3C_duplicate {
    // u32 unk0;
    // u32 unk4;
    // u32 unk8;
    Vector unk0;
    
    u32 unkC;

    u32 unk10;
    u32 unk14;
    u32 unk18;

    Vector unk1C;

    u32 unk28;
    u32 unk2C;

    Vector unk30;

    Vector unk3C;
    f32 unk40;

    u32 unk4C;
    u32 unk50[4];
    u32 unk60[4];
    u32 unk70[4];
    u32 unk80;
    u32 unk84;
};

// GObj?
typedef struct GObj {
    /* 0x00 */ u32 objId;
    /* 0x04 */ struct GObj* unk4;
    /* 0x08 */ struct GObj* unk8;
    /* 0x0C */ u8 link;
    // todo: find the array this indexes
    /* 0x0D */ u8 dl_link;
    // seems to be similar to other GObj's in proximity
    u8 unkE;
    u8 unkF;
    u32 unk10;
    // location of render callback according to HSD
    void (*unk14)(void);
    struct GObjProcess *proc;
    u32 unk1C;
    struct GObj* nextDL;
    struct GObj* prevDL;
    u32 renderPriority;
    // location of user data removal function according to HSD
    // based on usage this might actually be the render callback
    void (*unk2C)(struct GObj *);
    u32 unk30;
    u32 unk34;
    u32 unk38;
    // user_data???
    struct UnkStruct8004A7C4_3C *unk3C;
    // goes up by 2.0f per frame until it hits 40.0f, then resets to 0.0f
    f32 unk40;
    u32 unk44;
    // grab arguments
    void (*unk48)(void);
    u32 unk4C;
} GObj;
// size: 0x50
extern struct GObj *D_8004A7C4, *D_8004A7C8, *D_8004A7CC;
extern struct GObj *D_800DE44C;

typedef void (*VTABLE[])(struct GObj *);
void call_virtual_function(u32 arg0, u32 arg1, VTABLE callback);
void func_800BC11C(f32);

extern struct GObjProcess *gEntityGObjProcessArray[];

void func_801DC9E8_ovl12(void);

void assign_new_process_entry(struct GObjProcess *ts, void (*func)(struct GObj *));

extern s32 D_800DD710[];
extern s32 D_800DE190[];
extern s32 D_800DDFD0[];
extern s32 D_800DDE10[];
extern s32 gEntityVtableIndexArray[];
extern s32 D_800DD8D0[];
extern s32 D_800E0810[];
s32 random_soft_s32_range(s32 arg0);
void play_sound(s32 arg0);
void finish_current_thread(s32 arg);

extern f32 D_800E0B90[];
extern f32 D_800E09D0[];
extern s32 D_800E0F10[];
extern s32 D_800E0D50[];
extern f32 **D_800E0490[];
extern s32 *D_800E0650[];
extern s32 D_800E1ED0[];
extern void (*D_800DEDD0[])(struct GObj *);
extern void (*D_800DEF90[])(s32);
extern void (*D_800DF150[])(s32);
extern void (*D_800DF310[])(s32, s32, f32);
extern u32 D_800DF850[];
extern u32 D_800DF690[];
extern u32 *gSegment4StartArray[];

// i think this is an array of pairs (2-length arrays) of pointers but cba to figure out syntax
extern struct LayoutNode **D_800DFBD0[];
extern s32 D_800E0110[];
extern s32 D_800DFF50[];
extern s32 D_800E02D0[];

extern f32 D_800E2410[];
extern f32 D_800E2250[];
extern f32 D_800E2090[];

extern f32 gEntitiesPosZArray[];
extern f32 gEntitiesPosYArray[];
extern f32 gEntitiesPosXArray[];
extern f32 gEntitiesNextPosZArray[];
extern f32 gEntitiesNextPosYArray[];
extern f32 gEntitiesNextPosXArray[];
extern f32 D_800E3910[];
extern f32 D_800E3750[];
extern f32 D_800E3590[];
extern f32 D_800E33D0[];
extern f32 D_800E3210[];
extern f32 D_800E3050[];
extern f32 D_800E3E50[];
extern f32 D_800E3C90[];
extern f32 D_800E3AD0[];
extern f32 gEntitiesAngleZArray[];
extern f32 gEntitiesAngleYArray[];
extern f32 gEntitiesAngleXArray[];
extern f32 D_800E1450[];
extern f32 D_800E1290[];
extern f32 D_800E10D0[];
extern f32 gEntitiesScaleZArray[];
extern f32 gEntitiesScaleYArray[];
extern f32 gEntitiesScaleXArray[];
extern f32 D_800E5DD0[];
extern f32 D_800E5C10[];
extern f32 D_800E5A50[];
extern f32 D_800E4E10[];
extern f32 D_800E4C50[];
extern f32 D_800E4A90[];
extern f32 D_800E5350[];
extern f32 D_800E5190[];
extern f32 D_800E4FD0[];

extern u32 D_800DDA90[];

extern u8 D_800E7650[];

extern s32 D_800E8AE0[];
extern s32 D_800E8220[];
extern s32 D_800E83E0[];
extern s32 D_800E8760[];

extern u32 D_800E8E60[];
extern f32 D_800E9020[];
extern u8 D_800E76C0[];
extern u8 D_800E7730[];

extern u16 D_800E77A0[];

extern u8 D_800E7880[];
extern u8 D_800E78F0[];
extern f32 D_800E7B20[];
extern u32 D_800E7CE0[];
extern s32 D_800EA520[];
extern s32 D_800EA360[];
extern s32 D_800EA1A0[];
extern s32 D_800E9FE0[];
extern s32 D_800E9E20[];
extern s32 D_800E9C60[];
extern struct EntityThing800E9AA0 *D_800E9AA0[];
extern s32 D_800E98E0[];
extern f32 D_800EB320[];
extern f32 D_800EB160[];
extern f32 D_800EAFA0[];
extern f32 D_800EADE0[];
extern f32 D_800EAC20[];
extern f32 D_800EAA60[];
extern f32 D_800EA8A0[];
extern f32 D_800EA6E0[];
extern s32 D_800EB6A0[];
extern s32 D_800EB4E0[];
extern f32 D_800EBA20[];
extern f32 D_800EB860[];
extern s32 D_800EC120[];
extern s32 D_800EBF60[];
extern s32 D_800EBDA0[];
extern s32 D_800EBBE0[];
extern s32 D_800EC4A0[];
extern s32 D_800EC2E0[];
extern f32 D_800EC820[];
extern f32 D_800EC660[];
extern s32 D_800E6150[];
extern s32 D_800E5F90[];
extern f32 D_800E6D90[];
extern f32 D_800E6BD0[];
extern f32 D_800E17D0[];
extern f32 D_800E1610[];
extern f32 D_800E6A10[];
extern f32 D_800E6690[];
extern f32 D_800E64D0[];

extern f32 D_800E6850[];
extern s32 D_800E8CA0[];
extern s32 D_800E6310[];
extern f32 D_800E56D0[];
extern f32 D_800E5510[];
extern f32 D_800E5890[];
extern s32 D_800E9720[];
extern s32 D_800E9560[];
extern s32 D_800E93A0[];

extern f32 D_800D6B10;

// extern struct Normal D_800E6F50[];
extern f32 D_800D66FC, D_800D66F8;

extern u32 D_800E8060[];
extern s32 D_800E8920[];
extern s32 D_800E7EA0[];

#define STACK_TOP_MAGIC 0x00000000FEDCBA98

// todo: keep naming scheme but rename regardless
// uses GObjThreadStack
#define HS64_GOBJPROC_KIND_GOBJTHREAD 0
// just uses a callback
#define HS64_GOBJPROC_KIND_CALLBACK 1
// classic stack
#define HS64_GOBJPROC_KIND_OSTHREAD 2

struct ObjStack {
    // what looks like an mini thread stack, based on the last value in here being set to STACK_TOP_MAGIC
    u64 stack[0x20];
};

// if a function that uses GObjThread doesnt match, try this definition
// struct GObjThread {
//     struct GObjThread *unk0;
//     u32 unk4;
//     OSThread *unk8;
//     u8 filler[0x1B8 - 0x04 - 0x08];
//     // This might be a u8 pointer
//     struct ObjStack *objStack;
//     s32 unk1BC;
// };

struct UnkStruct800009E8 {
    u32 unk0;
    OSMesgQueue *unk4;
};

struct DynamicBuffer {
    u32 id;
    void *poolStart;
    void *poolEnd;
    u32 top;
};

extern struct DynamicBuffer gDynamicBuffer1, gDynamicBuffer2;

struct GObjThread
{
    struct GObjThread *unk0; // function?
    OSThread thread;
    struct ObjStack *objStack;
    s32 objStackSize;
};

struct GObjThreadStack {
    struct GObjThreadStack *unk0;
    struct GObjThreadStack *unk4;
    u64 stack[8];
};

typedef struct GObjProcess {
    struct GObjProcess *unk0;
    struct GObjProcess *unk4;
    struct GObjProcess *unk8;
    struct GObjProcess *unkC;
    /* 0x10 */ u32 pri;
    /* 0x14 */ u8 kind;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    /* 0x18 */ struct GObj *gobj;
    union {
        struct GObjThread *thread;
        void (*callback)(struct GObj *);
    } payload; // 0x1C
    /* 0x20 */ void (*entryPoint)(struct GObj *);
    u32 *ptr;
} GObjProcess;

struct OMMtx {
    struct OMMtx *next;
};

// TODO: is this an existing struct instead of a brand new one?
struct unk80008840 {
    u8 padding[0x90];
    struct AObj *unk90;
    u32 unk94;
    f32 unk98;
};

typedef f32 quartic[5];

typedef struct {
    /* 0x00 */ s8 type; /* 0=linear;1=bezier;2=hermite/6 */
    /* 0x01 */ char unk_01[0x1];
    /* 0x02 */ s16 length;
    /* 0x04 */ f32 invSegTime;
    /* 0x08 */ Vector *pts;
    /* 0x0C */ f32 duration;
    /* 0x10 */ f32 *times;
    /* 0x14 */ quartic *quartics;
} pathSpline;

typedef struct {
    /* 0x00 */ struct uvOP *next;
    /* 0x04 */ s8 value;
    /* 0x05 */ s8 op;
    /* 0x06 */ char unk_06[0x2];
    /* 0x08 */ f32 ref;
    /* 0x0C */ f32 t;
    /* 0x10 */ f32 p0;
    /* 0x14 */ f32 p1;
    /* 0x18 */ f32 v0;
    /* 0x1C */ f32 v1;
    /* 0x20 */ struct pathSpline *path;
} uvOP;

typedef struct {
    /* 0x00 */ u32 type;
    /* 0x04 */ u32 flags;
    /* 0x08 */ s32 inc;
} uvState;


struct TextureScroll {
    // start of a texture scroll struct?
    /* 0x08 */ u16 h_8;
    /* 0x0A */ s8 fmt1;
    /* 0x0B */ s8 siz1;
    /* 0x0C */ u32 *textures;
    /* 0x10 */ u16 stretch;
    /* 0x12 */ u16 sharedOffset;
    /* 0x14 */ u16 t0w;
    /* 0x16 */ u16 t0h;
    /* 0x18 */ s32 halve;
    /* 0x1C */ f32 xFrac0;
    /* 0x20 */ f32 yFrac0;
    /* 0x24 */ f32 xScale;
    /* 0x28 */ f32 yScale;
    /* 0x2C */ f32 field_0x2c;
    /* 0x30 */ f32 field_0x30;
    /* 0x34 */ u32 *palettes;
    /* 0x38 */ u16 flags;
    /* 0x3A */ s8 fmt2;
    /* 0x3B */ s8 siz2;
    /* 0x3C */ u16 w2;
    /* 0x3E */ u16 h2;
    /* 0x40 */ u16 t1w;
    /* 0x42 */ u16 t1h;
    /* 0x44 */ f32 xFrac1;
    /* 0x48 */ f32 yFrac1;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ u8 primColor[4];

    /* 0x5C */ u8 unk_5C;
    /* 0x5D */ s8 minLOD;
    /* 0x5E */ u8 unk_5E;
    /* 0x5F */ u8 unk_5F;

    /* 0x60 */ u8 envColor[4];
    /* 0x64 */ u8 blendColor[4];
    /* 0x68 */ u8 lightColor1[4];
    /* 0x6C */ u8 lightColor2[4];
    /* 0x70 */ u32 unk70;
    /* 0x74 */ u32 unk74;
    /* 0x78 */ u32 unk78;
    /* 0x7C */ u32 unk7C;
};
struct MObj {
    /* 0x00 */ struct MObj *next;
    /* 0x04 */ s32 unk_04;

    struct TextureScroll texScroll;
    
    /* 0x80 */ u16 texIndex1;
    /* 0x82 */ u16 texIndex2;
    /* 0x84 */ f32 primLOD;
    /* 0x88 */ f32 palIndex;
    /* 0x8C */ char unk_8C[0x4];
    /* 0x90 */ uvOP* ops;
    /* 0x94 */ uvState* states;
    /* 0x98 */ f32 offset;
    /* 0x9C */ f32 increment;
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ char unk_A4[0x4];
}; // size = 0xA8;


struct DObj {
    struct DObj *unk0;
    struct GObj *gobj;
    struct DObj *unk8;
    u32 unkC;
    struct DObj *unk10;
    u32 unk14;
    struct DObj *unk18;
    u8 filler[0x4C - 0x18 - 0x04];
    u32 unk4C;
    u32 unk50;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u32 unk58;
    u32 unk5C;
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    struct MObj *unk80;
    u32 unk84;
};

struct Camera {
    struct Camera *unk0;
    struct GObj *gobj;
    /* 0x08 */ Vp viewport;
    u32 unk18;
    u32 unk1C;

    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;

    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;

    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;

    u32 unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;

    u32 unk60;
    struct OMMtx *unk64[2];
    struct AObj *aobj;
    u32 unk70;

    // vec?
    f32 unk74;
    f32 unk78;
    f32 unk7C;

    u32 unk80;
    u32 unk84;
    u32 unk88;
    u32 unk8C;
};

struct Unk80005A98_2 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    OSMesgQueue *unk20;
    u32 unk24;
    OSTask task;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    u32 unk78;
    u32 unk7C;
    u32 unk80;
};

// Definitely a DObj
struct Unk80005A98 {
    u32 unk0;
    u32 unk4;
    struct Unk80005A98 *unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    OSMesgQueue *unk20;
    u32 unk24;
    u32 unk28;
    void (*unk2C)(struct Unk80005A98*);
    u32 unk30;
    u32 unk34;
    void* unk38;
    u32 unk3C;
    void* unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    Gfx *unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    u32 unk78;
    u32 unk7C;
    u32 unk80;
};

// One of the message types sent on the interrupt message queue
struct InterruptMessageType4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
};

// One of the message types sent on the ovl0_2 message queue
struct Ovl0_2_MessageType1
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

// One of the message types sent on the ovl0_2 message queue
struct Ovl0_2_MessageType2
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

// One of the message types sent on the ovl0_2 message queue
struct Ovl0_2_MessageType3
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

// One of the message types sent on the ovl0_2 message queue
struct Ovl0_2_MessageType4
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

// One of the message types sent on the ovl0_2 message queue
struct Ovl0_2_MessageType6
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

// Buffers allocated to hold the master displaylists
struct DLBuffer
{
    Gfx* start;
    u32 length; // In bytes
};

// One of the message types sent on the interrupt message queue
struct InterruptMessageType5 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

// One of the message types sent on the interrupt message queue
struct InterruptMessageTypeB {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern OSMesgQueue gInterruptMesgQueue;

struct Camera *func_80009F7C(struct GObj*);

void func_80009B5C(struct UnkStruct8004A7C4_3C *);

void func_801DF3F0_ovl12(void);

typedef struct UserData8000BE90 {
    s32 unk0;
    s32 unk4;
    struct UserData8000BE90 *unk8;
    s32 unkC;
    struct UserData8000BE90 *unk10;
    struct UserData8000BE90 *unk14;
} UserData8000BE90;

UserData8000BE90 *func_8000BE90(struct UserData8000BE90 *data);

void func_800F98EC(s32, f32);
void func_800A7F74(s32, s32, s32, f32, f32, f32);
void func_800A9760(u32);

struct UnkStructFunc80007380 {
    u32 unk0;
    u32 unk4;
    u32 unk8;

    // some sort of range that is allocated for gDynamicBuffer2
    void *unkC;
    void *unk10;

    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;


    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    u32 unk78;
    u32 unk7C;
    u32 unk80;
    u32 unk84;
    u32 unk88;
};


extern struct GObj *D_8004A7C4;

struct UnkStruct800D7098 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
};

struct UnkStruct800DE350 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10[4];
    u32 unk20[4];
    u32 unk30[3];
    u32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
};

extern struct GObj *D_800DE350[];

struct UnkStruct800D70D8 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

extern struct UnkStruct800D7098 D_800D7098;
extern struct UnkStruct800D70D8 D_800D70D8;


struct SubSub800E1B50_Unk88_UnkC_Unk0_Unk1C {
    u8 filler0[8];
    f32 unk8;
};

struct SubSub800E1B50_Unk88_UnkC_Unk0 {
    u8 filler0[0x10];
    f32 unk10;
    s32 unk14;
    s32 unk18;
    struct SubSub800E1B50_Unk88_UnkC_Unk0_Unk1C *unk1C;
};

struct SubSub800E1B50_Unk88_UnkC_Unk4 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    f32 unk10;
};

struct SubSub800E1B50_Unk88_UnkC {
    struct SubSub800E1B50_Unk88_UnkC_Unk0 *unk0;
    struct SubSub800E1B50_Unk88_UnkC_Unk4 *unk4;
};

struct Sub800E1B50_Unk88 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    struct SubSub800E1B50_Unk88_UnkC *unkC;
    u32 unk10;
};

struct Sub800E1B50_Unk94 {
    u32 pad[4];
    u32 unk10;
    u32 unk14;
    u32 unk18;
    // sound
    u32 unk1C;
};

struct Sub800E1B50 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    f32 unk10;
};

struct Sub800E1B50_34_4C {
    u32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

struct Sub800E1B50_Unk34 {
    u8 pad[0x4C];
    struct Sub800E1B50_34_4C *unk4C;
};
struct Sub800E1B50_Unk84 {
    u8 fill[0x50];
    u8 unk50;
};

struct UnkStruct800E1B50 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 pad[0x28];
    struct Sub800E1B50_Unk34 *unk34;
    u8 unk38;
    u8 unk39;
    u8 unk3A;
    u8 unk3B;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u32 unk44;
    u32 unk48;
    u8 pad2 [0x14];
    u32 unk60;
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    u32 unk78;
    u32 unk7C;
    struct Sub800E1B50 *unk80;
    struct Sub800E1B50_Unk84 *unk84;
    struct Sub800E1B50_Unk88 *unk88;
    s32 *unk8C;
    u32 unk90;
    struct Sub800E1B50_Unk94 *unk94;
    s32 *unk98;
};

extern struct UnkStruct800E1B50 *D_800E1B50[];






static u32 D_801E2B94_ovl12;
static u32 D_801E2B98_ovl12;
static u32 D_801E2B9C_ovl12;
static u32 D_801E2BA0_ovl12;
static u32 D_801E2BA4_ovl12;
static u32 D_801E2BA8_ovl12;
static u32 D_801E2BAC_ovl12;
static u32 D_801E2BB0_ovl12;
static u32 D_801E2BB4_ovl12;
static u32 D_801E2BB8_ovl12;
static u32 D_801E2BBC_ovl12;
static u32 D_801E2BC0_ovl12;
static u32 D_801E2BC4_ovl12;
static u32 D_801E2BC8_ovl12;
static u32 D_801E2BCC_ovl12;
static u32 D_801E2BD0_ovl12;
static u32 D_801E2BD4_ovl12;
static u32 D_801E2BD8_ovl12;
static u32 *D_801E2BDC_ovl12[9];
static u32 *D_801E2C00_ovl12[9];
static u32 D_801E2C24_ovl12;
static u32 D_801E2C28_ovl12;
static u32 D_801E2C2C_ovl12;
static u32 D_801E2C30_ovl12;
static u32 D_801E2C34_ovl12;
static u32 D_801E2C38_ovl12;
static u32 D_801E2C3C_ovl12;
static u32 D_801E2C40_ovl12;
static u32 D_801E2C44_ovl12;
static u32 D_801E2C48_ovl12;
static u32 D_801E2C4C_ovl12;
static u32 D_801E2C50_ovl12;
static u32 *D_801E2C54_ovl12[9];
static u32 *D_801E2C78_ovl12[9];
static u32 D_801E2E24_ovl12;

static u32 D_801E2E20_ovl12;






// Forward declared
void func_801DB294_ovl12(struct GObj *);
void func_801DB2DC_ovl12(struct GObj *);
void func_801DB3F8_ovl12(GObj *);
void func_801DB494_ovl12(struct GObj *);
void func_801DB4D0_ovl12(struct GObj *);
void func_801DB544_ovl12(struct GObj *);
void func_801DB66C_ovl12(struct GObj *);
void func_801DB6D8_ovl12(struct GObj *);
void func_801DB910_ovl12(struct GObj *);
void func_801DBA88_ovl12(struct GObj *);
void func_801DBC2C_ovl12(struct GObj *);
void func_801DC4A8_ovl12(struct GObj *);
void func_801DC5F4_ovl12(struct GObj *);
void func_801DC750_ovl12(struct GObj *);
void func_801DC804_ovl12(struct GObj *);
void func_801DCFE4_ovl12(struct GObj *);
void func_801DD02C_ovl12(struct GObj *);
void func_801DD110_ovl12(GObj *);
void func_801DD158_ovl12(struct GObj *);
void func_801DD1C8_ovl12(struct GObj *);
void func_801DD290_ovl12(struct GObj *);
void func_801DD33C_ovl12(struct GObj *);
void func_801DD3A8_ovl12(struct GObj *);
void func_801DD400_ovl12(struct GObj *);
void func_801DD508_ovl12(struct GObj *);
void func_801DD56C_ovl12(struct GObj *);
void func_801DD5E4_ovl12(struct GObj *);
void func_801DD63C_ovl12(struct GObj *);
void func_801DD6BC_ovl12(struct GObj *);
void func_801DD74C_ovl12(struct GObj *);
void func_801DD7CC_ovl12(struct GObj *);
void func_801DD8FC_ovl12(struct GObj *);
void func_801DD924_ovl12(struct GObj *);
void func_801DD96C_ovl12(struct GObj *);
void func_801DDA30_ovl12(GObj *);
void func_801DDA78_ovl12(struct GObj *);
void func_801DDAE8_ovl12(struct GObj *);
void func_801DDBC4_ovl12(struct GObj *);
void func_801DDC70_ovl12(struct GObj *);
void func_801DDCDC_ovl12(struct GObj *);
void func_801DDDA8_ovl12(struct GObj *);
void func_801DDF38_ovl12(struct GObj *);
void func_801DE0E4_ovl12(struct GObj *);
void func_801DE16C_ovl12(struct GObj *);
void func_801DE1FC_ovl12(struct GObj *);
void func_801DE27C_ovl12(struct GObj *);
void func_801DE3AC_ovl12(struct GObj *);
void func_801DE3D4_ovl12(struct GObj *);
void func_801DE41C_ovl12(struct GObj *);
void func_801DE4E0_ovl12(GObj *);
void func_801DE528_ovl12(struct GObj *);
void func_801DE598_ovl12(struct GObj *);
void func_801DE678_ovl12(struct GObj *);
void func_801DE724_ovl12(struct GObj *);
void func_801DE790_ovl12(struct GObj *);
void func_801DE7E8_ovl12(struct GObj *);
void func_801DE8A8_ovl12(struct GObj *);
void func_801DE944_ovl12(struct GObj *);
void func_801DE9C4_ovl12(struct GObj *);
void func_801DEAF4_ovl12(struct GObj *);
void func_801DFFA8_ovl12(struct GObj *);
void func_801DFFF0_ovl12(struct GObj *);
void func_801E00D8_ovl12(GObj *);
void func_801E016C_ovl12(struct GObj *);
void func_801E0298_ovl12(struct GObj *);
void func_801E03B0_ovl12(struct GObj *);
void func_801E05E8_ovl12(struct GObj *);
void func_801E0714_ovl12(struct GObj *);
void func_801E0824_ovl12(struct GObj *);
void func_801E0938_ovl12(struct GObj *);
void func_801E0A70_ovl12(struct GObj *);
void func_801E0B58_ovl12(struct GObj *);
void func_801E0C54_ovl12(struct GObj *);
void func_801E0D24_ovl12(struct GObj *);
void func_801E0D64_ovl12(struct GObj *);
void func_801E0DF8_ovl12(struct GObj *);
void func_801E0FC8_ovl12(struct GObj *);
void func_801E10C4_ovl12(struct GObj *);
void func_801E1124_ovl12(struct GObj *);
void func_801E11CC_ovl12(struct GObj *);
void func_801E123C_ovl12(struct GObj *);
void func_801E12D0_ovl12(struct GObj *);
void func_801E1500_ovl12(struct GObj *);
void func_801E1804_ovl12(GObj *);
void func_801E1890_ovl12(struct GObj *);
void func_801E1A60_ovl12(struct GObj *);
void func_801E1B90_ovl12(struct GObj *);
void func_801E1CD4_ovl12(struct GObj *);
void func_801DC094_ovl12(void);
void func_801DC378_ovl12(void);
void func_801DC8CC_ovl12(void);
void func_801DECD4_ovl12(void);
void func_801E1528_ovl12(void);


// extern
extern void func_800A7F74(s32, s32, s32, f32, f32, f32);
extern void func_800F98EC(s32, f32);
extern void func_800FD570(s32, s32, f32, f32, f32);
extern void func_800BC11C(f32);
extern void func_800BC1FC(s32);
extern void func_800B113C(void);
extern void func_800A77E8(s32, u32 *, u16 *);
extern void func_800AECC0(f32);
extern void func_800AED20(f32);

extern f32 func_800FA1D4(struct Unk80129114_4_4 *, Vector *, s16);

extern void func_801D152C_ovl8(s32);
extern void func_801D184C_ovl8(s32);
extern void func_801D17F4_ovl8(s32);
void func_8011E31C(Vector *v);
extern s32 D_800D6B54;
extern f32 gKirbyHp;


struct KirbyState_114 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u16 unk10;
    u16 unk12;
};

struct KirbyState_184 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;

    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

// 0x8012E7C0
// TODO: populate with actual values
struct Player {
    u32 actionChange;           // 0x0
    u8 unk4;
    u8 action;                  // 0x5
    u8 previousAction;          // 0x6
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 abilityState;                // 0xC
    s8 unkD;
    u8 unkE;
    u8 unkF;
    u32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u32 floatTimer;             // 0x1C
    s32 turnDirection;          // 0x20
    u32 unk24;
    u32 unk28;
    s32 unk2C;
    u32 unk30;
    // u8 unk31;
    // u8 unk32;
    // u8 unk33;
    u32 isTurning;              // 0x34
    f32 unk38;
    s32 unk3C;
    f32 unk40;
    u32 unk44;
    u32 unk48;
    // struct pointer
    u32 unk4C;
    // struct pointer
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u16 unk5C;
    u16 unk5E;
    u32 unk60;
    u16 unk64;
    u16 unk66;
    u16 unk68;
    u16 unk6A;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    u32 unk84;
    u16 unk88;
    u16 unk8A;
    u32 unk8C;
    u32 ability;                    // 0x90
    u32 currentInhale;          // 0x94
    u32 firstInhale;                // 0x98
    u32 secondInhale;           // 0x9C
    u32 abilityInUse;           // 0xA0
    u32 unkA4;
    u32 inhaledEntityData;      // 0xA8 (First 4 bytes of Entity struct)
    u32 isHoldingEntity;        // 0xAC
    u8 isInhaling;              // 0xB0
    u8 isInhalingBlock;         // 0xB1
    s16 numberInhaling;         // 0xB2
    s16 numberInhaled;          // 0xB4
    u16 unkB6;
    u8 unkB8;
    u8 unkB9;
    u16 unkBA;
    f32 unkBC;
    f32 unkC0;
    f32 unkC4;
    f32 unkC8;
    f32 unkCC;
    u16 jumpHeight;             // 0xD0
    u16 isFullJump;             // 0xD2
    s16 damageType;             // 0xD4
    u16 damageFlashTimer;       // 0xD6
    u16 damagePaletteTimer; // 0xD8
    u16 damagePaletteIndex; // 0xDA
    u8 isTakingDamage;          // 0xDC
    u8 droppedAbility;          // 0xDD
    u16 abilityDropTimer;       // 0xDE
    u16 hpAfterDamage;          // 0xE0
    u16 unkE2;
    u32 ceilingCollisionNext;   // 0xE4
    u32 floorCollisionNext; // 0xE8
    u32 rightCollisionNext; // 0xEC
    u32 leftCollisionNext;      // 0xF0
    u32 levelCollisionFlags;    // 0xF4
    u32 verticalCollision;      // 0xF8
    u32 horizontalCollision;    // 0xFC
    u16 ceilingType;                // 0x100
    u16 floorType;              // 0x102
    u16 unk104;
    u16 unk106;
    u16 unk108;
    u16 unk10A;
    u32 unk10C;
    u32 unk110;
    // todo: verify this
    struct KirbyState_114 *unk114;
    u32 unk118;
    u32 unk11C;
    u32 unk120;
    u32 unk124;
    u32 unk128;
    u32 unk12C;
    u32 unk130;
    u32 unk134;
    u32 unk138;
    u32 unk13C;
    u32 unk140;

    f32 unk144;
    f32 unk148;
    f32 unk14C;

    u8 unk150;
    u8 unk151;
    u8 unk152;
    u8 unk153;
    u32 unk154;
    f32 unk158;
    u32 unk15C;

    u16 unk160;
    u16 unk162;
    f32 unk164;
    f32 unk168;
    u32 unk16C;
    u32 unk170;

    f32 forwardVel;
    Vec3f vel;                  // 0x178

    // ---
    // TODO: does Player actually end here???
    // ---


    // u32 unk184;
    // u32 unk188;
    // u32 unk18C;
    // u32 unk190;
    // u32 unk194;
    // u32 unk198;
    // u32 unk19C;
    // u32 unk1A0;
    // u32 unk1A4;
    struct KirbyState_184 _184;
    
    
    u32 unk1A8;                 //PositionState goes from here until the end
    u32 unk1AC;
    u32 unk1B0;
    u32 unk1B4;
    u32 unk1B8;
    u32 unk1BC;
    u32 unk1C0;
    u32 unk1C4;
    u32 unk1C8;

    f32 xPos;                       // 0x1CC
    f32 yPos;                       // 0x1D0
    f32 zPos;                       // 0x1D4

    u32 unk1D8;
    u32 unk1DC;
    u32 unk1E0;
    u32 unk1E4;
    u32 unk1E8;
    u32 unk1EC;
    u32 unk1F0;
    u32 unk1F4;
    u32 unk1F8;
    u32 unk1FC;
    u32 viTimer;                    // 0x200
};


extern struct Player gKirbyState;


void func_800B35F0(void);
void func_800B46F8(void);
void func_800B50C4(Vector*);
f32 func_800F8728(s32, f32, f32);
// ? func_800F8C70(GObj*);                             /* extern */
// ? func_800F8E6C(GObj*);                             /* extern */
// ? func_80112A40(s32, Vector*, f32*);                /* extern */

// ? func_8011DD5C(f32*, f32*);                        /* extern */
u8 func_8011E244(f32);

void func_8011D40C(void);








