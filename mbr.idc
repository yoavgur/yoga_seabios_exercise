//
// +-------------------------------------------------------------------------+
// |   This file has been generated by The Interactive Disassembler (IDA)    |
// |           Copyright (c) 2013 Hex-Rays, <support@hex-rays.com>           |
// |                           Evaluation version                            |
// +-------------------------------------------------------------------------+
//
//
//      This file should be used in the following way:
//         - reload executable into IDA with using switch -c
//         - use File, Load IDC file and load this file.
//
//      NOTE: This file doesn't contain all information from the database.
//

#define UNLOADED_FILE   1
#include <idc.idc>

static main(void)
{
  // set 'loading idc file' mode
  SetCharPrm(INF_GENFLAGS, INFFL_LOADIDC|GetCharPrm(INF_GENFLAGS));
  GenInfo();            // various settings
  Segments();           // segmentation
  Enums();              // enumerations
  Structures();         // structure types
  Patches();            // manual patches
  SegRegs();            // segment register values
  Bytes();              // individual bytes (code,data)
  Functions();          // function definitions
  // clear 'loading idc file' mode
  SetCharPrm(INF_GENFLAGS, ~INFFL_LOADIDC&GetCharPrm(INF_GENFLAGS));
}

//------------------------------------------------------------------------
// General information

static GenInfo(void) {

        DeleteAll();    // purge database
	SetPrcsr("metapc");
	SetCharPrm(INF_COMPILER, 0);
	StringStp(0xA);
	Tabs(1);
	Comments(1);
	Voids(0);
	XrefShow(2);
	AutoShow(1);
	Indent(16);
	CmtIndent(40);
	TailDepth(0x10);
}

//------------------------------------------------------------------------
// Information about segmentation

static Segments(void) {
	SetSelector(0X1,0);
	;
	SegCreate(0X600,0X800,0X1,0,1,2);
	SegRename(0X600,"seg000");
	SegClass (0X600,"CODE");
	SegDefReg(0x600,"es",0x0);
	SegDefReg(0x600,"ss",0x0);
	SegDefReg(0x600,"ds",0x0);
	SegDefReg(0x600,"fs",0x0);
	SegDefReg(0x600,"gs",0x0);
	SetSegmentType(0X600,2);
	LowVoids(0x20);
	HighVoids(0x200);
}

//------------------------------------------------------------------------
// Information about enum types

static Enums(void) {
        auto id;
        BeginTypeUpdating(UTP_ENUM);
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
        BeginTypeUpdating(UTP_STRUCT);
}

//------------------------------------------------------------------------
// Information about bytes

