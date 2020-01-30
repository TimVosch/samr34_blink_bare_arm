/*
  Linker script for SamL21J18B

  Address ranges:
    Flash:            0x00000000 - 0x003FFFFF
    Reserved:         0x00400000 - 0x1FFFFFFF
    SRAM (internal):  0x20000000 - 0x20007FFF
    SRAM (low-power): 0x30000000 - 0x30002000
*/
SECTIONS 
{
  . = 0x00000000;
  .text :
  {
    *(vectors)   /* Vector table start at 0x0000 0000 */
    *(.text)      /* Code */
  }
  .rodata :
  {
    *(.rodata)    /* Read Only data, comes after code (.text) */
  }
  _DATA_ROM_START = .;    /* Symbol(variable) for ROM start*/

  /* Move to SRAM */
  . = 0x20000000;
  _DATA_RAM_START =.;    /* Symbol(variable) for RAM start*/
  .data : AT(_DATA_ROM_START)
  {
    *(.data)      /* Data memory */
  }
  _DATA_RAM_END = .;

  _BSS_START = .;
  .bss :
  {
    *(.bss)       /* Zero-filled run time allocate data memory */
  }
  _BSS_END = .;
}