static Bytes_0(void) {
        auto x;
#define id x

	ExtLinA		(0X600,	0,	"; File Name   : /tmp/poop/mbr");
	ExtLinA		(0X600,	1,	"; Format      : Binary file");
	ExtLinA		(0X600,	2,	"; Base Address: 0000h Range: 0000h - 0200h Loaded length: 0200h");
	MakeCode	(0X600);
	MakeRptCmt	(0X602,	"store 0 in stack segment");
	MakeRptCmt	(0X604,	"stack pointer points to 7c00");
	MakeRptCmt	(0X607,	"extra segment equals 0");
	MakeRptCmt	(0X609,	"data segment equals 0");
	MakeRptCmt	(0X60B,	"source index equals 7c00");
	MakeRptCmt	(0X60E,	"dest index = 600");
	MakeRptCmt	(0X61B,	"pop instruction_pointer=0x61c segment=0");
	MakeCode	(0X61C);
	MakeComm	(0X623,	"read 16 bytes and call functions depending on if the bytes are none zero and if they're negative or not");
	MakeName	(0X623,	"check_partition_table_entries");
	MakeComm	(0X627,	"jump if active partition");
	MakeComm	(0X629,	"jmp if partition table entry invalid");
	MakeComm	(0X632,	"TRANSFER TO ROM BASIC\ncauses transfer to ROM-based BASIC (IBM-PC)\noften reboots a compatible; often has no effect at all");
	MakeCode	(x=0X632);
	OpHex		(x,	0);
	MakeName	(0X634,	"my_check_ext_drives_preamble");
	MakeComm	(0X638,	"5 read attempts");
	MakeName	(0X640,	"my_check_for_extension_drive_installation");
	MakeComm	(0X645,	"DISK - Check for INT 13h Extensions\nBX = 55AAh, DL = drive number\nReturn: CF set if not supported\nAH = extensions version\nBX = AA55h\nCX = Interface support bit map");
	MakeCode	(x=0X645);
	OpHex		(x,	0);
	MakeComm	(0X648,	"Jump if not supported");
	MakeCode	(x=0X650);
	OpHex		(x,	1);
	MakeComm	(0X654,	"jmp if extended disk access functions supported");
	MakeName	(0X659,	"do_extended_read_of_partition_to_7c00");
	MakeComm	(0X65F,	"jmp if extension drive check failed");
	MakeComm	(0X67E,	"DISK - IBM/MS Extension - EXTENDED READ (DL - drive, DS:SI - disk address packet)");
	MakeCode	(x=0X67E);
	OpHex		(x,	0);
	MakeCode	(x=0X681);
	OpHex		(x,	1);
	MakeComm	(0X687,	"read 1 partition");
	MakeCode	(0X687);
	MakeName	(0X687,	"my_read_sectors_to_7c00");
	MakeRptCmt	(0X68A,	"write read bytes to address es:7c00");
	MakeComm	(0X68D,	"drive number");
	MakeComm	(0X690,	"head number");
	MakeComm	(0X693,	"sector number (maybe equals 4?)");
	MakeComm	(0X696,	"low 8 bits of cylinder number (maybe 0?)");
	MakeComm	(0X699,	"DISK - READ SECTORS INTO MEMORY\nAL = number of sectors to read, CH = track, CL = sector\nDH = head, DL = drive, ES:BX -> buffer to fill\nReturn: CF set on error, AH = status, AL = number of sectors read");
	MakeCode	(x=0X699);
	OpHex		(x,	0);
	MakeName	(0X69B,	"my_post_read_func");
	MakeComm	(0X69D,	"Jump if interrupt was successful [Jump if Not Below (CF=0)]");
	MakeCode	(0X6B0);
	MakeName	(0X6B0,	"my_reset_disk_drives");
	MakeComm	(0X6B6,	"DISK - RESET DISK SYSTEM\nDL = drive (if bit 7 is set both hard disks and floppy disks reset)");
	MakeCode	(x=0X6B6);
	OpHex		(x,	0);
	MakeComm	(0X6BB,	"compare last 2 bytes of 512 byte sector to 55AA");
	MakeCode	(0X6BB);
	MakeName	(0X6BB,	"my_try_turning_on_A20_gate");
	MakeComm	(0X6CC,	"set bits: keyboard_data, keyboard clock, IRQ1 (keyboard not mouse), and don't reset");
	MakeComm	(0X6CE,	"8042 keyboard controller command register.\nWrite output port (next byte to port 60h):\n7:  1=keyboard data line pulled low (inhibited)\n6:  1=keyboard clock line pulled low (inhibited)\n5:  enables IRQ 12 interrupt on mouse IBF\n4:  enables IRQ 1 interrupt on keyboard IBF\n3:  1=mouse clock line pulled low (inhibited)\n2:  1=mouse data line pulled low (inhibited)\n1:  A20 gate on/off\n0:  reset the PC (THIS BIT SHOULD ALWAYS BE SET TO 1)");
	MakeCode	(x=0X6CE);
	OpHex		(x,	0);
	MakeComm	(0X6D3,	"Enable A20 address line!!!!");
	MakeComm	(0X6D5,	"8042 keyboard controller data register.");
	MakeCode	(x=0X6D5);
	OpHex		(x,	0);
	MakeComm	(0X6DC,	"8042 keyboard controller command register.\nPulse output port.\nBits 0-3 indicate ports to pulse.");
	MakeCode	(x=0X6DC);
	OpHex		(x,	0);
	MakeName	(0X6E2,	"my_check_TCG_BIOS");
	MakeComm	(0X6E5,	"Trusted Computing Group call - TCG_StatusCheck\nReturn: EAX = 0 if supported\nEBX = 41504354h ('TCPA')\nCH:CL = TCG BIOS Version\nEDX = BIOS TCG Feature Flags\nESI = Pointer to Event Log\n");
	MakeCode	(x=0X6E5);
	OpHex		(x,	0);
	MakeComm	(0X6EA,	"jump if TCG is not supported");
	MakeComm	(0X6EC,	"compare to TCPA maybe");
	MakeComm	(0X6F3,	"jump if ebx!=\"TCPA\"");
	MakeComm	(0X6F5,	"compare TCG bios version to 1.02");
	MakeComm	(0X6F9,	"jump if cx<102");
	MakeComm	(0X725,	"Trusted Computing Group call - TCG_StatusCheck\nReturn: EAX = 0 if supported\nEBX = 41504354h ('TCPA')\nCH:CL = TCG BIOS Version\nEDX = BIOS TCG Feature Flags\nESI = Pointer to Event Log\n");
	MakeCode	(x=0X725);
	OpHex		(x,	0);
	MakeName	(0X727,	"my_jump_to_7c00");
	MakeCode	(0X731);
	MakeName	(0X731,	"my_print_missing_OS");
	MakeCode	(0X736);
	MakeName	(0X736,	"my_print_error_loading_OS");
	MakeCode	(0X73B);
	MakeName	(0X73B,	"my_print_invalid_partition_table");
	MakeName	(0X73E,	"my_print_preamble");
	MakeName	(0X745,	"my_print_string");
	MakeComm	(0X74F,	"- VIDEO - WRITE CHARACTER AND ADVANCE CURSOR (TTY WRITE)\nAL = character, BH = display page (alpha modes)\nBL = foreground color (graphics modes)");
	MakeCode	(x=0X74F);
	OpHex		(x,	0);
	MakeCode	(0X753);
	MakeName	(0X753,	"my_HALT");
	MakeCode	(0X754);
	MakeCode	(0X756);
	MakeName	(0X756,	"my_wait_until_can_read_from_keyboard_controller");
	MakeComm	(0X758,	"8042 keyboard controller status register\n7:  PERR    1=parity error in data received from keyboard\n   +----------- AT Mode ----------+------------ PS/2 Mode ------------+\n6: |RxTO    receive (Rx) timeout  | TO      general timeout (Rx or Tx)|\n5: |TxTO    transmit (Tx) timeout | MOBF    mouse output buffer full  |\n   +------------------------------+-----------------------------------+\n4:  INH     0=keyboard communications inhibited\n3:  A2      0=60h was the port last written to, 1=64h was last\n2:  SYS     distinguishes reset types: 0=cold reboot, 1=warm reboot\n1:  IBF     1=input buffer full (keyboard can't accept data)\n0:  OBF     1=output buffer full (data from keyboard is available)");
	MakeCode	(x=0X758);
	OpHex		(x,	1);
	MakeCode	(x=0X75C);
	OpHex		(x,	1);
	MakeCode	(x=0X760);
	OpHex		(x,	1);
	MakeByte	(0X7B5);
	MakeName	(0X7B5,	"my_invalid_partition_table");
	MakeByte	(0X7B6);
	MakeName	(0X7B6,	"my_error_loading_OS");
	MakeByte	(0X7B7);
	MakeName	(0X7B7,	"my_missing_OS");
	MakeWord	(0X7FE);
}

static Functions_0(void) {

	MakeFunction    (0X756,0X763);
	SetFunctionFlags(0X756,0x4400);
}

//------------------------------------------------------------------------
// Information about functions

static Functions(void) {

	Functions_0();
}

//------------------------------------------------------------------------
// Information about segment registers

static SegRegs(void) {
	SetRegEx(0X600,"es",0,3);
	SetRegEx(0X600,"ss",0,3);
	SetRegEx(0X600,"ds",0,3);
	SetRegEx(0X600,"fs",0,3);
	SetRegEx(0X600,"gs",0,3);
	SetRegEx(0X604,"ss",0,3);
	SetRegEx(0X609,"es",0,3);
	SetRegEx(0X60B,"ds",0,3);
	SetRegEx(0X725,"es",0,3);
}

//------------------------------------------------------------------------
// Information about all patched bytes:

static Patches(void) {
}

//------------------------------------------------------------------------
// Call all byte feature functions:

static Bytes(void) {
	Bytes_0();
        EndTypeUpdating(UTP_STRUCT);
}

// End of file.
